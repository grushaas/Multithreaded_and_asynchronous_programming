#include "ProgressBar.h"
#include <iostream>
#include <Windows.h>
#include <mutex>

using namespace std;


ProgressBar::ProgressBar(int calcLength, int x, int y)
	: barWidth(calcLength),
	posX(x),
	posY(y) 
{}

void ProgressBar::Start()
{
	const char symbol = '*';
	consoleParameter::setPosition(posX, posY);
	for (int i = 0; i < barWidth; ++i)
	{
		cout << symbol;
		Sleep(250);
	}
}