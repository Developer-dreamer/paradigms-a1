#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"

typedef struct Coordinates {
    int line;
    int index;
} Coordinates;

int main() {
    char* helper = "0 - close the program\n"
                    "1 - append symbols to the end\n"
                    "2 - start the new line\n"
                    "3 / 4 - save from / load in file\n"
                    "5 - print current text to console\n"
                    "6 - insert text by index in file\n"
                    "7 - search substring position in file\n";
    printf("%s", helper);
    
    char* fileName = "TestFile.txt";

    char** text;
    char* userInput;

    int breaker = 1;
    while (breaker) {
        printf("Enter a command: ");
        int command;
        scanf_s("%d", &command);

        switch (command) {

            // close the program
        case 0:
            breaker = 0;
            printf("Program has been closed successfully\n");
            break;

            // append symbols to the end of string
        case 1:
            printf("x is 1\n");
            break;

            // start new line in the string
        case 2:
            printf("x is 2\n");
            break;

            // save current string to the file 
        case 3:

            text = calloc(10, sizeof(char*));
            text[0] = "Some useless text";

            saveToFile(fileName, text);
            printf("Text has been saved to the file\n");

            // load string from the file
        case 4:
            text = loadFromFile(fileName);

            // ----- was used for debugging -----
            //for(int i = 0; text[i] != NULL; i++) {
            //    printf("%s\n", text[i]);
            //}
            //-----------------------------------

            break;
        default:
            printf("Such command does not exist\n");
            break;
        }
    }

    return 0;
}
