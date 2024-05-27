#pragma once

// --------- define gloval variables ---------

extern char* helper;

extern char* file_name;

extern int local_text_rows, local_text_chars, user_input_len;
extern int text_from_file_rows, text_from_file_chars;
extern char** text_from_file;
extern char** local_text;
extern char* user_input;

// ------------------------------------------
#ifndef COORDINATES_H
#define COORDINATES_H

typedef struct Coordinates {
    int line;
    int index;
} Coordinates;
extern Coordinates coords;
#endif

#ifndef READER_H
#define READER_H

int readConsole();
int readCommand();
int text_remover();
Coordinates readCoordinates();

#endif

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

int saveToFile();
int loadFromFile();
int concatenate_text();

#endif

#ifndef USERINPUTHANDLER_H
#define USERINPUTHANDLER_H

int end_insert_input();
int startNewLine();
int insert_text_by_index();
int text_searcher();

#endif