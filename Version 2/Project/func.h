#define FUNC_H
#ifdef FUNC_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "source.h"

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
bool _xor(bool s1, bool s2)
{ return (s1 != s2); }
void hamming(bool *data, bool *cracked_data, int length){
	bool *ram;
	for (int i = 0; i < length; i++)
	{ ram[i] = _xor(data[(i)], data[(i)]); }
	for (int j = 0; j < length; j++)
	{
		printf("\n");
		if (ram[j] != _xor(cracked_data[j], data[j]))
		{
			printf("%d . Address cracked data is not equels the original data.", j);
		}
		else
		{
			printf("Nothing wrong ?");
		}
	}
	printf( COLOR_CYAN "\n\n R E S U L T S \n" COLOR_RESET );
	for (int k = 0; k < length; k++)
	{
		printf("\n Recover Data : %b , Cracked Data : %b , Original Data : %b", ram[k], cracked_data[k], data[k]);
	}
}
#endif
