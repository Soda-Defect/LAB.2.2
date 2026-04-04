CC = g++
CFLAGS = -Wall -Wextra -std=c++14 
TARGET = programm
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

start: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

