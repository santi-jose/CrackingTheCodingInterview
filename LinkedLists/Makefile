# Compiler
CXX = g++

# Compiiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Output Executable
TARGET = test

# Source Files
SRCS = main.cpp LinkedList.cpp

# Object Files (Replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default Rule: Compile Everything
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean: 
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)