#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak format hasil laporan akhir ke layar
void cetakLaporan(int jmlData, int total, int nilaiMaks, float avg) {
    cout << "============[ Hasil Laporan ]============" << endl;
    cout << "Jumlah Data ; " << jmlData << endl;
    cout << "Total Nilai : " << total << endl;
    cout << "=========================================" << endl;
    cout << "Rata Rata Nilai : " << avg << endl;
    cout << "Nilai Maksimum : " << nilaiMaks << endl;
    cout << "=========================================" << endl;
}

// Fungsi utama tempat program mulai berjalan
int main() {
    int total = 0, jmlData, nilaiMaks; 
    float avg;
    
    // Meminta input jumlah data dari user (harus lebih dari 0)
    while (true) { 
        cout << "=========================================" << endl;
        cout << "Masukkan Jumlah Data yang ingin di input : ";
        cin >> jmlData;

        if (jmlData == 0) { 
            cout << "MINIMAL JUMLAH DATA YANG DIMASUKKAN ADALAH 1" << endl;
        } else {
            break;
        }
    }

    // Membuat array dinamis (vector) dengan ukuran jmlData + 1 (indeks 0 diabaikan)
    vector<int> nilai(jmlData + 1); 

    // Proses input nilai, hitung total, dan cari nilai maksimal
    for (int i = 1; i <= jmlData; i++) {
        cout << "Masukan Nilai ke " << (i) << " : ";
        cin >> nilai[i];

        total += nilai[i]; // Menjumlahkan semua nilai yang masuk

        // Menentukan nilai paling besar (maksimal)
        if (i == 1){
            nilaiMaks = nilai[i]; // Data ke-1 jadi patokan awal
        } else if (nilai[i] > nilaiMaks) {
            nilaiMaks = nilai[i]; // Ganti patokan jika ada yang lebih besar
        }
    }

    // Hitung rata-rata dan panggil fungsi cetak laporan
    avg = total / jmlData;
    cetakLaporan(jmlData, total, nilaiMaks, avg);
    cout << endl;
    
    return 0;
}