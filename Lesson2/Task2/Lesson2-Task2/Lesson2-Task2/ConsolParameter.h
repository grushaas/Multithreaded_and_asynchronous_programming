#pragma once
#include <Windows.h>
#include <chrono>
#include <iostream>

class consoleParameter
{
public:
	static void setPosition(int x, int y)
	{
		COORD point;
		point.X = x;
		point.Y = y;
		SetConsoleCursorPosition(hStdOut, point);
	}

private:
	static HANDLE hStdOut;
};

HANDLE consoleParameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);