#pragma once
#ifndef COORDINATES_H
#define COORDINATES_H

typedef struct Coordinates {
    int line;
    int index;
} Coordinates;

#endif

#ifndef READER_H
#define READER_H

char* readConsole();
int readCommand();
Coordinates readCoordinates();

#endif

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

int saveToFile(FILE* );
char** loadFromFile(FILE* );

#endif

#ifndef USERINPUTHANDLER_H
#define USERINPUTHANDLER_H

int buildText(char**, char*, Coordinates);

#endif