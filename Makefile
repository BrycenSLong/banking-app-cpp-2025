# Choose compiler
CXX = g++

# Compiler flags
CFLAGS = -Wall -std=c++11 -g

# Define final executable
TARGET = bankingApp

# Object files
OBJS = main.o bankAccount.o

# Build target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files to object files
main.o: main.cpp bankAccount.h
	$(CXX) $(CFLAGS) -c main.cpp
bankAccount.o: bankAccount.cpp bankAccount.h
	$(CXX) $(CFLAGS) -c bankAccount.cpp

# Clean Build rules
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
# Target for compiling and running the program in one step
.PHONY: run
run: $(TARGET)
	./$(TARGET)