#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	if (strlen(user_input) == 1) {
		return user_input[0];
	}

	return 0;
}

int readCommand() {
	printf("Enter a command: ");

	char input;
	// Read the first non-whitespace character
	while ((scanf(" %c", &input) != 1) || isspace(input));

	// Clear the input buffer
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	if (isdigit(input)) { 
		return input - '0'; 
	}
	else {
		return -1;
	}
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