#include <iostream>

using namespace std;

int main() {
    float tempHasil, Hasil, a, b;
    int op;
    char pilihan;

    cout << "Masukkan Nilai Awal : ";
    cin >> a;
    cout << endl;

    do {
        cout << "Pilih Operator (Tulis Angka 1-4) : \n 1. Penjumlahan \n 2. Pengurangan \n 3. Perkalian \n 4. Pembagian \n";
        cout << "Masukkan Nomor operator : ";
        cin >> op;
        cout << "==========================" << endl;
        cout << endl;
        cout << "Masukkan Nilai Akhir : ";
        cin >> b;
        cout << endl;
        
        switch(op) {
            case 1:
                tempHasil = a + b;
                Hasil =  tempHasil;
                cout << "Hasil Operasi = " << Hasil << endl;
                break;
            case 2:
                tempHasil = a - b;
                Hasil =  tempHasil;
                cout << "Hasil Operasi = " << Hasil << endl;
                break;
            case 3:
                tempHasil = a * b;
                Hasil =  tempHasil;
                cout << "Hasil Operasi = " << Hasil << endl;
                break;
            case 4:
                if (b != 0) {
                    tempHasil = a / b;
                    Hasil =  tempHasil;
                    cout << "Hasil Operasi = " << Hasil << endl;
                } else {
                    cout << "Error: Tidak bisa membagi dengan nol!" << endl;
                }
                break;
            default:
                cout << "Pilihan operasi tidak valid!" << endl;
                break;
        }

        cout << "Apakah ingin melanjutkan operasi? (Y/N)" << endl;
        cin >> pilihan;
        cout << "==========================" << endl;
        a = tempHasil;
        b = 0;

    } while (pilihan == 'y' || pilihan == 'Y');
        cout << "====[ Operasi Selesai, Silahkan run program kembali untuk memulai dari awal }====" << endl;
    
    return 0;
}