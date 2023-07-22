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
CXX = g++
MKDIR = mkdir
RM = rm

# Configuration
CXX_FLAGS = -Wall -pedantic

INCLUDE_DIR = $(SOURCE_DIR)

SOURCE_DIR = src
SOURCE_FILES = main.cpp

BUILD_DIR = build
OBJECT_DIRS = $(foreach file,$(SOURCE_FILES),$(BUILD_DIR)/$(dir $(file)))
OBJECT_FILES = $(foreach file,$(SOURCE_FILES),$(BUILD_DIR)/$(basename $(file)).o)

TARGET = netcover

# Recipes
.PHONY: build
build: create-dirs compile-objects link-objects

.PHONY: compile-objects
compile-objects: $(OBJECT_FILES)

.PHONY: create-dirs
create-dirs:
	$(MKDIR) -p $(OBJECT_DIRS)

.PHONY: link-objects
link-objects: $(OBJECT_FILES)
	$(CXX) $^ -o $(BUILD_DIR)/netcover

.PHONY: cleanup
cleanup:
	$(RM) -rf $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) -c -I$(INCLUDE_DIR) $< -o $@