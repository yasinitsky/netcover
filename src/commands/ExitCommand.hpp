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

#ifndef COMMANDS_HELP_COMMAND_HPP
#define COMMANDS_HELP_COMMAND_HPP

#include "shell/Command.hpp"

namespace commands {

class ExitCommand : public shell::Command {
    public:
        ExitCommand() : Command("exit", "exit from the netcover shell") { }
        shell::Result execute(Arguments &arguments) const override;
};

} // namespace commands

#endif // COMMANDS_HELP_COMMAND_HPP