#include <iostream>
#include <string>

using namespace std;

bool hanyaAngka(string value) {
    for (int i = 0; i < value.length(); i++) {
        if (value[i] < '0' || value[i] > '9') {
            return false;
        }
    }
    return true;
}

bool memuatAngka(string value) {
    for (int i = 0; i < value.length(); i++) {
        if (value[i] >= '0' && value[i] <= '9') {
            return true;
        }
    }
    return false;
}

bool validasiNama(string nama) {
    if (memuatAngka(nama)) {
        return false;
    }
    return true;
}

bool validasiNPM(string npm) {
    if (hanyaAngka(npm) == false) {
        return false;
    }
    if (npm.length() != 11) {
        return false;
    }
    return true;
}

int main() {
    string npm, nama, whatsapp;

    cout << "==============[ Input Data Mahasiswa ]==============" << endl;

    while (true) {
        cout << "Masukkan Nama Lengkap anda : ";
        getline(cin, nama);
        if (validasiNama(nama)) {
            break;
        } else {
            cout << "-> Error: Nama tidak boleh memuat angka!" << endl;
        }
    }

    while (true) {
        cout << "Masukkan NPM : ";
        cin >> npm;
        if (validasiNPM(npm)) {
            break;
        } else {
            cout << "-> Error: NPM tidak valid (harus 11 digit angka)!" << endl;
        }
    }

    while (true) {
        cout << "Masukkan Nomor Whatsapp : ";
        cin >> whatsapp;
        if (hanyaAngka(whatsapp)) {
            break;
        } else {
            cout << "-> Error: Nomor Whatsapp harus berupa angka!" << endl;
        }
    }

    if (npm[1] == '9') {
        npm[0] = npm[0] + 1;
        npm[1] = '0';
    } else {
        npm[1] = npm[1] + 1;
    }

    string viewGabungan = npm + "_" + nama + "_" + whatsapp;

    cout << "\n==============[ Hasil View ]==============" << endl;
    cout << "View 1 (Terpisah):" << endl;
    cout << "NPM (Manipulasi) : " << npm << endl;
    cout << "Nama Lengkap     : " << nama << endl;
    cout << "Nomor Whatsapp   : " << whatsapp << endl;
    
    cout << "\nView 2 (Gabungan):" << endl;
    cout << viewGabungan << endl;

    cout << "====================================================" << endl;
    cout << "Program Created by Zuniar Hamid Rahman (aka Zelfyn)" << endl;
    cout << "====================================================" << endl;

    return 0;
}