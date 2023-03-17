#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <Windows.h>
#include <locale.h>
#include "ProgressBar.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

mutex m;

void gotoxy(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD{ x, y }));
}

void CreateTable()
{
	gotoxy(0, 0);
	cout << "#";
	gotoxy(5, 0);
	cout << "id";
	gotoxy(15, 0);
	cout << "Progress Bar";
	gotoxy(35, 0);
	cout << "Time";
}

void Threads(int calcLength, int numThreads, int index)
{
	index += 1;

	gotoxy(0, index);
	cout << index;

	gotoxy(5, index);
	cout << get_id();
	
	gotoxy(15, index);
	auto start = high_resolution_clock::now();
	ProgressBar bar(calcLength, 15, index);
	bar.Start();
	auto end = high_resolution_clock::now();
	duration<double, milli> time = end - start;

	gotoxy(35, index);
	cout << time.count();
}

void Computing(int numThreads, int calcLength)
{
	vector<thread> ths;

	system("CLS");

	CreateTable();

	for (int i = 0; i < numThreads; ++i)
	{
		thread th(Threads, calcLength, numThreads, i);
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

	cout << "������� ���������� �������: ";
	cin >> numThreads;

	cout << "������� ����� ��� �������: ";
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