#include "read_file.h"
#include <stdio.h>

void read_file(char* str, figure* circle)
{
    FILE* file = fopen(str, "r");
    int i = 0;
    while (fscanf(file,
                  "%s (%d %d, %d)",
                  circle[i].name,
                  &circle[i].p[0],
                  &circle[i].p[1],
                  &circle[i].p[2])
           != EOF) {
        printf("%s (%d %d, %d)\n",
               circle[i].name,
               circle[i].p[0],
               circle[i].p[1],
               circle[i].p[2]);
        i++;
    }
}