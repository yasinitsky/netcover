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
#include "shell/CommandsManager.hpp"
#include "misc/RuntimeData.hpp"
#include "commands/ExitCommand.hpp"

#include <cstdlib>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    shell::Prompt &prompt = shell::Prompt::getInstance();
    prompt.setInputStream(&std::cin);
    prompt.setOutputStream(&std::cout);

    shell::CommandsManager &cm = shell::CommandsManager::getInstance();
    cm.registerCommand(new commands::ExitCommand{});

    misc::RuntimeData::runShell = true;
    while(misc::RuntimeData::runShell) {
        shell::Result result = prompt.ask();
        if(!result.isOk()) {
            std::cout << result;
        }
    }

    return EXIT_SUCCESS;
}