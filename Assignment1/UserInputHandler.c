#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"

int end_insert_input() {
	if (local_text == NULL) {
		local_text = calloc(local_text_rows, sizeof(char*));
	}

	for (int i = 0; i < local_text_rows; i++)
	{
		if (local_text[i] == NULL) {
			local_text[i] = calloc(local_text_chars, sizeof(char));
		}
		if (local_text[i + 1] == '\0') {
			if (local_text_chars < user_input_len) {
				local_text_chars = user_input_len;
				local_text[i] = realloc(local_text[i], local_text_chars);
			}
			strcat(local_text[i], user_input);
			break;
		}
		if (i + 1 < local_text_rows && local_text[i + 1] != NULL && local_text[i + 1][0] == '\n')
		{
			strcpy(local_text[i + 1], user_input);
			break;
		}
	}

	free(user_input);
	return 0;
}

int startNewLine() {
	if (local_text == NULL || local_text[0] == '\0')
	{
		return 0;
	}
	
	for (int i = 0; i < local_text_rows; i++)
	{
		if (local_text[i] == NULL || local_text[i] == '\0') {
			local_text[i] = calloc(local_text_chars, sizeof(char));
			local_text[i][0] = '\n';
			return 1;
		}
	}

	return 0;
}
