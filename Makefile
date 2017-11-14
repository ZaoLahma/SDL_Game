CCOMMAND = gcc
CFLAGS = -Wall -c -Wextra -g
LINKARGS = -lpthread
SOURCES = $(wildcard src/*.c)
RELEASE_SOURCES = $(wildcard src/release/*.c)
TEST_SOURCES = $(wildcard test/*.c)
OBJECTS = $(SOURCES:.c=.o)
RELEASE_OBJECTS = $(RELEASE_SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
INC_DIRS = -I./inc -I./config
TEST_EXE_NAME = test_game
RELEASE_EXE_NAME = game

$(TEST_EXE_NAME): $(OBJECTS) $(TEST_OBJECTS)
	$(CCOMMAND) $(OBJECTS) $(TEST_OBJECTS) $(LINKARGS) -o $(TEST_EXE_NAME)

$(RELEASE_EXE_NAME): $(OBJECTS) $(RELEASE_OBJECTS)
	$(CCOMMAND) $(OBJECTS) $(RELEASE_OBJECTS) $(LINKARGS) -o $(RELEASE_EXE_NAME)

%.o: %.c
	$(CCOMMAND) $(INC_DIRS) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TEST_EXE_NAME) $(RELEASE_EXE_NAME) $(OBJECTS) $(TEST_OBJECTS) $(RELEASE_OBJECTS)
