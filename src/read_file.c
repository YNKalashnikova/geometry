#include "read_file.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void skip_char(size_t* i, char* line, size_t symb)
{
    while (line[*i] == symb) {
        *i += 1;
    }
}

size_t parse_coord(size_t* i, int* coord, char* line)
{
    *coord = atoi(&line[*i]);
    skip_char(i, line, ' ');
    if (!(line[*i] == '0') && *coord == 0) {
        return 1;
    }
    skip_char(i, line, '-');
    while (isdigit(line[*i])) {
        *i += 1;
    }
    return 0;
}

size_t read_string(char* line, size_t number, figure* circle)
{
    size_t i = 0;
    while (line[i] != '(') {
        if (line[i] == ' ') {
            i++;
            continue;
        }
        circle[number].name[i] = tolower(line[i]);
        i++;
    }
    i++;
    size_t bug = 0;
    bug = parse_coord(&i, &circle[number].x, line);
    bug = parse_coord(&i, &circle[number].y, line);
    skip_char(&i, line, ' ');
    if (line[i] == ',') {
        i++;
    } else {
        return 0;
    }
    skip_char(&i, line, 32);
    circle[number].r = strtod(&line[i], NULL);
    size_t tochka = 0;
    while ((isdigit(line[i])) || ((line[i] == '.') && (tochka == 0))) {
        if (line[i] == '.') {
            tochka++;
        }
        i++;
    }
    skip_char(&i, line, ' ');
    if ((circle[number].r <= 0) || (strcmp(circle[number].name, "circle") != 0)
        || (line[i] != ')') || (bug > 0) || (line[i + 1] != '\n')) {
        return 0;
    }
    return 1;
}

size_t read(char* str, figure* circle)
{
    FILE* file = fopen(str, "r");
    if (!file) {
        return 0;
    }
    size_t number = 0;
    char line[500];
    while (fgets(line, 500, file) != NULL) {
        size_t debug = read_string(line, number, circle);
        if (debug == 0) {
            return 0;
        }
        number++;
    }
    fclose(file);
    return number;
}
