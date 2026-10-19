#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double fungsi(double x, double koefA, double koefB, double koefC, double koefD) {
    return (koefA * pow(x, 3)) + (koefB * pow(x, 2)) - (koefC * x) - koefD;
}

void bisection(
    double &a, double &b, double &c, 
    double &hasilA, double &hasilB, double &hasilC,
    double koefA, double koefB, double koefC, double koefD
) {
    hasilA = fungsi(a,koefA,koefB,koefC,koefD);
    hasilB = fungsi(b,koefA,koefB,koefC,koefD); 

    cout << left << fixed << setprecision(5);
    cout << setw(10) << a;
    cout << setw(10) << b;
    cout << setw(10) << hasilA;
    cout << setw(10) << hasilB;
    
    c = (a + b) / 2;
    hasilC = fungsi(c,koefA,koefB,koefC,koefD);

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

void menuTabel() {
    double a, b, x, h, koefA, koefB, koefC, koefD;
    int total_step;

    cout << "\n=== Menghitung Akar dengan Metode Tabel ===" << endl;

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
        cout << "x = " << left << setw(8) << x << " | f(x) = " << fungsi(x, koefA, koefB, koefC, koefD) << endl;
    }
    cout << "-------------------------------------" << endl;
}

void menuSecant() {
    double a, b, c, error, koefA, koefB, koefC, koefD;
    int max_iterasi;

    cout << "\n=== METODE SECANT ===" << endl;
    
    cout << "Masukkan tebakan awal 1 (X1)   = "; cin >> a;
    cout << "Masukkan tebakan awal 2 (X2)   = "; cin >> b;
    cout << "Masukkan Batas Toleransi Error = "; cin >> error;
    cout << "Masukkan Maksimum Iterasi      = "; cin >> max_iterasi;

     cout << "\n--------------------------------------------------------------------------------------" << endl;
    cout << left << fixed << setprecision(5);
    cout << setw(9)  << "Iterasi"
         << setw(13) << "x1" 
         << setw(13) << "x2" 
         << setw(13) << "x3" 
         << setw(13) << "f(x1)" 
         << setw(13) << "f(x2)" 
         << setw(13) << "f(x3)" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= max_iterasi; i++) {

        double fx1 = fungsi(a,koefA,koefB,koefC,koefD);
        double fx2 = fungsi(b,koefA,koefB,koefC,koefD);

        c = b - (fx2 * (b - a)) / (fx2 - fx1);

        double fx3 = fungsi(c,koefA,koefB,koefC,koefD);

        cout << setw(9)  << i
             << setw(13) << a
             << setw(13) << b
             << setw(13) << c
             << setw(13) << fx1
             << setw(13) << fx2
             << setw(13) << fx3 << endl;

        if (abs(fx3) <= error) {
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "\nKonvergen tercapai pada iterasi ke-" << i << endl;
            cout << "Akar persamaan didapatkan : x = " << c << endl;
            cout << "Nilai f(x3)               = " << fx3 << " (sudah <= toleransi error " << error << ")" << endl;
            return;
        }

        a = b;
        b = c;
    }

    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "\nTelah mencapai batas iterasi maksimum = " << max_iterasi << endl;

}

double turunanFungsi(double x, double koefA, double koefB, double koefC) {
    return (3 * koefA * pow(x, 2)) + (2 * koefB * x) - koefC;
}

void menuNewton(double koefA, double koefB, double koefC, double koefD) {
    double x0, x1, fx0, f_aksen_x0, error;
    int max_iterasi;

    cout << "\n=== METODE NEWTON-RAPHSON ===" << endl;
    
    cout << "Masukkan tebakan awal (x0)     = "; cin >> x0;
    cout << "Masukkan Batas Toleransi Error = "; cin >> error;
    cout << "Masukkan Maksimum Iterasi      = "; cin >> max_iterasi;

    cout << "\n----------------------------------------------------------------------" << endl;
    cout << left << fixed << setprecision(5);
    cout << setw(10) << "Iterasi"
         << setw(15) << "x0" 
         << setw(15) << "f(x0)" 
         << setw(15) << "f'(x0)" 
         << setw(15) << "x1" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (int i = 1; i <= max_iterasi; i++) {
        fx0 = fungsi(x0, koefA, koefB, koefC, koefD);
        f_aksen_x0 = turunanFungsi(x0, koefA, koefB, koefC);

        if (f_aksen_x0 == 0.0) {
            cout << "Dihentikan: Turunan f'(x0) bernilai 0 (Terjadi pembagian dengan nol)." << endl;
            return;
        }

        x1 = x0 - (fx0 / f_aksen_x0);

        cout << setw(10) << i
             << setw(15) << x0
             << setw(15) << fx0
             << setw(15) << f_aksen_x0
             << setw(15) << x1 << endl;

        double fx1 = fungsi(x1, koefA, koefB, koefC, koefD);
        if (abs(fx1) <= error) {
            cout << "----------------------------------------------------------------------" << endl;
            cout << "\nKonvergen tercapai pada iterasi ke-" << i << endl;
            cout << "Akar persamaan didapatkan : x = " << x1 << endl;
            cout << "Nilai f(x)                = " << fx1 << " (sudah <= toleransi error " << error << ")" << endl;
            return;
        }

        x0 = x1;
    }

    cout << "----------------------------------------------------------------------" << endl;
    cout << "\nPencarian dihentikan. Telah mencapai batas iterasi maksimum = " << max_iterasi << endl;
}

void ubahKoef(double &koefA, double &koefB,
              double &koefC, double &koefD) {

    cout << "\n==================================" << endl;
    cout << "Masukkan Koefisien Fungsi" << endl;
    cout << "F(x) = [A]x^3 + [B]x^2 - [C]x - [D]" << endl;

    cout << "Inputkan Koefisien A: ";
    cin >> koefA;

    cout << "Inputkan Koefisien B: ";
    cin >> koefB;

    cout << "Inputkan Koefisien C: ";
    cin >> koefC;

    cout << "Inputkan Koefisien D: ";
    cin >> koefD;
}

int main() {
    double koefA, koefB, koefC, koefD;
    int pilihan;

    ubahKoef(koefA,koefB,koefC,koefD);

    do {
        cout << "\n==================================" << endl;
        cout << "          Pilihan Metode           " << endl;
        cout << "==================================" << endl;
        cout << "1. Metode Biseksi" << endl;
        cout << "2. Tabulasi Fungsi" << endl;
        cout << "3. Metode Secant" << endl;
        cout << "4. Newton Raphson" << endl;
        cout << "5. Ubah Koefisien Fungsi" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        cout << "\nBerikut adalah fungsi persamaan yang dipakai : " << endl;
        cout << "F(x) = " << koefA << "x^(3) + " << koefB << "x^(2) - " << koefC << "x - " << koefD << endl; 


        switch (pilihan) {
            case 1:
                menuBiseksi();
                break;
            case 2:
                menuTabel();
                break;
            case 3:
                menuSecant();
                break;
            case 4:
                menuNewton(koefA,koefB,koefC,koefD);
                break;
            case 5:
                ubahKoef(koefA,koefB,koefC,koefD);
                break;
            case 6:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}