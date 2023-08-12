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

#ifndef SHELL_PROMPT_HPP
#define SHELL_PROMPT_HPP

#include "misc/Singleton.hpp"
#include "shell/Result.hpp"
#include "shell/Command.hpp"
#include "shell/CommandsManager.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace shell {

class Prompt : public misc::Singleton<Prompt> {
    private:
        static const std::string DEFAULT_PROMPT;
        static const std::string SHELL_RESULT_PROVIDER;

        std::istream *m_inputStream;
        std::ostream *m_outputStream;
        CommandsManager &m_cm;

        Result parseInput(const std::string &input, std::string &command, Command::Arguments &arguments) const;
        std::size_t getNextToken(const std::string &input, std::string &token, std::size_t pos = 0) const;
        bool isSpace(const char character) const;
    public:
        Prompt() : m_cm(CommandsManager::getInstance()) {}
        void setInputStream(std::istream *stream);
        void setOutputStream(std::ostream *stream);
        const Result ask() const;
};

} // namespace shell

#endif // SHELL_PROMPT_HPP