# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++23 -I"C:/raylib64/include"

# Linker flags
LDFLAGS = -L"C:/raylib64/lib" -lraylib -lopengl32 -lgdi32 -lwinmm

# Executable name
TARGET = main.exe

# Source files
SRCS = src/main.cpp

# Default to debug mode
DEBUG = true

ifeq ($(DEBUG), true)
	CFLAGS += -g -DDEBUG
else
	CFLAGS += -O2
endif

# Default target (build)
all: $(TARGET)

# Build rule
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	del $(TARGET)