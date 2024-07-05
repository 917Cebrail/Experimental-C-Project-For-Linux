#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "source.h"

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
        mvwprintw(win1, 1, 1, "[F]File   [E] Exit");
	mvwprintw(win1, 3, 1, "File -> [O] Open txt file   [N] New txt file");
        wrefresh(win1);

        mvwprintw(win2, 1, 1, "      Plutonia Experimental Project");
	mvwprintw(win2, 2, 1, "[1] Drawing   [2] Calculator   [3] Executive Code");
        mvwprintw(win2, 3, 1, "[4] Terminal  [5] Experimental [6] System Info");
	wrefresh(win2);

        char c = wgetch(win1); // Use wgetch instead of getchar for ncurses input

        if (c == 'E')
        {
            delwin(win1);
            delwin(win2);
            endwin();
            break;
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
		    getchar();
		    break;
                }
		else if (cc == 'N')
		{
		    mvwprintw(win2, 5, 1, "File path : ");
                    char file[100];
                    echo();
		    wgetstr(win2, file);
		    mvwprintw(win2, 6, 1, "Text : ");
                    char line[2048];
                    echo();
                    wgetstr(win2, line);
                    noecho();
                    File(file, cc, line);
		    getchar();
		    break;
		}
		else
		{ }
            }
        }
    }

    return 0;
}
