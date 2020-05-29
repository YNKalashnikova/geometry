#include "read_file.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

double perimeter(figure* circle, size_t n)
{
    return (2 * M_PI * circle[n].r);
}

double area(figure* circle, size_t n)
{
    return (M_PI * pow(circle[n].r, 2));
}

size_t crossing(figure* circle, size_t n, int i)
{
    if ((sqrt(pow(circle[n].x - circle[i].x, 2)
              + pow(circle[n].y - circle[i].y, 2)))
        <= (circle[n].r + circle[i].r)) {
        return 1;
    }
    return 0;
}

void crossing_check(figure* circle, size_t n, size_t number)
{
    size_t crs = 0;
    for (int i = 0; i < number; i++) {
        if (i != n) {
            if (crossing(circle, n, i) == 1) {
                if (crs == 0) {
                    printf("\tintersects:\n");
                }
                crs = 1;
                printf("\t\t%d. circle\n", i + 1);
            }
        }
    }
}
