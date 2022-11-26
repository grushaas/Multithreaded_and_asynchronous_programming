#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void ProgressBar(double progress, double speed)
{
    cout << "Индетификатор потока: " << this_thread::get_id() << endl;

    while (progress < 1.0) {
        int barWidth = 70;

        cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) cout << "=";
            else if (i == pos) cout << ">";
            else cout << " ";
        }
        cout << "] " << int(progress * 100.0) << " %\r";
        cout.flush();

        progress += speed;
    }
    cout << endl;
}

void StartThread(double speed, int NStreams)
{
    for (int i = 0; i < NStreams; ++i)
    {
        cout << "Номер потока: " << i << endl;
        auto start = chrono::high_resolution_clock::now();
        thread T(ProgressBar, 0.0, speed);
        T.join();
        auto end = chrono::high_resolution_clock::now();
        duration<double, milli> time = end - start;

        cout << "Суммарное время: " << time.count() << endl;
        cout << endl;
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);

    StartThread(0.1, 20);
}