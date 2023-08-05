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

#include "shell/Command.hpp"
#include "CommandMock.hpp"

class CommandTest : public testing::Test {
    protected:
        const CommandMock m_command;
};

TEST_F(CommandTest, shouldGetCommandName) {
    ASSERT_EQ(m_command.getName(), CommandMock::COMMAND_NAME);
}

TEST_F(CommandTest, shouldGetCommandDescription) {
    ASSERT_EQ(m_command.getDescription(), CommandMock::COMMAND_DESCRIPTION);
}