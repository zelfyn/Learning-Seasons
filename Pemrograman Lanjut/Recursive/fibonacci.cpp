#include <iostream>
using namespace std;

int fibo(int n, int a = 0, int b = 1) {
    if (n == 0) return a;
    return fibo(n-1, b, a+b);
}

int main() {
    int jmlDeret;
    cout << "Masukkan Jumlah Deret Fibonacci : ";
    cin >> jmlDeret;
    cout << "=====================================" << endl;
     
    for (int i = 0; i <= jmlDeret; i++) {
        cout << fibo(i) << " ";
    }
    
    return 0;
} 