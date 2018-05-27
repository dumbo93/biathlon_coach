# the compiler
CC = gcc

# the compiler flag 
CFLAGS = -g -Wall

# linker flag
LDFLAGS = -g -pthread

# executable file
TARGET = main

# objects files
OBJECTS = main.o wifi_server.o save_data.o computer_state.o

# sourse files
SOURCES = main.c wifi_server.c save_data.c computer_state.c

# link programs, taget: executable
$(TARGET):$(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

# compile programs, taget: object files
$(OBJECTS):$(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

#cleaning
clean: 
	rm -f $(TARGET) $(OBJECTS)