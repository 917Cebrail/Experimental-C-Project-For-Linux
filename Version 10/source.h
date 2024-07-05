#ifndef SOURCE_H
#define SOURCE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 32

void File(char *path, char op, char *line)
{
    if (op == 'O')
    {
        FILE *file = fopen(path, "r");

        if (file == NULL)
        {
            printf("File does not exist. Creating %s file.\n", path);
            file = fopen(path, "w");
            if (file != NULL)
            {
                fputs(".\n", file);
                fclose(file);
            }
            return;
        }

        int character;
        while ((character = fgetc(file)) != EOF)
        {
            putchar(character);
        }

        fclose(file);
    }
    else if (op == 'N')
    {
        FILE *file = fopen(path, "w");

        if (file == NULL)
        {
            printf("File cannot be opened for writing.\n");
            return;
        }

        fputs(line, file);

        fclose(file);
    }
    else
    {
        printf("Invalid operation.\n");
    }
}

void readCityFromFile(const char *filename, int ***city, int *rows, int *cols)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int **tempCity = NULL;
    int rowCount = 0;

    while (fgets(line, sizeof(line), file))
    {
        int colCount = 0;
        int *row = NULL;
        char *token = strtok(line, ",");
        while (token)
        {
            row = realloc(row, sizeof(int) * (colCount + 1));
            row[colCount++] = atoi(token);
            token = strtok(NULL, ",");
        }

        tempCity = realloc(tempCity, sizeof(int *) * (rowCount + 1));
        tempCity[rowCount++] = row;
    }

    fclose(file);

    *city = tempCity;
    *rows = rowCount;
    *cols = rowCount > 0 ? strlen(line) : 0;
}

void displayCity(int **city, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            switch (city[i][j])
            {
                case 1:
                    putchar('#');
                case 2:
                    putchar('-');
                case 3:
                    putchar('[');
                case 4:
                    putchar(']');
                case 0:
                    putchar('.');
                default:
                    putchar('?');
            }
        }
        putchar('\n');
    }
}

void freeCity(int **city, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(city[i]);
    }
    free(city);
}

#endif
