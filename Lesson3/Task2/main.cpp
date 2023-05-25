#include <iostream>
#include <future>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

void print(const int& i)
{
    cout << i << " ";
}

void parallelFor_each(vector<int>::iterator begin, vector<int>::iterator end, void (&func)(const int&))
{
    unsigned int const length = distance(begin, end);
    unsigned int const max_chunk_size = 25;
    if(length <= max_chunk_size)
    {
        for_each(begin, end, func);
    }
    else
    {
        vector<int>::iterator midPoint = begin;
        advance(midPoint, length / 2);
        auto first = async(ref(parallelFor_each), begin, midPoint, ref(func));
        parallelFor_each(midPoint, end, func);
    }
}

int main()
{
    vector<int> numbers(100, 2);
    parallelFor_each(numbers.begin(), numbers.end(), print);
}
