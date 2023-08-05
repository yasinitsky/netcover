/**
 * Copyright (C) 2023 Yaroslav Yasynytskyi.
 * This file is part of Netcover.

 * Netcover is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option) any later
 * version.

 * Netcover is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "shell/Prompt.hpp"

using namespace shell;

const std::string Prompt::DEFAULT_PROMPT = std::string{"netcover> "};
const std::string Prompt::SHELL_RESULT_PROVIDER = std::string{"shell"};

void Prompt::setInputStream(std::istream *stream) {
    this->m_inputStream = stream;
}

void Prompt::setOutputStream(std::ostream *stream) {
    this->m_outputStream = stream;
}

const Result Prompt::ask() const {
    *m_outputStream << DEFAULT_PROMPT;

    std::string input;
    std::getline(*m_inputStream, input);

    std::string commandName;
    Command::Arguments arguments;
    parseInput(input, commandName, arguments);
    
    Result result{commandName};
    if(commandName.length() == 0) {
        return result;
    }

    Command *command = m_cm.findCommand(commandName);
    if(!command) {
        result.setError("command not found");
        return result;
    }

    return command->execute(arguments);
}

void Prompt::parseInput(const std::string &input, std::string &command, Command::Arguments &arguments) const {
    std::size_t pos = getNextWord(input, command);
    
    while(true) {
        std::string word;
        pos = getNextWord(input, word, pos);

        if(word.size() == 0) break;

        arguments.push_back(word);
    }
}

std::size_t Prompt::getNextWord(const std::string &input, std::string &word, std::size_t pos) const {
    while(pos < input.size()) {
        if(!isSpace(input[pos])) break;
        pos++;
    }

    while(pos < input.size()) {
        if(isSpace(input[pos])) break;

        word += input[pos++];
    }

    return pos;
}

bool Prompt::isSpace(const char character) const {
    return std::isspace(static_cast<unsigned char>(character));
}