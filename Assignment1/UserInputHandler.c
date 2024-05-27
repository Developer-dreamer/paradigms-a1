#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Methods.h"

int end_insert_input() {
	if (local_text == NULL) {
		local_text = calloc(local_text_rows, sizeof(char*));
	}

	for (int i = 0; i < local_text_rows; i++)
	{
		if (local_text[i] == NULL) {
			local_text[i] = calloc(local_text_chars, sizeof(char));
			if (local_text[i] == NULL) {
				printf("Failed to allocate memory\n");
				return -1;
			}
		}
		if (local_text[i + 1] == '\0' || local_text[i + 1] == NULL) {
			if (local_text_chars < user_input_len) {
				local_text_chars = user_input_len;
				local_text[i] = realloc(local_text[i], local_text_chars);
				if (local_text[i] == NULL) {
					printf("Failed to reallocate memory\n");
					return -1;
				}
			}
			if (local_text[i][0] == '\n')
			{
				local_text[i][0] = '\0';	
				strcat(local_text[i], user_input);
				break;
			}
			strcat(local_text[i], user_input);
			break;
		}

	}

	free(user_input);
	user_input = NULL;
	return 0;
}

int start_new_line() {
	if (local_text == NULL || local_text[0] == '\0')
	{
		return 0;
	}

	for (int i = 0; i < local_text_rows; i++)
	{
		if (local_text[i] == NULL || local_text[i] == '\0') {
			local_text[i] = calloc(local_text_chars, sizeof(char));
			if (local_text[i] == NULL)
			{
				printf("Failed to allocate memory\n");
				return -1;
			}
			local_text[i][0] = '\n';
			return 1;
		}
	}

	return 0;
}

int insert_text_by_index() {
	if (coords.line < 0 || coords.line >= local_text_rows || coords.index < 0 || coords.index >= local_text_chars) {
		return -1;
	}

	if (local_text == NULL) {
		local_text = calloc(local_text_rows, sizeof(char*));
		if (local_text == NULL)
		{
			printf("Failed to allocate memory\n");
			return -1;
		}
	}

	if (local_text[coords.line] == NULL) {
		local_text[coords.line] = calloc(local_text_chars, sizeof(char));
		if (local_text[coords.line] == NULL)
		{
			printf("Failed to allocate memory\n");
			return -1;
		}
	}

	if (local_text_chars < coords.index + strlen(user_input) + strlen(&local_text[coords.line][coords.index])) {
		local_text_chars = coords.index + strlen(user_input) + strlen(&local_text[coords.line][coords.index]);
		local_text[coords.line] = realloc(local_text[coords.line], local_text_chars);
		if (local_text[coords.line] == NULL)
		{
			printf("Failed to reallocate memory\n");
			return -1;
		}
	}

	if (local_text[coords.line][coords.index] == '\n') {
		local_text[coords.line][coords.index] = '\0';
	}

	// Move existing elements to the right to make space for the new text
	memmove(&local_text[coords.line][coords.index + strlen(user_input)], &local_text[coords.line][coords.index], strlen(&local_text[coords.line][coords.index]) + 1);

	// Insert the new text
	memcpy(&local_text[coords.line][coords.index], user_input, strlen(user_input));

	// Free the user input
	free(user_input);
	user_input = NULL;

	return 1;
}

int text_searcher() {
	if (local_text == NULL || user_input == NULL) {
		return -1;
	}

	Coordinates coords[256];
	int numMatches = 0;

	for (int i = 0; i < local_text_rows; i++) {
		if (local_text[i] == NULL) {
			continue;
		}

		char* found = strstr(local_text[i], user_input);
		while (found != NULL) {
			
			coords[numMatches].line = i;
			coords[numMatches].index = found - local_text[i];
			numMatches++;

			if (found + 1 < local_text[i] + strlen(local_text[i]) && found != NULL) {
				found = strstr(found + 1, user_input);
			}
			else {
				break;
			}
		}
	}

	printf("Coordinates of the found substrings:\n");
	for (int i = 0; i < numMatches; i++) {
		printf("(%d, %d)\n", coords[i].line, coords[i].index);
	}

	return numMatches;
}
