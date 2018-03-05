TARGET = main
CFLAGS = -std=c++14
CC = g++

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o ./$(TARGET) ./$(TARGET).cpp
