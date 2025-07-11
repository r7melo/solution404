#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a testing tool for example
int *Integer(int value);
char *String(char *value);


int *Integer(int value){
    int *integer = (int*)malloc(sizeof(int));
    if(integer != NULL) *integer = value;
    return integer;
}

char *String(char *value){
    char *string = (char*)malloc(strlen(value)+1);
    if(string != NULL) strcpy(string, value);
    return string;
}
