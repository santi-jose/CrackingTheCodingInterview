# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Output Executable
TARGET = test

# Source Files
SRCS = main.cpp LinkedList.cpp

# Object Files (Replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

#Dependency Files
DEPS = $(SRCS:.cpp=.o)

# Default Rule: Compile Everything
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o object files and generate dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include dependency files if they exist
-include $(DEPS)

# Clean up build files
clean: 
	rm -f $(OBJS) $(TARGET) $(DEPS)

# Run the program
run: $(TARGET)
	./$(TARGET)