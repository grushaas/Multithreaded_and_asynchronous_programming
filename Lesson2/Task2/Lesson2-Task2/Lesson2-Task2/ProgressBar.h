#pragma once

class ProgressBar
{
private:
	int barWidth;
	double speed;

public:
	ProgressBar(int calcLength, double speed);

	void Start();
};