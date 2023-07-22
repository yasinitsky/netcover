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