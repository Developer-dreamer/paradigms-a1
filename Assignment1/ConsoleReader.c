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
	printf("Enter coordinates (fromat: (x,y) - (row, line)):  ");
	if (scanf("%d %d", &coords.line, &coords.index) == 2) {
		return coords;
	}
	else
	{
		printf("Invalid input\n");
		return;
	}

}

int text_remover() {
	printf("Do you want to save local text to file (2) or clear buffer and file text (1) or clear text from file only (0)?: ");
	char answer;
	scanf(" %c", &answer);
	if (answer == '2') {
		saveToFile();
		printf("Local text has been saved to file.\n");
		return 1;
	}
	else if (answer == '1') {
		for (int i = 0; local_text[i] != NULL; i++) {
			free(local_text[i]);
			local_text[i] = NULL;
		}
		free(local_text);
		local_text = NULL;
		for (int i = 0; text_from_file[i] != NULL; i++) {
			free(text_from_file[i]);
			text_from_file[i] = NULL;
		}
		free(text_from_file);
		text_from_file = NULL;
		printf("Local text has been cleared.\n");
		return 1;
	}
	else if (answer == '0')
	{
		for (int i = 0; text_from_file[i] != NULL; i++) {
			free(text_from_file[i]);
			text_from_file[i] = NULL;
		}
		free(text_from_file);
		text_from_file = NULL;	 
		printf("Local text has been cleared.\n");
		return 0;
	}
	else {
		printf("Local text and text from file saved separately\n");
		return 0;
	}
}