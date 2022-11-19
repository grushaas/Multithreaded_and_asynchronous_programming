#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <thread>
#include "Table.h"

using namespace std;
using namespace std::chrono;

void AdditionVectors(vector<int> vec1, vector<int> vec2, double& resultTime)
{
	vector<int> result(500);
	int i = 0;
	auto start = chrono::high_resolution_clock::now();
	while (i != vec1.size())
	{
		result[i] = vec1[i] + vec2[i];
		++i;
	}
	auto end = chrono::high_resolution_clock::now();

	duration<double, milli> time = end - start;
	resultTime = time.count();
}

vector<int> RandomFilling(vector<int>& vec, int NOperations)
{
	for (int i = 0; i < NOperations; ++i)
	{
		int value = 1 + rand() % 50;
		vec[i] = value;
	}

	return vec;
}

int main()
{
	double resultTime = 0;

	vector<int> vec1(500);
	vector<int> vec2(500);
	vector<int> vec3(5000);
	vector<int> vec4(5000);
	vector<int> vec5(50000);
	vector<int> vec6(50000);
	vector<int> vec7(500000);
	vector<int> vec8(500000);

	vec1 = RandomFilling(vec1, 500);
	vec2 = RandomFilling(vec2, 500);
	vec3 = RandomFilling(vec3, 5000);
	vec4 = RandomFilling(vec4, 5000);
	vec5 = RandomFilling(vec5, 50000);
	vec6 = RandomFilling(vec6, 50000);
	vec7 = RandomFilling(vec7, 500000);
	vec8 = RandomFilling(vec8, 500000);

	thread T1(AdditionVectors, vec1, vec2, ref(resultTime));

	cout << resultTime << endl;
}