#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/file.h"
#include "lib/lexer.h"

int get_file(char *filename, char **buffer);

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage:\n");
		printf("\t%s file.toy\n", argv[0]);
		return 1;
	}

	char *filename = argv[1];
	char *dot = strrchr(filename, '.');

	if (dot == NULL || (dot && strcmp(dot, ".toy"))) {
		printf("Toylang only accepts .toy files\n");
		return 1;
	}

	char *buffer;

	get_file(filename, &buffer);

	printf("Buffer Size: %i\n", strlen(buffer));
	printf("Buffer:\n");
	printf("%s\n\n", buffer);

	tokenize(buffer);

	free(buffer);
	return 0;
}