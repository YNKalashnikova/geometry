#include <stdio.h>

int main()
{
    FILE* file;
    struct figure {
        char name[10];
        int p[3];
    };
    struct figure circle[10];
    int i = 0;
    file = fopen("figures.txt", "r");

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
    return 0;
}