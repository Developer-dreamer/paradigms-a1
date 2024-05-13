#pragma once
#ifndef READER_H
#define READER_H

char* readConsole();
int readCommand();

#endif

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

int saveToFile(FILE* );
char** loadFromFile(FILE* );

#endif
