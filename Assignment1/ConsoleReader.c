#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Methods.h"

int readConsole() {

	user_input = malloc(user_input_len * sizeof(char));
	int length = 0;

	printf("Enter a string: ");
	// Clear the input stream
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	int row_to_insert = 0;
	while (1) {

		fgets(user_input + length, user_input_len - length, stdin);
		
		length = strlen(user_input);
		if (length == (user_input_len - 1)) {
			user_input_len *= 2;
			user_input = realloc(user_input, user_input_len);
		}

		if (user_input[length - 1] == '\n') {
			user_input[length - 1] = '\0';
			break;
		}

	}

	return 0;
}

int readCommand() {
	char* command = malloc(2);
	fgets(command, 2, stdin);
	return atoi(command);
}

Coordinates readCoordinates() {
	Coordinates coords;
	if (scanf("%d %d", &coords.line, &coords.index) == 2) {
		return coords;
	}
	else
	{
		printf("Invalid input\n");
		return;
	}

}