#define ALU_H
#ifdef ALU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool AND(bool s1, bool s2){ return s1 && s2; }
bool OR(bool s1, bool s2) { return s1 || s2; }
bool NOT(bool s) { return !s; }
bool XOR(bool s1, bool s2) { return s1 != s2; }
bool NOR(bool s1, bool s2) { return !(s1 || s2); }
bool XNOR(bool s1, bool s2) { return !(s1 != s2); }
bool NAND(bool s1, bool s2) { return !(s1 && s2); }
bool RAM[8];
bool ALU(bool s1[2], bool s2[2], bool selector, bool i1, bool i2)
{
	bool select[2];
	select[1] = OR(AND(s1[1], selector), AND(s2[1], selector));
	select[2] = OR(AND(s1[2], selector), AND(s2[2], selector));
	if (select[1] == true && select[2] == true)
	{ return i1; }
	else if (select[1] == true && select[2] == false)
	{ return i2; }
	else if (select[1] == false && select[2] == true)
	{
		for (int i = 0; i < 8; i++)
		{
			if (RAM[i] != 0 || RAM[i] != NULL) {}
			else { RAM[i] == s1; }
		}
		return 1;
	}
	else if (select[1] == false && select[2] == false)
	{
		for (int i = 0; i < 8; i++)
		{
			if (RAM[i] != 0 || RAM[i] != NULL) {}
			else { RAM[i] == s2; }
		}
		return 1;
	}
}

#endif
