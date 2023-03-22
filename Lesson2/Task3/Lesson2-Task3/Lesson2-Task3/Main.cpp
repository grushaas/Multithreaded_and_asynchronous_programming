#include <iostream>
#include <mutex>
#include <Windows.h>

using namespace std;

class protectedData
{
public:
	protectedData(double value1, char value2, bool value3)
		: dollar(value1),
		key(value2),
		flag(value3) {}

	double dollar;
	char key;
	bool flag;

	mutex dataM;

	void const printData() noexcept
	{
		cout << "Доллар: " << dollar << endl;
		cout << "Ключ: " << key << endl;
		cout << boolalpha << "Флаг: " << flag << endl;
	}
};

void lockSwap(protectedData& data1, protectedData& data2)// lock
{
	lock(data1.dataM, data2.dataM);
	lock_guard<mutex> L1(data1.dataM, adopt_lock);
	lock_guard<mutex> L2(data2.dataM, adopt_lock);

	auto tmp = data1.dollar;
	data1.dollar = data2.dollar;
	data2.dollar = tmp;

	tmp = data1.key;
	data1.key = data2.key;
	data2.key = tmp;

	tmp = data1.flag;
	data1.flag = data2.flag;
	data2.flag = tmp;
}

void scopedLockSwap(protectedData& data1, protectedData& data2)// scoped_lock
{
	scoped_lock lock(data1.dataM, data2.dataM);

	auto tmp = data1.dollar;
	data1.dollar = data2.dollar;
	data2.dollar = tmp;

	tmp = data1.key;
	data1.key = data2.key;
	data2.key = tmp;

	tmp = data1.flag;
	data1.flag = data2.flag;
	data2.flag = tmp;
}

void uniqueLockSwap(protectedData& data1, protectedData& data2)// unique_lock
{
	unique_lock<mutex> lk1(data1.dataM, defer_lock);
	unique_lock<mutex> lk2(data2.dataM, defer_lock);
	lock(lk1, lk2);

	auto tmp = data1.dollar;
	data1.dollar = data2.dollar;
	data2.dollar = tmp;

	tmp = data1.key;
	data1.key = data2.key;
	data2.key = tmp;

	tmp = data1.flag;
	data1.flag = data2.flag;
	data2.flag = tmp;
}

void render(protectedData& data1, protectedData& data2)
{
	cout << "Data1: " << endl;
	data1.printData();
	cout << "Data2: " << endl;
	data2.printData();

	cout << endl;
}

int main()
{
	protectedData data1(78.53, '-', false);
	protectedData data2(43.22, '+', true);
	protectedData data3(12.124, '*', false);
	protectedData data4(84.123, '/', true);
	protectedData data5(940.12, '%', false);
	protectedData data6(1853.12, '#', true);

	//lock
	render(data1, data2);
	lockSwap(data1, data2);
	render(data1, data2);

	//scoped_lock
	render(data3, data4);
	scopedLockSwap(data3, data4);
	render(data3, data4);

	//unique_lock
	render(data5, data6);
	uniqueLockSwap(data5, data6);
	render(data5, data6);
}