# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -O2 -MMD -MP -I lib -g

# Directories
SRC_DIR := days
TEST_DIR := tests
BIN_DIR := bin
OBJ_DIR := obj
LIB_DIR := lib

# List of all test sources (e.g. tests/day01_test.cpp)
TEST_SOURCES := $(wildcard $(TEST_DIR)/*_test.cpp)

# Extract test names without extension (e.g. day01)
TEST_NAMES := $(basename $(notdir $(TEST_SOURCES:%_test.cpp=%)))

# Binaries to build (e.g. bin/day01_test)
BINARIES := $(addprefix $(BIN_DIR)/,$(addsuffix _test,$(TEST_NAMES)))

# Default target
all: $(BINARIES)

# Build each test binary from test + solution object
$(BIN_DIR)/%_test: $(OBJ_DIR)/%_test.o $(OBJ_DIR)/%.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile test .cpp to .o
$(OBJ_DIR)/%_test.o: $(TEST_DIR)/%_test.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile solution.cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%/solution.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include generated dependency files if they exist
-include $(wildcard $(OBJ_DIR)/*.d)

# Run tests. Usage: make test [day=01]
ifdef day
PADDED_DAY := $(shell printf "%02d" $(day))
test: $(BIN_DIR)/day$(PADDED_DAY)_test
	@echo "Running $<..."
	@./$<
else
test: $(BINARIES)
	@for bin in $(BINARIES); do \
		echo "Running $$bin..."; \
		./$$bin; \
	done
endif

# Create a new day using C++ script
newday: $(BIN_DIR)/newday
	@./$(BIN_DIR)/newday

# Build the newday binary
$(BIN_DIR)/newday: $(LIB_DIR)/newday.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean everything
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all test clean newday
