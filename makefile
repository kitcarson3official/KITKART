CC 			= g++
CFLAGS		= -Wall -Wextra -pedantic
LDFLAGS    	= -lsfml-graphics -lsfml-window -lsfml-system
OUTPUT		= KITKART.bin

all: clean compile

clean:
	rm -f $(OUTPUT)

compile:
	$(CC) $(CFLAGS) SRC/*.cpp LIB/*.cpp $(LDFLAGS) -o $(OUTPUT)

run:
	./$(OUTPUT)