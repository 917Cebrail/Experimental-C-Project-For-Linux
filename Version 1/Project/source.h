#ifndef SOURCE_H
#define SOURCE_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

void box(int x, int y)
{
	for(int i = 0; i < x; i++)
	{
		printf("\n ");
		for(int j = 0; j < y; j++)
		{
			printf("#");
		}
	}
	// printf(" Area : %d , Height : %d", (x + y)*2, (x * y));
}

void triangle(int x, int y)
{
	for(int i = 0; i < x; i++)
	{
		printf("\n#");
		for(int j = i; j < y; j++)
		{
			printf("#");
		}
	}
}

float operator(float s1, float s2, char *_operator)
{
	if(strcmp(_operator, "+")) { return s1 + s2; }
	else if (strcmp(_operator, "-"))
       	{
		if (s1 < s2) return s2 - s1;
		else if (s2 < s1) return s1 - s2;
		else return 0;
       	}
	else if (strcmp(_operator, "*")) return s1 * s2;
	else if (strcmp(_operator, "/"))
	{
		if (s1 < s2) return s2 / s1;
		else if (s2 < s1) return s1 / s2;
		else return 0;
	}
	else if (strcmp(_operator, "POW")) return pow(s1, s2);
	else if (strcmp(_operator, "SQRT(1)")) return sqrt(s1);
	else if (strcmp(_operator, "SQRT(2)")) return sqrt(s2);
	else if (strcmp(_operator, ">"))
	{
		if (s1 > s2) return true;
		else return false;
	}
	else if (strcmp(_operator, "<"))
	{
		if (s1 < s2) return true;
		else return false;
	}
	else return 0;
}

void File(int _operator, char *filePath)
{
	FILE *f;
	if (_operator == 1)
	{
		f = fopen(filePath, "r");
		char *num;
		fscanf(f, "%s", &num);
		printf(" Value : %s", num);
		fclose(f);
	}
	else if (_operator == 2)
	{
		f = fopen(filePath, "w");
		char *line;
		fscanf(f, "%s", &line);
		fprintf(f, "%s", line);
		fclose(f);
	}
	else if (_operator == 3)
	{
		char *name;
		scanf(" File Name : %s\n", &name);
		f = fopen(name, "w");
		fclose(f);
	}
	else
	{
		printf("\n");
	}
}

#endif
