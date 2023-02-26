#include "ProgressBar.h"
#include <iostream>
#include <Windows.h>

using namespace std;

ProgressBar::ProgressBar(int calcLength, double speed) : barWidth(calcLength), speed(speed)
{

}

void ProgressBar::Start()
{
	double progress = 0.0;
	while (progress < 1.0)
	{
		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i)
		{
			if (i < pos)
			{
				cout << "-";
			}
			else if (i == pos)
			{
				cout << ">";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "]" << "\r";
		cout.flush();

		progress += speed;
	}
	cout << endl;
}