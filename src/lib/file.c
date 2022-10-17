#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_file(char *filename, char **buffer) {
	unsigned long numbytes;
	FILE *fp = fopen(filename, "r");

	fseek(fp, 0L, SEEK_END);
	numbytes = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	*buffer = calloc(numbytes, sizeof(char));

	if (buffer == NULL) {
		printf("Error allocating memory for buffer\n");
		return 1;
	}

	fread(*buffer, sizeof(char), numbytes, fp);
	fclose(fp);

	return 0;
}