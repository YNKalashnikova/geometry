#include "read_file.h"
#include <math.h>
#include <stddef.h>

double perimeter(figure* circle, size_t n)
{
    return (2 * M_PI * circle[n].r);
}