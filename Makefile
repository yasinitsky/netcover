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

# SYNOPSIS:
#	make build      - build netcover executable (result is build/netcover)
# 	make test       - build and run unittests
#	make cleanup    - clean build directory

# Tools
CXX     = g++
MKDIR   = mkdir
RM      = rm
FIND    = find
AR      = ar

# Options
CXXFLAGS    = -Wall -pedantic -std=c++17 -c

BUILD_ROOT  = build

.SUFFIXES:

# Build executable
SOURCE_ROOT     = src
SOURCE_FILES    = $(shell $(FIND) $(SOURCE_ROOT) -type f -name *.cpp)
SOURCE_OBJECTS  = $(foreach file,$(SOURCE_FILES),$(BUILD_ROOT)/$(basename $(file)).o)
SOURCE_MAIN     = $(BUILD_ROOT)/$(SOURCE_ROOT)/main.cpp
SOURCE_INCLUDE  = $(SOURCE_ROOT)
SOURCE_HEADERS  = $(shell $(FIND) $(SOURCE_INCLUDE) -type f -name *.hpp)
SOURCE_TARGET   = $(BUILD_ROOT)/netcover

.PHONY: build
build: $(SOURCE_TARGET)

$(SOURCE_TARGET): $(SOURCE_OBJECTS)
	$(CXX) $^ -o $@

$(BUILD_ROOT)/$(SOURCE_ROOT)/%.o: $(SOURCE_ROOT)/%.cpp $(SOURCE_HEADERS)
	@$(MKDIR) -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(foreach file,$(SOURCE_INCLUDE),-I$(file)) $< -o $@

# Build gtest
GTEST_ROOT      = 3rdparty/googletest
GTEST_SRC       = $(GTEST_ROOT)/src
GTEST_FILES     = $(GTEST_SRC)/gtest_main.cc $(GTEST_SRC)/gtest-all.cc
GTEST_OBJECTS   = $(foreach file,$(GTEST_FILES),$(BUILD_ROOT)/$(basename $(file)).o)
GTEST_INCLUDE   = $(GTEST_ROOT) $(GTEST_ROOT)/include
GTEST_LIB       = $(BUILD_ROOT)/$(GTEST_ROOT)/libgtest.a

$(GTEST_LIB): $(GTEST_OBJECTS)
	$(AR) rsc $@ $^

# Don't add gtest headers dependency, because we won't change it
$(BUILD_ROOT)/$(GTEST_ROOT)/%.o: $(GTEST_ROOT)/%.cc
	@$(MKDIR) -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(foreach file,$(GTEST_INCLUDE),-I$(file)) $^ -o $@

# Build and run unittests
TEST_ROOT       = test
TEST_FILES      = $(shell $(FIND) $(TEST_ROOT) -type f -name *.cpp)
TEST_OBJECTS    = $(foreach file,$(TEST_FILES),$(BUILD_ROOT)/$(basename $(file)).o) $(filter-out $(basename $(SOURCE_MAIN)).o,$(SOURCE_OBJECTS))
TEST_INCLUDE    = $(SOURCE_INCLUDE) $(GTEST_INCLUDE)
TEST_HEADERS    = $(SOURCE_HEADERS)
TEST_TARGET     = $(BUILD_ROOT)/$(TEST_ROOT)/test.out

.PHONY: test
test: $(TEST_TARGET)
	@./$(TEST_TARGET)

$(TEST_TARGET): $(GTEST_LIB) $(TEST_OBJECTS)
	$(CXX) $(TEST_OBJECTS) -o $@ -L$(dir $(GTEST_LIB)) -lgtest

$(BUILD_ROOT)/$(TEST_ROOT)/%.o: $(TEST_ROOT)/%.cpp $(TEST_HEADERS)
	@$(MKDIR) -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(foreach file,$(TEST_INCLUDE),-I$(file)) $< -o $@

# Cleanup
.PHONY: cleanup
cleanup:
	$(RM) -rf $(BUILD_ROOT)