#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "source.h"
#include "alu.h"
#include "func.h"

int main()
{
	printf(COLOR_CYAN);
	box(1, 34);
	printf( COLOR_YELLOW "\n M A N A G E M E N T " COLOR_MAGENTA " < S T D I/O >" COLOR_RESET);
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
			if (check == 1) printf("\n Sigmoid : %f", Sigmoid(x, y, (x+y)/2));
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
			length = 4;
			bool s1[4][4] = {
				{0, 0, 1, 0},
				{0, 1, 1, 0},
				{0, 0, 1, 0},
				{0, 0, 1, 0}
			};
			bool c1[4][4] = {
				{0, 1, 0, 1},
			     	{0, 1, 1, 1},
				{0, 1, 1, 1},
				{0, 1, 1, 0}
			};
			printf( COLOR_GREEN "\n D A T A\n" COLOR_RESET);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{ printf(" Original (" COLOR_CYAN "%1d" COLOR_RESET " , " COLOR_CYAN "%1d" COLOR_RESET ")  =  %b \n Cracked  (" COLOR_CYAN "%1d" COLOR_RESET " , %1d)  =  %b", i, j, s1[i][j], i, j, c1[i][j]); }
				printf("\n");
			}
			hamming(s1, c1);
			printf("\n");
		}
		else if (cmd == 5)
		{
			int len = 7;
			float image[7][7] = {
				{0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0},
				{0, 1, 1, 0, 0},
				{0, 0, 1, 0, 0},
				{0, 0, 1, 0, 0},
				{0, 1, 1, 1, 0},
				{0, 0, 0, 0, 0}
			};
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					if (image[i][j] != 0)
					{ if (neuron(image[i][j],i ,j) == 1) { printf("#"); } else { printf(":"); } }
					else { printf("."); }
				}
				printf("\n");
			}
		}
		else if (cmd == 6)
		{
			hertz = 1000000;
			bool s1[2] = {0, 0}, s2[2] = {0, 0}, i1 = 1, i2 = 0, selector = 1;
			for (int i = 0; i < 2; i++) 
			{ 
				printf("\n Enter s1[%d] : ", i); scanf("%b", s1[i]);
				printf("\n Enter s2[%d] : ", i); scanf("%b", s2[i]);
			}
			printf("\n I1 : %b ,  I2 : %b ,  Result : %b\n", i1, i2, ALU(s1, s2, selector, i1, i2));
		}
		else if (cmd == 7)
		{ system("clear"); }
		else if (cmd == 8)
		{
			printf("\n 1 : Drawing\n 2 : Calculating\n \\-> + , - , * , / , POW , SQRT({1 or 2}) , > , <");
			printf("\n 3 : Formulas\n 4 : Hamming Style Code\n 5 : Photo AI (Experimental)");
			printf("\n 7 : Clear Screen\n 8 : Help \n 9 : PC Information\n 0 : Exit\n 10 : Extensions (Coming soon)");
		}
		else if (cmd == 9)
		{
			printf(COLOR_CYAN "\n Disk Information\n" COLOR_RESET);
			system("df -h");
			printf(COLOR_GREEN "\n Kernel Verison\n" COLOR_RESET);
			system("uname -r");
			printf(COLOR_RED "\n Ram Usage\n" COLOR_RESET);
			system("free -h");
		}
		else if (cmd == 10)
		{
			double correct[4] = {2, 4, 5, 6};
			double incorrect[4] = {2, 4, 5, 7};
			for (int i = 0; i < 4; i++)
			{ printf("\n Data : %1f  <-> Correct : %1f , Data : %1f <-> Incorrect : %1f",correct[i], solomon(correct[i]), incorrect[i], solomon(incorrect[i])); }
			printf("\n\n");
			Array4D(2, 2, 2, 2);
		}
		else { printf( COLOR_RED " Wrong command " COLOR_CYAN " if you don't know a commands ? type '" COLOR_YELLOW "8" COLOR_CYAN "' and see the all commands"); }
	}
	return 0;
}
