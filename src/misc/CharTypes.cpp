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

#include "misc/CharTypes.hpp"

#include <cctype>

using namespace misc;

bool CharTypes::isSpace(const char character) {
    return std::isspace(static_cast<unsigned char>(character));
}

bool CharTypes::isLetter(const char character) {
    return std::isalpha(static_cast<unsigned char>(character));
}

bool CharTypes::isNumber(const char character) {
    return std::isdigit(static_cast<unsigned char>(character));
}

bool CharTypes::isAlphanumeric(const char character) {
    return (isLetter(character) || isNumber(character));
}