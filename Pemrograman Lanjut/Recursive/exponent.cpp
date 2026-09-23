#include <iostream>
using namespace std;

int pangkat(int basis, int n) {
    if (n <= 1) {
        return 1;
    } 

    return basis * pangkat(basis, n - 1);
}

int main() {
    int basis, n;

    cout << "Masukkan Nilai Basis = ";
    cin >> basis;

    cout << "Masukkan Pangkat = ";
    cin >> n;

    cout << "Hasil dari " << basis << "^(" << n << ") adalah " << pangkat(basis, n) << endl;
    return 0;
}