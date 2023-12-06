CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2

SRC_DIR = src
LIB_DIR = lib

# List the source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES = $(wildcard $(LIB_DIR)/*.cpp)

# Generate the object file names from source files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRC_FILES)) $(patsubst $(LIB_DIR)/%.cpp,%.o,$(LIB_FILES))

# The final executable name
EXECUTABLE = pokemon_league

# Default target
all: $(EXECUTABLE)

# Rule to build object files from source files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build the final executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up intermediate files and the executable
clean:
	rm -f *.o $(EXECUTABLE)

# Phony target to force make to always execute the clean target
.PHONY: clean
