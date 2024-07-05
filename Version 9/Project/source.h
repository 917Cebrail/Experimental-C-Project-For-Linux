#define SOURCE_H
#ifndef SOURCE_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void File(char *path, char op, char *line)
{
    if (op == 'O')
    {
        FILE *file = fopen(path, "r");

        if (file == NULL)
        {
            	printf("File is not existed. The %s file created.", path);
	    	fopen(path, "w");
	    	fputs(".\n",file);
	    	fclose(file);
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
            printf("File is not opened");
        }

        fputs(line, file);

        fclose(file);
    }
    else
    {
    	
    }
}

#endif
