#ifndef READ_FILE_H
#define READ_FILE_H
#include <stddef.h>

typedef struct {
    char name[7];
    int x, y;
    double r;
} figure;

void skip_char(size_t* i, char* line, size_t symb);

size_t parse_coord(size_t* i, int* coord, char* line);

size_t read_string(char* line, size_t number, figure* circle);

size_t read(char* str, figure* circle);
#endif