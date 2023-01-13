CC = gcc
C_LIBS := -lm
CFLAGS = -std=c11 -Wall -Werror -Wextra
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: build

build: test s21_string.a

test:  Tests/test.o s21_string.a
	$(CC) $(CFLAGS) Tests/test.o s21_string.a $(C_LIBS) -o test

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)

rebuild: clean all 
	./test

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

clean:
	rm -rf *.a *.o Tests/*.o s21_string test
