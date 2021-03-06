
/*****************************************************************************
 * Copyright (C) Saurabh Agrawal saurabhagrawal1483@gmail.com
 
 * This file is part of Calculator.

 *   Calculator is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   Calculator is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with Calculator.  If not, see <http://www.gnu.org/licenses/>.

 *****************************************************************************/

#define MAXI 200
#include<stdio.h>

typedef struct stack {
	int i;
	double arr[MAXI];
}stack;

void init(stack* s);

void push(stack* s, double num);

double pop(stack* s);

int isfull(stack *s);

int isempty(stack *s);

double top(stack *s);

typedef struct cstack{
	int i;
	char carr[MAXI];
} cstack;

void cinit(cstack* t);

void cpush(cstack* t, char c);

char cpop(cstack* t);

int cisfull(cstack *t);

int cisempty(cstack *t);

char* ctop(cstack *t);
