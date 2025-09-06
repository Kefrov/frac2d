# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# SDL2 flags
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET := $(BUILD_DIR)/frac2d

# Default target
default: run

# Build and run the executable
run: $(TARGET)
	@echo "Running Frac2D..."
	@./$(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(SDL_LDFLAGS) -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SDL_CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build files
clean:
	@echo "Cleaning up..."
	@rm -f $(BUILD_DIR)/*.o
	@rm -f $(TARGET)

.PHONY: default run clean
