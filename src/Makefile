CC = g++
CFLAGS = -Wall -pedantic

DIRNAME = $(shell basename $(CURDIR))

rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)$(filter $(subst *,%,$2),$d))

INCLUDE_PATH = ./includes

STATIC_LIBS = 
SOURCE_FILES = $(call rwildcard,*,*.cpp)
HEADERS = $(call rwildcard,$(INCLUDE_PATH),*.h)
TEMPLATES = $(call rwildcard,*,*.tpp)

TARGET = netcover.out
DEPENDS = $(STATIC_LIBS) $(SOURCE_FILES) $(ENTRYPOINT) $(HEADERS) $(TEMPLATES)

all: $(TARGET)

$(TARGET): $(DEPENDS)
	$(CC) $(CFLAGS) -I $(INCLUDE_PATH) $(SOURCE_FILES) -o $@

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
