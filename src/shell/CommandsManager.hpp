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
#include <iterator>

namespace shell {

class CommandsManager : public misc::Singleton<CommandsManager> {
    private:
        using container = std::unordered_map<std::string, Command *>;
        container m_commands;
    public:
        struct Iterator {
            public:
                using iterator_category = std::input_iterator_tag;
                using value_type = Command *;
                using pointer = value_type *;
                using reference = value_type &;

                Iterator(container::iterator current) : m_current(current) { }
                reference operator*() const;
                pointer operator->();
                Iterator &operator++();
                friend bool operator!=(const Iterator &a, const Iterator &b);
            private:
                container::iterator m_current;
        };

        CommandsManager() = default;
        ~CommandsManager();

        void registerCommand(Command *command);
        Command *findCommand(const std::string &name);

        Iterator begin();
        Iterator end();

        void clear();
};

bool operator!=(const CommandsManager::Iterator &a, const CommandsManager::Iterator &b);

} // namespace shell

#endif // SHELL_COMMANDS_MANAGER_HPP