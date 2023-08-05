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

#ifndef SHELL_COMMANDS_MANAGER_HPP
#define SHELL_COMMANDS_MANAGER_HPP

#include "misc/Singleton.hpp"
#include "shell/Command.hpp"

#include <unordered_map>

namespace shell {

class CommandsManager : public misc::Singleton<CommandsManager> {
    public:
        CommandsManager() = default;

        void registerCommand(Command *command);
        Command *findCommand(const std::string &name);
        
    private:
        std::unordered_map<std::string, Command *> m_commands;
};

} // namespace shell

#endif // SHELL_COMMANDS_MANAGER_HPP