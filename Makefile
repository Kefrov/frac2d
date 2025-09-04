# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET := $(BUILD_DIR)/frac2d

# Default target
default: run

# Build and run the executable
run: $(TARGET)
	./$(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build files
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(TARGET)

.PHONY: default run clean
