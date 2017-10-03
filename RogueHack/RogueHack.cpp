// RogueHack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define SCREEN_ROWS 23
#define SCREEN_COLS 60
vector<string> screen;

#define MAP_EMPTY '.'
#define MAP_VWALL '|'
#define MAP_HWALL '='
#define MAP_PLAYER '@'

void initScreen()
{
	string defaultRow = "";
	screen.clear();

	for (int c = 0; c < SCREEN_COLS; c++)
		defaultRow += MAP_EMPTY;

	for (int r = 0; r < SCREEN_ROWS; r++)
		screen.push_back(defaultRow);
}

void printScreen()
{
	for (int r = 0; r < SCREEN_ROWS; r++)
	{
		cout << screen[r] << endl;
	}
}

void setInfo(int atk, int hp, int gold, int exp, int lvl)
{
	stringstream buffer;

	buffer << "ATK: " << atk << ", HP: " << hp << ", GOLD: " << gold << ", EXP: " << exp << ", LVL: " << lvl;
	screen[SCREEN_ROWS - 1] = buffer.str();
}

void setMap()
{
	for (int r = 0; r < SCREEN_ROWS-1; r++)  //-1 because statInfo takes up the last row
	{
		screen[r][0] = MAP_VWALL;
		screen[r][SCREEN_COLS - 1] = MAP_VWALL;
	}

	for (int c = 0; c < SCREEN_COLS; c++)
	{
		screen[0][c] = MAP_HWALL;
		screen[SCREEN_ROWS - 2][c] = MAP_HWALL;
	}
}

void setPlayer(int r, int c)
{
	screen[r][c] = MAP_PLAYER;
}

int main()
{
	string choice = "";
	int myR = 3;
	int myC = 4;

	while (choice != "q" && choice != "Q")
	{
		initScreen();
		setInfo(15, 100, 0, 10, 1);
		setMap();
		setPlayer(myR, myC);

		printScreen();

		cout << ">> ";
		cin >> choice;

		if (choice == "a")
		{
			myC -= 1;
		}
		else if (choice == "d")
		{
			myC += 1;
		}
		else if (choice == "w")
		{
			myR -= 1;
		}
		else if (choice == "s")
		{
			myR += 1;
		}
	}
	return 0;
}

