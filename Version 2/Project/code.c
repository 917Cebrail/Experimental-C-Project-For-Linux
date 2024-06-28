#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "source.h"
#include "func.h"

int main()
{
	printf(COLOR_CYAN);
	box(1, 34);
	printf( COLOR_YELLOW "\n  M A N A G E M E N T " COLOR_MAGENTA " S T D I O " COLOR_RESET);
	printf(COLOR_CYAN);
	box(1, 34);
	int cmd;
	while(true)
	{
		printf( COLOR_RESET "\n Enter a command > ");
		scanf("%d", &cmd);
		if(cmd == 0) { break; }
		else if (cmd == 1)
		{
			int cmd2;
			printf("\n 1 : Box\n 2 : Triangle");
			printf("\n 3 : Exit\n  > ");
			scanf("%d", &cmd2);
			if (cmd2 == 3) printf("\n");
			else if (cmd2 != 3)
			{
				int x, y;
			        printf("\n X : ");
				scanf("%d", &x);
	 			printf("\n Y : ");
				scanf("%d", &y);
				if (cmd2 == 1) box(x, y);
				else if (cmd2 == 2) triangle(x, y);
				else printf("\n");
			}
		}
		else if (cmd == 2) 
		{
			int x, y;
			char *_op;
			printf("\n S1 : ");
			scanf("%d", &x);
			printf("\n S2 : ");
			scanf("%d", &y);
			printf("\n Operator : ");
			scanf("%s", &_op);
			printf("\n ! NOTE ! 0 = ERROR");
			printf("\n Result : %f", operator(x, y, _op));
		}
		else if (cmd == 3) 
		{
			printf("\n [1] : Sigmoid  [2] : ReLU");
			printf("\n [3] : Formul1  [4] : Formul2  [5] : Formul3\n [6] : Formul4  [7] : Formul5  [8] : Formul6");
			int check, x, y;
			printf("\n > ");
			scanf("%d", &check);
			printf("\n Num 1 : ");
			scanf("%d", &x);
			printf("\n Num 2 : ");
			scanf("%d", &y);
			if (check == 1) printf("\n Sigmoid : %f", Sigmoid(x, y));
			else if (check == 2) printf("\n ReLU N1 : %f  ,  ReLU N2 : %f" , ReLU(x), ReLU(y));
			else if (check == 3) printf("\n Formul1 : %f", Formul1(x, y));
			else if (check == 4) printf("\n Formul2 , N1 : %f  N2 : %f", Formul2(x), Formul2(y));
			else if (check == 5) printf("\n Formul3 : %f", Formul3(x, y));
			else if (check == 6) printf("\n Formul4 : %f", Formul4(x, y));
			else if (check == 7) printf("\n Formul5 : %f", Formul5(x, y));
			else if (check == 8) printf("\n Formul6 : %f", Formul6(x, y));
			else printf("\n Wrong Operator.");
		}
		else if (cmd == 4) 
		{
			bool s1[10] = {0, 1, 1, 0, 0, 1, 1, 1, 0, 1};
			bool c1[10] = {0, 1, 0, 1, 0, 1, 1, 1, 0, 1};
			hamming(s1, c1, 10);
		}
		else if (cmd == 8)
		{
			printf("\n 1 : Drawing\n 2 : Calculating");
			printf("\n 3 : Formulas\n 4 : Hamming Style Code");
			printf("\n 8 : Help \n 0 : Exit");
		}
		else if (cmd == 9)
		{
			printf("\n Nothing ? \n");
		}
		else { printf( COLOR_RED " Wrong command " COLOR_CYAN " if you don't know a commands ? type '" COLOR_YELLOW "8" COLOR_CYAN "' and see the all commands"); }
	}
	return 0;
}
