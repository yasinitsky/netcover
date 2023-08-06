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

#include "gtest/gtest.h"

#include "shell/CommandsManager.hpp"
#include "CommandMock.hpp"

using testing::ElementsAre;

class CommandsManagerTest : public testing::Test {
    protected:
        shell::CommandsManager &m_cm = shell::CommandsManager::getInstance();
        CommandMock *m_testCommand = nullptr;

        void SetUp() {
            m_testCommand = new CommandMock();
            m_cm.registerCommand(m_testCommand);
        }

        void TearDown() {
            delete m_testCommand;
            m_testCommand = nullptr;
        }
};

TEST_F(CommandsManagerTest, shouldFindCommand) {
    ASSERT_EQ(m_cm.findCommand(CommandMock::COMMAND_NAME), m_testCommand);
}

TEST_F(CommandsManagerTest, shouldFindCommandFailWhenCommandDoesNotExist) {
    ASSERT_EQ(m_cm.findCommand("invalid_command"), nullptr);
}

TEST_F(CommandsManagerTest, shouldIterateOverCommands) {
    std::vector<shell::Command *> commands;

    for(auto &command : m_cm) {
        commands.push_back(command);
    }

    ASSERT_THAT(commands, ElementsAre(m_testCommand));
}