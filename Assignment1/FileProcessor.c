#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Methods.h"

int saveToFile() {
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    
    for(int i = 0; local_text[i] != NULL && local_text[i] != "\0"; i++) {
		fprintf(file, "%s\n", local_text[i]);
	}
    fclose(file);
    return 0;                           
}


char** loadFromFile(char* filename) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }

    int max_lines = text_from_file_rows;
    if (text_from_file != NULL) {
        printf("File already loaded\n");
        return -1;
    }

    text_from_file = malloc(max_lines * sizeof(char*));
    for (int i = 0; i < max_lines; i++) {
        text_from_file[i] = calloc(text_from_file_chars, sizeof(char));
    }

    int i = 0;
    while (fgets(text_from_file[i], text_from_file_chars, file) != NULL) {
        // Remove the newline character
        text_from_file[i][strcspn(text_from_file[i], "\n")] = '\0';
        i++;

        // If we've reached the end of the array, resize it
        if (i >= max_lines) {
            max_lines *= 2;
            text_from_file = realloc(text_from_file, max_lines * sizeof(char*));
            for (int j = i; j < max_lines; j++) {
                text_from_file[j] = calloc(local_text_chars, sizeof(char));
            }
        }
    }

    // Close the file
    fclose(file);

    return 0;
}