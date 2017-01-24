CC = g++

CFLAGS = -ggdb `pkg-config --cflags --libs opencv`

default:
	$(CC) $(CFLAGS) main.cpp
