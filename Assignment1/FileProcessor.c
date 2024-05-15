#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Methods.h"

int saveToFile(char* filename, char** text) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    
    for(int i = 0; text[i] != NULL && text[i] != "\0"; i++) {
		fprintf(file, "%s\n", text[i]);
	}
    fclose(file);
    return 0;
}

#define MAX_LINE_LENGTH 256
#define INITIAL_LINES 10

char** loadFromFile(char* filename) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }

    int max_lines = INITIAL_LINES;
    char** lines = malloc(max_lines * sizeof(char*));
    for (int i = 0; i < max_lines; i++) {
        lines[i] = calloc(MAX_LINE_LENGTH, sizeof(char));
    }

    int i = 0;
    while (fgets(lines[i], MAX_LINE_LENGTH, file) != NULL) {
        // Remove the newline character
        lines[i][strcspn(lines[i], "\n")] = '\0';
        i++;

        // If we've reached the end of the array, resize it
        if (i >= max_lines) {
            max_lines *= 2;
            lines = realloc(lines, max_lines * sizeof(char*));
            for (int j = i; j < max_lines; j++) {
                lines[j] = calloc(MAX_LINE_LENGTH, sizeof(char));
            }
        }
    }

    // Close the file
    fclose(file);

    return lines;
}