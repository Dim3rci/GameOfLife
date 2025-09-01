# Compiler and flags
CXX := g++
# CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2 -Iinclude
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Linker flags for console application
LDFLAGS := -static-libgcc -static-libstdc++

# Project name
TARGET := game_of_life

# Directories
SRCDIR := src
OBJDIR := obj
INCDIR := include

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Create executable - add -mwindows flag for console app
$(TARGET): $(OBJECTS)
	@echo "Linking $@..."
# 	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Build completed successfully!"

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean build files
clean:
	@echo "Cleaning..."
	@rm -rf $(OBJDIR) $(TARGET)
	@echo "Clean completed!"

# Run the program
run: clean $(TARGET)
	@./$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: clean $(TARGET)

# Release build (with optimizations)
release: CXXFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)

# Show help
help:
	@echo "Task Manager Makefile"
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  clean   - Remove build files"
	@echo "  run     - Build and run the program"
	@echo "  debug   - Build with debug symbols"
	@echo "  release - Build with optimizations"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all clean run debug release help

# Prevent make from deleting intermediate files
.SECONDARY: