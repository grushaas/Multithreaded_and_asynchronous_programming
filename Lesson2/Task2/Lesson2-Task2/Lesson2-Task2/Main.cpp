#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <Windows.h>
#include <locale.h>
#include "ProgressBar.h"
#include "ConsolParametr.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

mutex m;

void CreateTable()
{
	consoleParameter::setPosition(0, 0);
	cout << "#";
	consoleParameter::setPosition(5, 0);
	cout << "id";
	consoleParameter::setPosition(15, 0);
	cout << "Progress Bar";
	consoleParameter::setPosition(35, 0);
	cout << "Time";
}

void Threads(int calcLength, int numThreads, int index)
{
	//m.lock();
	consoleParameter::setPosition(0, index);
	cout << index;

	consoleParameter::setPosition(5, index);
	cout << get_id();

	consoleParameter::setPosition(15, index);
	auto start = high_resolution_clock::now();
	ProgressBar bar(calcLength, 15, index);
	bar.Start();
	auto end = high_resolution_clock::now();
	duration<double, milli> time = end - start;

	consoleParameter::setPosition(35, index);
	cout << time.count();
	//m.unlock();
}

void Computing(int numThreads, int calcLength)
{
	vector<thread> ths;

	system("CLS");

	CreateTable();

	for (int i = 0; i < numThreads; ++i)
	{
		thread th(Threads, calcLength, numThreads, i + 1);
		ths.push_back(move(th));
	}

	for (int i = 0; i < numThreads; ++i)
	{
		ths[i].join();
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