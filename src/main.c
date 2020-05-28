#include "circle_proc.h"
#include "read_file.h"
#include <stdio.h>
#define N 1000

figure circle[N];

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Incorrect arguments\n");
        return 0;
    }
    size_t number = read(argv[1], circle);
    if (number == 0) {
        printf("Invalid data\n");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        printf("%d. circle (%d %d, %.1lf)\n",
               i + 1,
               circle[i].x,
               circle[i].y,
               circle[i].r);
        printf("perimeter = %.3lf\n", perimeter(circle, i));
        printf("area = %.3lf\n", area(circle, i));
    }
    return 0;
}
