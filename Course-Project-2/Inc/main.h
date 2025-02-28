#ifndef INC_MAIN_H_

#define INC_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Inc/test.h"

double f1(double x);
double f2(double x);
double f3(double x);
double df1(double x);
double df2(double x);
double df3(double x);
double root(double (*f)(double), double (*g)(double), double a, double b, double eps1, double (*df)(double), double (*dg)(double));
double integral(double (*f)(double), double a, double b, double eps2);

#endif