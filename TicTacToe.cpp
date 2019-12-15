// TicTacToe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<ctime>


char player ='x';
char computer = 'o';
char table[9] = {' ',' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' };
bool putChess(char a, int i)
{
	if (table[i] == ' ')
	{
		table[i] = a;
		return 0;
	}
	else
	{
		printf("What the hell?\n");
		return 1;
	}

}

void printTable()
{
	//system("cls");
	int i=0;
	while (i <= 6)
	{
		printf("-----\n");
		printf("%c|%c|%c\n", table[i], table[i+1], table[i+2]);
		i = i + 3;
	}
	printf("-----\n");
}

bool judge(char a)
{
	int i=0;
	while(i<=6)
	{
		if (a == table[i] && table[i] == table[i + 1] && table[i + 1] == table[i + 2])
			return 1;
		i = i + 3;
	}
	for (i = 0; i < 3; i++)
	{
		if (a == table[i] && table[i] == table[i + 3] && table[i + 3] == table[i + 6])
			return 1;
	}
	if (a == table[0] && table[0] == table[4] && table[4] == table[8])
		return 1;
	if (a == table[2] && table[2] == table[4] && table[4] == table[6])
		return 1;
	return 0;
}

void chooseChess()
{
	int i;
	printf("选择想要的棋子\n1:o  2:x\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		player = 'o';
		computer = 'x';
		break;
	case 2:
		player = 'x';
		computer = 'o';
		break;
	default:printf("error!");
	}
}


void computerTurn()
{
	srand((unsigned int)(time(NULL))); //error
	int i = 0;
	int mark = 0;
	for (i = 0; i < 9; i++)
	{
		if (table[i] == ' ')
		{
			putChess(computer, i);
			if (judge(computer))
			{
				mark = 1;
				break;
			}
			else table[i] = ' ';
		}
	}
	if (mark == 0)
	{
		while (1)
		{
			i = rand() % 9;
			if (table[i] == ' ')
			{
				putChess(computer, i);
				break;
			}
		}
	}
}
void playerTurn()
{
	int i;
	printf("you:%c\ncomputer:%c\nyour turn:",player,computer);
	//printTable();
	do
	{
		scanf("%d", &i);
	} while (putChess(player, i));
}
int main()
{
	srand((unsigned int)(time(NULL)));
	int r=0;
	int mark=1;
	chooseChess();
	system("cls");
	r = rand() % 2;
	switch (r)
	{
	case 0:
		while (1)
		{
			playerTurn();
			system("cls");
			printTable();
			if (judge(player))
			{
				//printTable();
				printf("you win!");
				break;
			}
			system("cls");
			computerTurn();
			printTable();
			if (judge(computer))
			{
				//printTable();
				printf("computer win!");
				break;
			}
		}
		break;
	case 1:
		while (1)
		{
			computerTurn();
			printTable();
			if (judge(computer))
			{
				//printTable();
				printf("computer win!");
				break;
			}
			playerTurn();
			system("cls");
			printTable();
			if (judge(player))
			{
				//printTable();
				printf("you win!");
				break;
			}
			system("cls");
		}
		break;
	}
}