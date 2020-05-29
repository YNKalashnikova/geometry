#include "circle_proc.h"
#include <ctest.h>

figure circle[1000];

void create_circle(figure* circle, size_t n, int p1, int p2, double p3)
{
    circle[n].x = p1;
    circle[n].y = p2;
    circle[n].r = p3;
}

CTEST(parse_coord, correct_x)
{
    char* line = "circle (1 2, 3)\n";
    size_t expect = 0;
    size_t i = 8;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, incorrect_x)
{
    char* line = "circle (a 2, 3)\n";
    size_t expect = 1;
    size_t i = 8;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, correct_y)
{
    char* line = "circle (1 2, 3)\n";
    size_t expect = 0;
    size_t i = 10;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, incorrect_y)
{
    char* line = "circle (1 b, 3)\n";
    size_t expect = 1;
    size_t i = 10;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(perimeter, test)
{
    create_circle(circle, 1, 1, 2, 1.5);
    double expect = 3 * M_PI;
    double result = perimeter(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}

CTEST(area, test)
{
    create_circle(circle, 1, 1, 2, 2);
    double expect = 4 * M_PI;
    double result = area(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}

