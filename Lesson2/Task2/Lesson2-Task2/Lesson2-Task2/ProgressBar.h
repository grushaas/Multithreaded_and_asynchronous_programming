#pragma once
#include "ConsolParameter.h"

class ProgressBar
{
private:
	int barWidth;
	int posX;
	int posY;

public:
	ProgressBar(int calcLength, int x, int y);

	void Start();
};