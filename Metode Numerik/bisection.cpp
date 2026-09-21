#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void function(double &a, double &b, double &c, double &hasilA, double &hasilB, double &hasilC) {
    cout << left << fixed << setprecision(5);
    cout << setw(10) << a;
    cout << setw(10) << b;
    hasilA = pow(a, 3) + (2 * pow(a, 2)) - (3 * a);
    hasilB = pow(b, 3) + (2 * pow(b, 2)) - (3 * b);
    cout << setw(10) << hasilA;
    cout << setw(10) << hasilB;
    
    c = (a+b) / 2;
    hasilC = pow(c, 3) + (2 * pow(c, 2)) - (3 * c);
    cout << setw(10) << c;
    cout << setw(10) << hasilC << endl;


    if (hasilA * hasilC > 0) 
    {
        a = c;
    } else {
        b = c;
    }
}

int main() {
    double a, b, c, hasilA, hasilB, hasilC, iterasi;
    cout << "Menghitung Akar dengan Metode Biseksi" << endl;
    cout << "Menggunakan fungsi : f(x) = x^(3) + 2x^(2) - 3x" << endl;
    
    cout << "Masukkan Nilai tebakan awal = ";
    cin >> a;
    cout << "Masukkan Nilai tebakan akhir = ";
    cin >> b;
    cout << "Masukkan Nilai iterasi = ";
    cin >> iterasi;

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << left; 
    cout << setw(10) << "a" 
         << setw(10) << "b" 
         << setw(10) << "f(a)" 
         << setw(10) << "f(b)" 
         << setw(10) << "c" 
         << setw(10) << "f(c)" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 0; i <= iterasi; i++){
        function(a,b,c,hasilA,hasilB,hasilC);
    }

    return 0;
}