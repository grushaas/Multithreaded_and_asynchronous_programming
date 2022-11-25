#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>

using namespace std;

atomic<int> clientsAtomic = 0;
mutex m;

void customers(int maxClients)
{
	for (int i = maxClients; i > 0; i--)
	{
		this_thread::sleep_for(500ms);
		int clients = clientsAtomic.load();
		clientsAtomic.store(++clients);
		cout << clientsAtomic.load() << endl;
	}
	cout << endl;
}

void operators()
{
	int clients = 0;
	do 
	{
		this_thread::sleep_for(2000ms);
		clients = clientsAtomic.load();
		clientsAtomic.store(--clients);
		cout << clientsAtomic.load() << endl;

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