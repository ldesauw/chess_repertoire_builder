# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Iinclude/object -Iinclude/utils -Wall -Wextra

# Find all .cpp files in src/ and its subdirectories
SRCS = $(shell find src -name "*.cpp")

# Generate object files in build/ with the same directory structure as in src/
OBJS = $(patsubst src/%, build/%, $(SRCS:.cpp=.o))

# Executable name
EXEC = chessrepbuilder

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
