#define FUNC_H
#ifdef FUNC_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "source.h"

int length;

float max(float y, float s)
{ if (y < s) return s; else return y; }
float min(float y, float s)
{ if (s < y) return (s - s); else return y - y; }
float Sigmoid(float s1, float s2, float s3)
{ return 1 / (1 + exp(-(s1 * s2) + s3)); }
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
bool _xor(bool s1, bool s2)
{ return (s1 != s2); }
void hamming(bool data[length][length], bool cracked_data[length][length]){
	bool ram[length][length];
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			ram[i][j] = _xor( _xor(data[i][j], data[i][j]) , _xor(data[i][j], data[i][j]));
			if (ram[i][j] != cracked_data[i][j]) 
			{ printf("\n ( " COLOR_CYAN "%1d" COLOR_RESET " , " COLOR_CYAN "%1d" COLOR_RESET " ) " COLOR_RED "Address Error" COLOR_RESET " ", i, j); }
			else { printf(COLOR_GREEN "\n Nothing Wrong ? " COLOR_RESET); }
		}
	}
}
#endif
