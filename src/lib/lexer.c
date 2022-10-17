#include <string.h>
#include <stdio.h>

int tokenize(char *buffer) {
	char code[strlen(buffer)];
	
	
	strcpy(code, buffer);
	memmove(&code['\n'],&code['\n'+1],strlen(code)-'\n');

	char *line = strtok(code, ";");
	int lineNumber = 0;

	while (line != NULL) {
		lineNumber++;
		printf("Line %i:\t%s \n", lineNumber, line);
		
		line = strtok(NULL, ";");
	}

	return 0;
}