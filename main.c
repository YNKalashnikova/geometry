#include "read_file.h"
#include <stdio.h>
#define N 10

figure circle[N];

int main(int argc, char** argv)
{
    read_file(argv[1], circle);
    return 0;
}
