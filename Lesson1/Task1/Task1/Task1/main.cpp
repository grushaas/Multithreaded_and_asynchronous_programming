#include <iostream>
#include <thread>

using namespace std;

int clients = 0;

void customers(int maxClients)
{
	for (int i = maxClients; i > 0; i--)
	{
		this_thread::sleep_for(1000ms);
		++clients;
		cout << clients << endl;
	}
	cout << endl;
}

void operators()
{
	do {

		this_thread::sleep_for(2000ms);
		--clients;
		cout << clients << endl;

	} while (clients != 0);
}


int main()
{
	int maxClients = 8;

	std::thread T1(customers, maxClients);
	std::thread T2(operators);

	T1.detach();
	T2.join();
}