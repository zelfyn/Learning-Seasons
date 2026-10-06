#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void bisection(
    double &a, double &b, double &c, 
    double &hasilA, double &hasilB, double &hasilC,
    double koefA, double koefB, double koefC, double koefD
) {
    hasilA = (koefA * pow(a, 3)) + (koefB * pow(a, 2)) - (koefC * a) - koefD;
    hasilB = (koefA * pow(b, 3)) + (koefB * pow(b, 2)) - (koefC * b) - koefD; 

    cout << left << fixed << setprecision(5);
    cout << setw(10) << a;
    cout << setw(10) << b;
    cout << setw(10) << hasilA;
    cout << setw(10) << hasilB;
    
    c = (a + b) / 2;
    hasilC = (koefA * pow(c, 3)) + (koefB * pow(c, 2)) - (koefC * c) - koefD;

    cout << setw(10) << c;
    cout << setw(10) << hasilC << endl;

    if (hasilA * hasilC > 0) {
        a = c;
    } else {
        b = c;
    }
}

void menuBiseksi() {
    double a, b, c, hasilA, hasilB, hasilC, iterasi, error, koefA, koefB, koefC, koefD;
    
    cout << "\n=== Menghitung Akar dengan Metode Biseksi ===" << endl;
    cout << "F(x) = [A]x^(3) + [B]x^(2) - [C]x - [D]" << endl;
    cout << "Inputkan Koefisien A : "; cin >> koefA;
    cout << "Inputkan Koefisien B : "; cin >> koefB;
    cout << "Inputkan Koefisien C : "; cin >> koefC;
    cout << "Inputkan Koefisien D : "; cin >> koefD;

    cout << "\nBerikut adalah fungsi persamaan yang dipakai : " << endl;
    cout << "F(x) = " << koefA << "x^(3) + " << koefB << "x^(2) - " << koefC << "x - " << koefD << endl; 

    cout << "Masukkan Nilai tebakan awal (a) = "; cin >> a;
    cout << "Masukkan Nilai tebakan akhir (b)= "; cin >> b;
    cout << "Masukkan Nilai iterasi = "; cin >> iterasi;
    cout << "Masukkan Batas Error = "; cin >> error;

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << left; 
    cout << setw(10) << "a" 
         << setw(10) << "b" 
         << setw(10) << "f(a)" 
         << setw(10) << "f(b)" 
         << setw(10) << "c" 
         << setw(10) << "f(c)" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 0; i <= iterasi; i++) {
        bisection(a, b, c, hasilA, hasilB, hasilC, koefA, koefB, koefC, koefD);
        
        if (abs(hasilC) <= error) {
            cout << "\nAkar ditemukan pada c = " << c << " (Toleransi error terpenuhi)" << endl;
            break;
        }
    } 
}

double fungsiTabel(double x, double koefA, double koefB, double koefC, double koefD) {
    return (koefA * pow(x, 3)) + (koefB * pow(x, 2)) - (koefC * x) - koefD;
}

void menuTabel() {
    double a, b, h, x, koefA, koefB, koefC, koefD;
    int total_step;

    cout << "\n=== Menghitung Akar dengan Metode Tabel ===" << endl;
    cout << "F(x) = [A]x^(3) + [B]x^(2) - [C]x - [D]" << endl;
    cout << "Inputkan Koefisien A : "; cin >> koefA;
    cout << "Inputkan Koefisien B : "; cin >> koefB;
    cout << "Inputkan Koefisien C : "; cin >> koefC;
    cout << "Inputkan Koefisien D : "; cin >> koefD;

    cout << "\nBerikut adalah fungsi persamaan yang dipakai : " << endl;
    cout << "F(x) = " << koefA << "x^(3) + " << koefB << "x^(2) - " << koefC << "x - " << koefD << endl; 

    cout << "\n=== Tentukan Nilai Fungsi===" << endl;
    cout << "Batas bawah: "; cin >> a;
    cout << "Batas atas : "; cin >> b;
    cout << "Step H     : "; cin >> h;

    if (h == 0) {
        cout << "Error: Step (h) tidak boleh 0!" << endl;
        return;
    }

    total_step = round((b - a) / h);

    cout << "\n-------------------------------------" << endl;
    for (int i = 0; i <= total_step; i++) {
        x = a + (i * h);
        cout << "x = " << left << setw(8) << x << " | f(x) = " << fungsiTabel(x, koefA, koefB, koefC, koefD) << endl;
    }
    cout << "-------------------------------------" << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n==================================" << endl;
        cout << "          Pilihan Metode           " << endl;
        cout << "==================================" << endl;
        cout << "1. Metode Biseksi" << endl;
        cout << "2. Tabulasi Fungsi" << endl;
        cout << "3. Fungsi Lain" << endl;
        cout << "4. Fungsi Lain" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuBiseksi();
                break;
            case 2:
                menuTabel();
                break;
            case 3:
                cout << "Fungsi Lain Menyusul" << endl;
                break;
            case 4:
                cout << "Fungsi Lain Menyusul" << endl;
                break;
            case 5:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}