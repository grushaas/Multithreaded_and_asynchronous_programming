#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <Windows.h>
#include <locale.h>
#include "ProgressBar.h"

using namespace std;

void Threads(int calcLength, int numberThread)
{
	cout << numberThread << " ";
	
	ProgressBar bar(calcLength, 0.005);
	bar.Start();
}

void Computing(int numThreads, int calcLength)
{
	cout << "#    id     Progress Bar    Time" << endl;
	for (int i = 0; i < numThreads; ++i)
	{
		thread th(Threads, calcLength, i);
		th.join();
	}
}

void Start()
{
	int numThreads = 0;
	int calcLength = 0;

	cout << "¬ведите количество потоков: ";
	cin >> numThreads;

	cout << "¬ведите длину дл€ расчета: ";
	cin >> calcLength;
	Computing(numThreads, calcLength);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "russian");

	Start();
}