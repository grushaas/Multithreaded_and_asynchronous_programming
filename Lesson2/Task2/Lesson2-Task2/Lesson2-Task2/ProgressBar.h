#pragma once

class ProgressBar
{
private:
	int barWidth;

public:
	ProgressBar(int calcLength, short x, short y);

	void Start();
};