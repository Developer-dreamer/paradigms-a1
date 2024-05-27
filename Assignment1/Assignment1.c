#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"



char* file_name = "TestFile.txt";

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
		"3 / 4 - save to / load from file\n"
		"5 - print current text to console\n"
		"6 - insert text by index in file\n"
		"7 - search substring position in file\n";
	printf("%s", helper);

	int breaker = 1;
	while (breaker) {

		int command = readCommand();

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

			printf("Text has been appended\n");

			break;

			// start new line in the string
		case 2:
		{
			if (startNewLine())
			{
				printf("New line has been started succsessfully\n");
			}
			break;
		}
		// save current string to the file 
		case 3:
			saveToFile();
			printf("Text has been saved to the file\n");
			break;
			// load string from the file
		case 4:
			if (!loadFromFile()) { 
				// checking if the function was successful and no error with allocations occured
				// !0 = 1 -> true (which means everything was loaded successfully)
				// ----- was used for debugging -----
				if (text_from_file != NULL) { // checking for null to avoid access violation
					for (int i = 0; text_from_file[i] != NULL; i++) {
						printf("%s\n", text_from_file[i]);
					}
				}
			}
			else {
				printf("Error loading from file\n");
			}

			concatenate_text();

			
			break;
			// print current string to console
		case 5:
			if (local_text == NULL) {
				printf("Local text is empty\n");
				break;
			}

			for (int i = 0; local_text[i] != NULL || local_text[i] != '\0'; i++) {
				if (local_text[i][0] == '\n') {
					local_text[i][0] = '\0';
				}
				printf("%s\n", local_text[i]);
			}
			break;
			// insert text by index in file
		case 6:
			printf("Enter coordinates (fromat: (x,y) - (row, line)):  ");
			coords = readCoordinates();
			
			insert_text_by_index();
			// ----- was used for debugging -----
			//printf("%d %d\n", coords.line, coords.index);
			// ----------------------------------
			break;

			// search substring position in file
		case 7:
			readConsole();
			text_searcher();
			break;
		default:
			printf("Such command does not exist\n");
			break;
		}
	}

	return 0;
}
