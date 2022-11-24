#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace std::chrono;

//Сложение векторов
void AdditionVectors(vector<int> vec1, vector<int> vec2)
{
	vector<int> result(vec1.size());
	int i = 0;
	while (i != vec1.size())
	{
		result[i] = vec1[i] + vec2[i];
		++i;
	}
}

//Заполнение рандомными числами в вектор
void RandomFilling(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int value = 1 + rand() % 50;
		vec[i] = value;
	}
}

int main()
{
	// Вектора для сложения
	vector<int> vec1(1000);
	vector<int> vec2(1000);
	vector<int> vec3(10000);
	vector<int> vec4(10000);
	vector<int> vec5(100000);
	vector<int> vec6(100000);
	vector<int> vec7(1000000);
	vector<int> vec8(1000000);
	vector<vector<int>> vectors = { vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8 };

	//Итоговое время
	double resultTime;
	vector<double> resultTimes;

	// Заполнение векторов
	for (int i = 0; i < vectors.size(); ++i)
	{
		RandomFilling(vectors[i]);
	}

	// 1 поток
	
	int count = 0;
	int max = vectors.size();
	while (count != max);
	{
		auto start = chrono::high_resolution_clock::now();
		vector<int> vec1 = vectors[count];
		vector<int> vec2 = vectors[count + 1];
		thread T1(AdditionVectors, vec1, vec2);
		T1.join();
		auto end = chrono::high_resolution_clock::now();
		duration<double, milli> resultTime = end - start;
		resultTimes[count] = resultTime.count();
		
		count += 2;
	}

	cout << resultTimes[0] << endl;
	//cout << resultTimes[1] << endl;
	//cout << resultTimes[2] << endl;
}