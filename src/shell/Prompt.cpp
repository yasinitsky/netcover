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

#include <regex>

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
    Result result = parseInput(input, commandName, arguments);    
    if(commandName.length() == 0 || !result.isOk()) {
        return result;
    }

    Command *command = m_cm.findCommand(commandName);
    if(!command) {
        result.setError("command not found");
        return result;
    }

    return command->execute(arguments);
}

Result Prompt::parseInput(const std::string &input, std::string &command, Command::Arguments &arguments) const {
    std::size_t pos = getNextToken(input, command);
    Result result{command};
    
    while(pos < input.length()) {
        std::string token;
        pos = getNextToken(input, token, pos);
        if(pos == std::string::npos) {
            result.setError("missing closing quote");
            return result;
        }

        arguments.push_back(token);
    }

    return result;
}

std::size_t Prompt::getNextToken(const std::string &input, std::string &token, std::size_t pos) const {
    // skip whitespaces before token
    while(pos < input.length()) {
        if(!isSpace(input[pos])) break;
        pos++;
    }

    char curr = input[pos];
    if(curr == '"') { // quoted token
        char prev = '"';
        pos++;
        while(pos < input.length()) {
            curr = input[pos++];
            if(curr == '"') {
                if(prev != '\\') return pos;

                token.pop_back();
            }

            token += curr;
            prev = curr;
        }
        
        return std::string::npos;
    } else { // regular token
        while(pos < input.length()) {
            curr = input[pos];
            if(isSpace(curr) || curr == '"') return pos;

            pos++;
            token += curr;
        }
    }

    return pos;
}

bool Prompt::isSpace(const char character) const {
    return std::isspace(static_cast<unsigned char>(character));
}