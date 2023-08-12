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

#include "shell/Prompt.hpp"
#include "CommandMock.hpp"

using testing::Return;
using testing::ElementsAre;

class PromptTest : public testing::Test {
    protected:
        shell::Prompt &m_prompt = shell::Prompt::getInstance();
        CommandMock *m_command;
        std::istringstream m_istream;
        std::ostringstream m_ostream;
        shell::CommandsManager &m_cm = shell::CommandsManager::getInstance();

        void SetUp() {
            m_command = new CommandMock();

            m_prompt.setInputStream(&m_istream);
            m_prompt.setOutputStream(&m_ostream);
            m_cm.registerCommand(m_command);
        }

        void TearDown() {
            delete m_command;
            m_command = nullptr;
            m_cm.clear();
        }
};

TEST_F(PromptTest, shouldAskReturnErrorWhenTryingToExecuteNonExistingCommand) {
    m_istream.str("invalid_command");
    m_istream.clear();

    shell::Result result = m_prompt.ask();

    ASSERT_FALSE(result.isOk());
}

TEST_F(PromptTest, shouldAskExecuteCommandWithArguments) {
    m_istream.str(CommandMock::COMMAND_NAME + " arg1 arg2 arg3");
    m_istream.clear();

    EXPECT_CALL(*m_command, execute(ElementsAre("arg1", "arg2", "arg3")))
            .WillOnce(Return(shell::Result{CommandMock::COMMAND_NAME}));

    ASSERT_TRUE(m_prompt.ask().isOk());
}

TEST_F(PromptTest, shouldAskExecuteCommandWithQuotedArgumentsWithoutSpaces) {
    m_istream.str(CommandMock::COMMAND_NAME + " arg1\"quoted 1\\\"\"\"quoted 2\"");
    m_istream.clear();

    EXPECT_CALL(*m_command, execute(ElementsAre("arg1", "quoted 1\"", "quoted 2")))
            .WillOnce(Return(shell::Result{CommandMock::COMMAND_NAME}));

    ASSERT_TRUE(m_prompt.ask().isOk());
}

TEST_F(PromptTest, shouldAskExecuteCommandWithQuotedArgumentsWithSpaces) {
    m_istream.str(CommandMock::COMMAND_NAME + " arg1    \"quoted 1\\\"\"   \"quoted 2\"");
    m_istream.clear();

    EXPECT_CALL(*m_command, execute(ElementsAre("arg1", "quoted 1\"", "quoted 2")))
            .WillOnce(Return(shell::Result{CommandMock::COMMAND_NAME}));

    ASSERT_TRUE(m_prompt.ask().isOk());
}

TEST_F(PromptTest, shouldAskReturnErrorWhenTryingToPassIncompleteArguments) {
    m_istream.str(CommandMock::COMMAND_NAME + " arg1    \"quoted 1\\\"\"   \"quoted 2");
    m_istream.clear();

    ASSERT_FALSE(m_prompt.ask().isOk());
}