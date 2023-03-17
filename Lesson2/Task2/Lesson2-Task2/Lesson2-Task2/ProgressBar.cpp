#include "ProgressBar.h"
#include <iostream>
#include <Windows.h>
#include <mutex>

using namespace std;


ProgressBar::ProgressBar(int calcLength, short x, short y) : barWidth(calcLength)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD{ x, y }));
}

void ProgressBar::Start()
{
	const char symbol = '*';
	for (int i = 0; i < barWidth; ++i)
	{
		cout << symbol;
		Sleep(250);
	}
}