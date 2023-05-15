#include <iostream>
#include <future>
#include <thread>
#include <vector>

using namespace std;

void addOne(vector<int> vec)
{
    int const size = vec.size();
    int count = 0;
    while(count <= size)
    {
        vec[count] += 1;
        ++count;
    }

    cout << "Done!" << endl;
}

void print(vector<int> vec)
{
    int const size = vec.size();
    for(int i = 0; i < size; ++i)
    {
        cout << vec[i] << " ";
    }
    cout << "Done!" << endl;
}

void asyncDivider(vector<int>::iterator itBegin, vector<int>::iterator itEnd, promise<vector<int>> vec_promise)
{
    vector<int> newVec;
    int maxElements = 5;
    int blocks = (itEnd - itBegin) / maxElements;

    itEnd -= 5;

    for(int i = 0; i < maxElements; ++i)
    {
        int number = *itBegin;
        newVec[i] = number;
    }

    vec_promise.set_value(newVec);
}

void asyncFor_each(vector<int>::iterator itBegin, vector<int>::iterator itEnd, void (&foo)(vector<int> vec))
{
    promise<vector<int>> vec_promise;
    future<vector<int>> vec_future = vec_promise.get_future();
    thread work_thread(asyncDivider, itBegin, itEnd, move(vec_promise));
    vector<int> newVec = vec_future.get();
    work_thread.join();

    foo(newVec);

    return asyncFor_each(itBegin, itEnd, foo);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator itBegin = vec.begin();
    vector<int>::iterator itEnd = vec.end() - 1;

    asyncFor_each(itBegin, itEnd, print);
}