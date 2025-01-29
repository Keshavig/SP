CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -O2
CXXFLAGS_DEBUG = -Wall -Wextra -Werror -ggdb -Og

SRC_DIR = source
EXECUTABLE_DIR = bin
OBJS_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJS_DIR)/%.o)

TARGET = replacer

all: release

debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(EXECUTABLE_DIR)/$(TARGET)

release: $(EXECUTABLE_DIR)/$(TARGET)

# Linking the object files to create the executable
$(EXECUTABLE_DIR)/$(TARGET): $(OBJS) $(EXECUTABLE_DIR) $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule for compiling source files into object files
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Directories for executable and object files
$(EXECUTABLE_DIR): 
	mkdir -p $(EXECUTABLE_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Clean up generated files
clean:
	rm -rf $(OBJS_DIR) $(EXECUTABLE_DIR)
