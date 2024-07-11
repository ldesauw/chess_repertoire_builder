# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Iinclude/object -Iinclude/utils -Wall -Wextra

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

# Executable name
EXEC = chess_repertoire_builder

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile source files to object files
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it does not exist
build:
	mkdir -p build

# Clean up build files
clean:
	rm -rf build $(EXEC)

.PHONY: all clean
