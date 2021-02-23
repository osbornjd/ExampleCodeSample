# Simple makefile which compiles sources into libraries
# and then links libraries into a target file.
# To add more classes one just needs to add the *.o file into $(LIB_OBJS)
#

# Set basic compiler variables
INC_DIR = src
CPPFLAGS  = -g -Wall -std=c++11 -I $(INC_DIR)
ARFLAGS = -rv
CC = g++
SRC_DIR = src

# Set object files to create
LIB_OBJS = $(SRC_DIR)/Event.o $(SRC_DIR)/Particle.o $(SRC_DIR)/Event_Parser.o $(SRC_DIR)/Kaon.o $(SRC_DIR)/Pion.o

# Set target object file
OBJS = $(SRC_DIR)/event_analyzer.o

# Set target executable
TARGET = event_analyzer

# Main make
$(TARGET): $(LIB_OBJS) $(OBJS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(LIB_OBJS) src/event_analyzer.o

all:  $(LIB_OBJS) $(TARGET)


# Make tests
# Test target and directory
TEST_TARGET = test
TEST_DIR = tests

$(TEST_TARGET): $(LIB_OBJS) $(TEST_DIR)/test.o
	$(CC) $(CPPFLAGS) -o $(TEST_TARGET) -I ../src $(LIB_OBJS) $(TEST_DIR)/test.o

test: $(LIB_OBJS) $(TEST_TARGET)

clean:
	rm -f $(TARGET) $(LIB_OBJS) $(TEST_TARGET) $(TEST_DIR)/test.o $(SRC_DIR)/event_analyzer.o
