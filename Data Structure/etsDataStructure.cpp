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

string Format (int frmtValue) {
    switch (frmtValue)
    {
    case 1:
        return ".mp4";
    case 2:
        return ".mov";
    case 3:
        return ".avi";
    default:
        return ".mp4";
    }
}

struct renderTask {
    string taskName, format;
    renderTask* next;
};

renderTask* head = NULL;
renderTask* tail = NULL;
renderTask* cur = NULL;

void addRender (string name, int frmtValue) {
    renderTask* newTask = new renderTask();

    newTask->taskName = name;
    newTask->format = Format(frmtValue);
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
        tail = newTask;
    } else {
        tail->next = newTask;
        tail = newTask;
    }

    cout << "[+] Berhasil : Project " << name << " berhasil ditambahkan" << endl;
}

void listQueue () {
    cur = head;

    if (cur == NULL) {
        cout << "[!] Belum ada proiject yang ditambah" << endl;
        return;
    }

    cout << "\n=== Daftar Antrian Render After Effects ===" << endl;
    int nomor = 1;

    while (cur != NULL)
    {
        cout << nomor << ". " << cur->taskName << cur->format << endl;
        cur = cur->next;
        nomor++;
    }
    cout << "===========================================\n" << endl;
}

void renderProces () {
    if (head == NULL){
        cout << "\n[-] Antrian kosong" << endl;
        return;
    }
    
    renderTask* del = head;
    cout << endl;
    timer();
    cout << "\n[v] Rendering SELESAI: '" << del->taskName << endl;

    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete del;
}

int main() {
    int pilihan;
    string namaVideo;
    int pilihanFormat;
    do
    {
        cout << "==============[ Menu Render ]==============" << endl;
        cout << "1. Tambah Antrian Render Baru" << endl;
        cout << "2. Selesaikan 1 Antrian Render" << endl;
        cout << "3. Selesaikan Semua Antrian Render" << endl;
        cout << "4. Tampilkan Daftar Antrian" << endl;
        cout << "5. Stop/Batalkan Render" << endl;
        cout << "6. Keluar Program" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "==========[ Tambahkan Antrian Project ]==========" << endl;
            cout << "Masukkan Nama Video : ";
            getline(cin, namaVideo);

            cout << "Pilih Format Video : " << endl;
            cout << "1. Mp4 || 2. MOV || 3. AVI " << endl;
            cin >> pilihanFormat;

            addRender (namaVideo, pilihanFormat);
            break;
        case 2:
            renderProces();
            break;
        case 3:
            while (head != NULL) {
                cout << head << endl;
                renderProces();
            }
            break;
        case 4:
            listQueue();
            break;
        case 5:
            if (head == NULL) {
                cout << "[!] Antrian sudah kosong." << endl;
            } else {
                while(head != NULL) {
                    renderTask* temp = head;
                    head = head->next;
                    delete temp;
                }
                tail = NULL;
                cout << "[!] Semua antrian render telah dibatalkan." << endl;
            }
            break;
        default:
            break;
        }
    } while (pilihan != 6);
    
    return 0;
}