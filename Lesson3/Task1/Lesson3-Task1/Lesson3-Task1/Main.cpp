#include <iostream>
#include <future>
#include <algorithm>

using namespace std;

//Нахождение меньшего
void findSmallestPosition(int* arr, int startPosition, int const size, promise<int> pr)
{
	int smallestPosition = startPosition;

	for (int i = startPosition; i < size; ++i)
	{
		if (arr[i] < arr[smallestPosition])
		{
			smallestPosition = i;
		}
	}

	pr.set_value(smallestPosition);
}

//Сортировка выбором
void Sorting(int* arr, int const size)
{
	
	for (int i = 0; i < size; ++i)
	{
		promise<int> f_promise;
		future<int> f_future = f_promise.get_future();

		auto smallestPosition = 
			async(findSmallestPosition, arr, i, size, move(f_promise));
		f_future.wait();
		swap(arr[i], arr[f_future.get()]);
	}
}

int main()
{
	int const size = 10;
	int* arr = new int[size] { 2, 1, 4, 5, 3, 6, 8, 7, 9, 10 };

	cout << "До сортировки: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	Sorting(arr, size);

	cout << "После сортировки: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;

	return 0;
}