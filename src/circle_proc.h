#ifndef CIRCLE_PROC_H
#define CIRCLE_PROC_H
#include "read_file.h"
#include <math.h>
#include <stddef.h>

double perimeter(figure* circle, size_t n);

double area(figure* circle, size_t n);

size_t crossing(figure* circle, size_t n, size_t i);

void crossing_check(figure* circle, size_t n, size_t number);
#endif