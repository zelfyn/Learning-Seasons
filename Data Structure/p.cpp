#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void timer() {
    int time = 0;

    for (int i = 0; i <= 10; i++) {
        cout << "[" << "\033[2G";
        for (int j = 0; j < i; j++) {
            cout << "=";
        }

        for (int j = i; j < 10; j++) {
            cout << " ";
        }

        cout << "]" << time << "%" << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
        time += 10;
    }
    cout << endl;
}

main (){
    timer();
    return 0;
}