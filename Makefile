# define compiler
CC       = gcc
# define compiler flags
CFLAGS   = -Wall -g
# define the object files that this project needs
OBJFILES = linked_lists.o main.o
# define the executable file's name
MAIN     = main

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFIAGS) -o $(MAIN) $(OBJFILES)
	
%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<
