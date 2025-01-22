CXX = clang++
CXXFLAGS_INSTALL = -Wall -Wextra -Werror -O3
CXXFLAGS_DEBUG = -Wall -Wextra -Werror -ggdb

SRC_DIR = source
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

TARGET = sarchi
EXECUTABLE_DIR = bin

# Default build (optimized)
all: release

# Release build
release: $(EXECUTABLE_DIR)/$(TARGET)

# Debug build
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(EXECUTABLE_DIR)/$(TARGET)

# Linking step
$(EXECUTABLE_DIR)/$(TARGET): $(OBJS) | $(EXECUTABLE_DIR)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $@

# Compiling source files to object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the bin directory exists
$(EXECUTABLE_DIR):
	mkdir -p $(EXECUTABLE_DIR)

# Clean build files
clean:
	rm -rf $(EXECUTABLE_DIR) $(SRC_DIR)/*.o
