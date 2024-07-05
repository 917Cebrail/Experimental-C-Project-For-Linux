#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "source.h"
#include "exe.h"

int main()
{
    WINDOW *win1, *win2;
    int height, width;
    initscr();
    cbreak();
    height = 20;
    width = 80;
    win1 = newwin(5, width, 1, 1);
    box(win1, 1, 1);
    wrefresh(win1);
    win2 = newwin(height, width, 5, 1);
    box(win2, 1, 1);
    wrefresh(win2);

    while (true)
    {
        werase(win1);
        werase(win2);
        mvwprintw(win1, 1, 1, "[F] File   [E] Exit");
        mvwprintw(win1, 2, 1, "File -> [O] Open txt file   [N] New txt file");
        mvwprintw(win1, 3, 1, "Date & Time : ");
        wrefresh(win1);
        system("date");
        
        mvwprintw(win2, 2, 1, "      Plutonia Experimental Project");
        mvwprintw(win2, 3, 1, "[1] Paint     [2] Calculator   [3] Executive Code");
        mvwprintw(win2, 4, 1, "[4] About     [5] Experimental [6] Show Directory");
        wrefresh(win2);
        
        char c = wgetch(win1);

        if (c == 'E')
        {
            delwin(win1);
            delwin(win2);
            endwin();
            break;
        }
        else if (c == '1')
        {
            char _path[256];
            mvwprintw(win2, 5, 1, "File name { *.sli } : ");
            wrefresh(win2);
            echo();
            wgetstr(win2, _path);
            noecho();
            int **city = NULL;
            int rows = 0, cols = 0;
            readCityFromFile(_path, &city, &rows, &cols);
            displayCity(city, rows, cols);
            freeCity(city, rows);
            wgetch(win2);
        }
        else if (c == '2')
        {
            float n1, n2;
            char s1[64], s2[64];
            mvwprintw(win2, 5, 1, "Number 1 : ");
            wrefresh(win2);
            echo();
            wgetstr(win2, s1);
            mvwprintw(win2, 6, 1, "Number 1 : ");
            wrefresh(win2);
            echo();
            wgetstr(win2, s2);
            noecho();
            n1 = atof(s1); 
            n2 = atof(s2);
            mvwprintw(win2, 7,  1, "|-> [+] : %f", (n1 + n2));
            mvwprintw(win2, 8,  1, "|-> [-] : %f", (n1 - n2));
            mvwprintw(win2, 9,  1, "|-> [x] : %f", (n1 * n2));
            mvwprintw(win2, 10, 1, "\\-> [/] : %f", (n1 / n2));
            wrefresh(win2);
            getchar();          
        }
        else if (c == '3')
        {
            FILE *file;
    		char line[256], path[128];
            mvwprintw(win2, 5, 1, "File path { *.ce } : ");
            wrefresh(win2);
            echo();
            wgetstr(win2, path);    		
        	file = fopen(path, "r");
        	while (fgets(line, sizeof(line), file) != NULL) 
        	{ Compiler(line); }
        	fclose(file);
        	wrefresh(win2);
        	getchar();
        }
        else if (c == '4')
        {
        	mvwprintw(win2, 5, 1, "This track was added on Jul 05, 2024, 21:53:40");
        	mvwprintw(win2, 6, 1, "The person who created this MS-DOS style program is Cebrail Kutlar.");
        	mvwprintw(win2, 7, 1, "Producer: Cebrail Kutlar");
        	wrefresh(win2);
        	getchar();
        }
        else if (c == '5')
        {
        	mvwprintw(win2, 5, 1, "It will also be added in the next updates");
        	mvwprintw(win2, 6, 1, "Please wait until that date");
        	wrefresh(win2);
        	getchar();
        }
        else if (c == '6')
        {
        	mvwprintw(win2, 5, 1, "Directory : ");
        	wrefresh(win2);
        	system("ls");
        	getchar();
        }        
        else if (c == 'F')
        {
            while (true)
            {
                char cc = wgetch(win1);

                if (cc == 'O')
                {
                    mvwprintw(win2, 5, 1, "File path : ");
                    wrefresh(win2);

                    char file[100];
                    echo();
                    wgetstr(win2, file);
                    noecho();

                    File(file, cc, "");
                    wgetch(win2);
                    break;
                }
                else if (cc == 'N')
                {
                    mvwprintw(win2, 5, 1, "File path : ");
                    wrefresh(win2);

                    char file[100];
                    echo();
                    wgetstr(win2, file);

                    mvwprintw(win2, 6, 1, "Text : ");
                    char line[2048];
                    wgetstr(win2, line);
                    noecho();

                    File(file, cc, line);
                    wgetch(win2);
                    break;
                }
                else
                {
                    
                }
            }
        }
    }

    return 0;
}
