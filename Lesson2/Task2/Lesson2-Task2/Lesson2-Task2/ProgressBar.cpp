#include "ProgressBar.h"
#include <iostream>
#include <Windows.h>
#include "ConsolParameter.h"

using namespace std;



ProgressBar::ProgressBar(int calcLength, int x, int y)
	: barWidth(calcLength),
	posX(x),
	posY(y) 
{}

void ProgressBar::Start()
{
	const char symbol = '*';
	for (int i = posX; i < barWidth + posX; ++i)
	{
		this_thread::sleep_for(250ms);
		
		//m.lock();
		consoleParameter::setPosition(i, posY);
		cout << symbol;
		//m.unlock();
	}
}
HANDLE consoleParameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);