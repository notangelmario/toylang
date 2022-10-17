CC=gcc
DEPS = src/lib/file.c

all: clean compile

compile:
	@mkdir bin
	$(CC) src/main.c $(DEPS) -o bin/toylang

clean:
	@rm -rf bin