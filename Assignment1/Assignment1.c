#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"



char* fileName = "TestFile.txt";

int local_text_rows = 64;
int local_text_chars = 64;
int text_from_file_rows = 64;
int text_from_file_chars = 64;
int user_input_len = 64;

char** text_from_file = NULL;
char** local_text = NULL;
char* user_input = NULL;

Coordinates coords;
int check = 0;
int main() {
	char* helper = "0 - close the program\n"
		"1 - append symbols to the end\n"
		"2 - start the new line\n"
		"3 / 4 - save from / load in file\n"
		"5 - print current text to console\n"
		"6 - insert text by index in file\n"
		"7 - search substring position in file\n";
	printf("%s", helper);

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
			readConsole();
			end_insert_input();

			// ------- was used for debugging -------
			/*for( int i = 0; local_text[i] != NULL && local_text[i] != '\0'; i++)
			{
				printf("%s\n", local_text[i]);
			}*/
			// ---------------------------------------

			break;

			// start new line in the string
		case 2:
			printf("x is 2\n");
			break;

			// save current string to the file 
		case 3:

			local_text = calloc(10, sizeof(char*));
			local_text[0] = "Some useless text";

			saveToFile(fileName, local_text);
			printf("Text has been saved to the file\n");
			break;
			// load string from the file
		case 4:
			text_from_file = loadFromFile(fileName);
			printf("Text has been loaded from the file\n");

			// ----- was used for debugging -----
			//for(int i = 0; text[i] != NULL; i++) {
			//    printf("%s\n", text[i]);
			//}
			//-----------------------------------
			break;
			// print current string to console
		case 5:
			for (int i = 0; local_text[i] != NULL && local_text[i] != "\0"; i++) {
				printf("%s\n", local_text[i]);
			}
			break;
			// insert text by index in file
		case 6:
			printf("Enter coordinates (fromat: (x,y) - (row, line)):  ");
			coords = readCoordinates();

			// ----- was used for debugging -----
			// printf("%d %d\n", coords.line, coords.index);
			// ----------------------------------
			break;

			// search substring position in file
		case 7:
			break;
		default:
			printf("Such command does not exist\n");
			break;
		}
	}

	return 0;
}
