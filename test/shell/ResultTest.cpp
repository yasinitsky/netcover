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

#include "shell/Result.hpp"

class ResultTest : public testing::Test {
    protected:
        const std::string m_provider{"RESULT_TEST"};
        shell::Result m_result{m_provider};
};

TEST_F(ResultTest, shouldIsOkReturnTrueIfErrorIsNotSet) {
    ASSERT_TRUE(m_result.isOk());
}

TEST_F(ResultTest, shouldIsOkReturnFalseIfErrorIsSet) {
    m_result.setError("description");

    ASSERT_FALSE(m_result.isOk());
}

TEST_F(ResultTest, shouldPrintErrorTextToOutputStream) {
    const std::string error = "sample error";
    const std::string expectedOutput = m_provider + ": " + error + '\n';
    std::ostringstream ss;

    m_result.setError(error);
    ss << m_result;

    ASSERT_EQ(ss.str(), expectedOutput);
}