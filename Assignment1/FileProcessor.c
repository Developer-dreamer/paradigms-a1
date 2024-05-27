#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Methods.h"

int save_to_file() {
	FILE* file = fopen(file_name, "w");
	if (file == NULL) {
		printf("Failed to open file\n");
		return -1;
	}

	for (int i = 0; i < local_text_rows; i++) {
        if (local_text[i] == NULL) {
			continue;
        }
        if (local_text[i][0] == '\n') {
			local_text[i][0] = '\0';
		}
		fprintf(file, "%s\n", local_text[i]);
		free(local_text[i]);
		local_text[i] = NULL;
	}
	free(local_text);
	local_text = NULL;


	fclose(file);
	return 0;
}


int load_from_file() {

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }

    if (text_from_file != NULL) {
        printf("File already loaded\n");
		return -1;
    }
    text_from_file = calloc(text_from_file_rows, sizeof(char*));
    // added checking for correct allocation
    if (text_from_file == NULL) {
        printf("Failed to allocate memory\n");
        fclose(file);
        return -1;
    }

    for (int i = 0; i < text_from_file_rows; i++) {
        text_from_file[i] = calloc(text_from_file_chars, sizeof(char));
        // same checking here
        if (text_from_file[i] == NULL) {
            printf("Failed to allocate memory\n");
            fclose(file);
            return -1;
        }
    }

    int i = 0;
	int length = 0;
    while (fgets(text_from_file[i] + length, text_from_file_chars - length, file) != NULL) {

        length = strlen(text_from_file[i]);
        if (length == (text_from_file_chars - 1)) {
            text_from_file_chars *= 2;
            text_from_file[i] = realloc(text_from_file[i], text_from_file_chars);
			if (text_from_file[i] == NULL) {
				printf("Failed to reallocate memory\n");
				fclose(file);
				return -1;
			}
        }


        if (text_from_file[i][strlen(text_from_file[i]) - 1] == '\n') {
            text_from_file[i][strlen(text_from_file[i]) - 1] = '\0';
			length = 0;
            i++;
        }


        if (i >= text_from_file_rows) {
            text_from_file_rows *= 2;
            char** temp = realloc(text_from_file, text_from_file_rows * sizeof(char*));
            if (temp == NULL) {
                printf("Failed to reallocate memory\n");
                fclose(file);
                return -1;
            }
            text_from_file = temp;
            for (int j = i; j < text_from_file_rows; j++) {
                text_from_file[j] = calloc(text_from_file_chars, sizeof(char));
                if (text_from_file[j] == NULL) {
                    printf("Failed to allocate memory\n");
                    fclose(file);
                    return -1;
                }
            }
        }
		
    }


    text_from_file[i + 1] = NULL;
    fclose(file);

    return 0;
}
int concatenate_text() {
	// concatenate text from file with local text
	if (local_text == NULL) {
		text_concatenator();
		printf("Text concatenated with local successfully.\n");
		return 0;
	}
	else
	{
		printf("Local text is not empty. Cannot concatenate texts\n");
		if (remove_text()) {
			concatenate_text();
		}
		else
		{
			return 1;
		}
	}
}
int text_concatenator() {
	if (text_from_file == NULL) {
        return 0;
	}
    if (local_text_rows < text_from_file_rows) {
		local_text_rows = text_from_file_rows;
    }
    if (local_text_chars < text_from_file_chars)
    {
		local_text_chars = text_from_file_chars;
    }
	local_text = calloc(local_text_rows, sizeof(char*));
	for (int i = 0; i < text_from_file_rows; i++) {
		local_text[i] = calloc(local_text_chars, sizeof(char));

		if (text_from_file[i] != NULL) {
			strcpy(local_text[i], text_from_file[i]);
			local_text[i][strlen(text_from_file[i])] = '\0';
		}
	}
	return 0;
}