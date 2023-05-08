#ifndef READFILE_H
#define READFILE_H

#include <stdio.h>
#include "card.h"

FILE * file;

char cwd[1024];
char *memoryBuff;
long file_size;

char *file_name = "DATA.txt";
char * file_save ="shuffled_cards.txt";
char file_path[1024];

typedef struct ReadFile{

}ReadFile;

ReadFile readFromFile(char *file);
#endif
