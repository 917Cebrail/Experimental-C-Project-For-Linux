#define FUNC_H
#ifdef FUNC_H

#include <stdio.h>
#include <math.h>

float max(float y, float s)
{ if (y < s) return s; else return y; }
float min(float y, float s)
{ if (s < y) return (s - s); else return y - y; }
float Sigmoid(float s1, float s2)
{ return 1 / (1 + exp(-(s1 * s2) + ((s1 + s2) / 2))); }
float ReLU(float s)
{ return max(0,s); }
float Formul1(float s1, float s2)
{ return sqrt((pow(ReLU(s1), s2) + pow(ReLU(s2), s1))); }
float Formul2(float s)
{ return max(0,s) + 0.1 * min(0,s); }
float Formul3(float s1, float s2)
{ return (exp(s1) / exp(s2)) * exp(s1 + s2); }
float Formul4(float s1, float s2)
{ return (s1 * s2) + (s1 + s2); }
float Formul5(float s1, float s2)
{ return 1 / (1 + sqrt(pow(s1, s2))); }
float Formul6(float s1, float s2)
{ return (Formul2(s1) + Formul2(s2)) / 2; }

#endif
