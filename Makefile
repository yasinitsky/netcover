# Copyright (C) 2023 Yaroslav Yasynytskyi.
# This file is part of Netcover.
#
# Netcover is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.
#
# Netcover is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <http://www.gnu.org/licenses/>.

# Tools
CXX 	= g++
MKDIR 	= mkdir
RM 		= rm
FIND	= find

# Build process
CXX_FLAGS 		= -Wall -pedantic -std=c++17 -c
BUILD_ROOT		= build
SOURCE_ROOT 	= src

SOURCE_FILES	= $(shell $(FIND) $(SOURCE_ROOT) -type f -name *.cpp)
SOURCE_OBJECTS	= $(foreach file,$(SOURCE_FILES),$(BUILD_ROOT)/$(basename $(file)).o)
SOURCE_INCLUDE	= $(SOURCE_ROOT)
SOURCE_HEADERS	= $(shell $(FIND) $(SOURCE_INCLUDE) -type f -name *.hpp)
SOURCE_TARGET	= $(BUILD_ROOT)/netcover

BUILD_TREE = $(SOURCE_DIRS)

.SUFFIXES:

.PHONY: build
build: $(SOURCE_TARGET)

$(SOURCE_TARGET): $(SOURCE_OBJECTS)
	$(CXX) $^ -o $(SOURCE_TARGET)

$(BUILD_ROOT)/$(SOURCE_ROOT)/%.o: $(SOURCE_ROOT)/%.cpp $(SOURCE_HEADERS)
	@$(MKDIR) -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(foreach file,$(SOURCE_INCLUDE),-I$(file)) $< -o $@

.PHONY: cleanup
cleanup:
	$(RM) -rf $(BUILD_ROOT)