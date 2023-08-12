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

#include "shell/CommandsManager.hpp"

using namespace shell;

void CommandsManager::registerCommand(Command *command) {
    m_commands.insert(std::make_pair(command->getName(), command));
}

Command *CommandsManager::findCommand(const std::string &name) {
    if(m_commands.find(name) == m_commands.end()) {
        return nullptr;
    }

    return m_commands[name];
}

CommandsManager::Iterator CommandsManager::begin() {
    return Iterator(m_commands.begin());
}

CommandsManager::Iterator CommandsManager::end() {
    return Iterator(m_commands.end());
}

CommandsManager::Iterator::reference CommandsManager::Iterator::operator*() const {
    return m_current->second;
}

CommandsManager::Iterator::pointer CommandsManager::Iterator::operator->() {
    return &m_current->second;
}

CommandsManager::Iterator &CommandsManager::Iterator::operator++() {
    ++m_current;
    return *this;
}

bool shell::operator!=(const CommandsManager::Iterator &a, const CommandsManager::Iterator &b) {
    return (a.m_current != b.m_current);
}

CommandsManager::~CommandsManager() {
    for(auto &command : *this) {
        delete command;
    }
}

void CommandsManager::clear() {
    m_commands.clear();
}