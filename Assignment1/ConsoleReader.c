#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"

char* readConsole() {
    int arr_size = 64;
    char* string = malloc(arr_size);
    int length = 0;

    while (1) {
        fgets(string + length, arr_size - length, stdin);
        length = strlen(string);

        // If the last character is a newline, we've reached the end of the input
        if (string[length - 1] == '\n') {
            string[length - 1] = '\0'; // Replace the newline with a null terminator
            break;
        }

        // Otherwise, we need to allocate more space
        arr_size *= 2;
        string = realloc(string, arr_size);
        if (string == NULL) {
            printf("Failed to allocate memory\n");
            exit(1);
        }
    }

    return string;
}

int readCommand() {
	char* command = malloc(2);
    fgets(command, 2, stdin);
    return atoi(command);
}
