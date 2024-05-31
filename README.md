# Simple text editor 
## Implementation
I was implemented this program using procedural paradigm in C language.
You can find there different files with different functionality.
Each of function defined in Methods.h header for program flexibility, easier reading and refactoring.
There is 10 options which are described in helper variable.
This program can work with files, string arrays, using different functionality for text editing.
## Testing
For program testing you can use next command sequence:
4 - for load the text  
1 : Hello world - for inserting text to the end  
6 : #hi# : 1 10 - insert text with index  
7 : procedural - for finding index of given word  
5 - print current state of the text  
3- save local text to file  
9 - clear the console  
0 - end the program  

## Execution results example:
```
Enter a command: 1
Enter a string: abcd
Text has been appended
Enter a command: 2
New line has been started succsessfully
Enter a command: 5
abcd

Enter a command: 4
Text has been loaded from file
Local text is not empty. Cannot concatenate texts
Do you want to save local text to file (1) or clear text from file only (0)?: 1
Local text has been saved to file.
Text concatenated with local successfully.
Enter a command: 6
Enter a string: Hello,
Enter coordinates (fromat: (x,y) - (row, line)):  0 0
Enter a command: 5
Hello, Understand the basics of procedural and structural programming by having hands-on experience
in using these paradigms. Learn how the memory management works inside the process,
understand the virtual memory concept and typical issues with memory allocation and
deallocation, learn the basic data types.
Enter a command: 7
Enter a string: programming
Coordinates of the found substrings:
(0, 58)
Enter a command: 3
Text has been saved to the file
Enter a command: 0
Program has been closed successfully
```

