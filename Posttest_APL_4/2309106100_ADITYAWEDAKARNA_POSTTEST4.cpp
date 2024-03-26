#include <iostream>
#include <string>

using namespace std;

struct Ability {
    string name;
    string description;
};

struct Hero {
    string nama;
    string role;
    Ability ability;
};

const int MAX_HERO = 30;

void displayMenu() {
    cout << "\nMenu:\n"
         << "1. Lihat List Hero\n"
         << "2. Tambah Hero\n"
         << "3. Update Hero\n"
         << "4. Hapus Hero\n"
         << "0. Keluar\n";
}

void lihatListHero(const Hero list_hero[], int size) {
    if (size == 0) {
        cout << "\nTidak ada hero dalam list.\n";
        return;
    }
    cout << "\nList Hero:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Nama: " << list_hero[i].nama << ", Role: " << list_hero[i].role << endl;
        cout << "Ability: " << list_hero[i].ability.name << " - " << list_hero[i].ability.description << endl;
    }
}

void tambahHero(Hero list_hero[], int& size) {
    if (size < MAX_HERO) {
        Hero hero;
        cout << "\nMasukkan nama hero: ";
        cin.ignore();
        getline(cin, hero.nama);

        cout << "Masukkan role hero: ";
        getline(cin, hero.role);

        cout << "Masukkan alasan meta:\n";
        cout << "alasan meta" << endl;
        cout << "Deskripsi: ";
        getline(cin, hero.ability.description);

        hero.ability.name = "meta karna";

        list_hero[size] = hero;
        size++;
        cout << "Hero berhasil ditambahkan\n";
    } else {
        cout << "Jumlah hero telah mencapai batas maksimum.\n";
    }
}

void updateHero(Hero list_hero[], int size) {
    if (size == 0) {
        cout << "\nTidak ada hero dalam list untuk diupdate.\n";
        return;
    }
    string target_nama;
    cout << "\nMasukkan nama hero yang ingin diupdate: ";
    cin.ignore();
    getline(cin, target_nama);

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (list_hero[i].nama == target_nama) {
            cout << "Masukkan nama hero baru: ";
            getline(cin, list_hero[i].nama);

            cout << "Masukkan role hero baru: ";
            getline(cin, list_hero[i].role);

            cout << "Masukkan alasan meta baru:\n";
            cout << "Deskripsi: ";
            getline(cin, list_hero[i].ability.description);

            cout << "Hero berhasil diupdate\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Hero tidak ditemukan.\n";
    }
}

void hapusHero(Hero list_hero[], int& size) {
    if (size == 0) {
        cout << "\nTidak ada hero dalam list untuk dihapus.\n";
        return;
    }
    string target_nama;
    cout << "\nMasukkan nama hero yang ingin dihapus: ";
    cin.ignore();
    getline(cin, target_nama);

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (list_hero[i].nama == target_nama) {
            for (int j = i; j < size - 1; ++j) {
                list_hero[j] = list_hero[j + 1];
            }
            size--;
            found = true;
            cout << "Hero berhasil dihapus!\n";
            break;
        }
    }

    if (!found) {
        cout << "Hero tidak ditemukan.\n";
    }
}

int main() {
    string username = "adit";
    int nim = 100;
    int percobaan_salah = 0;
    Hero list_hero[MAX_HERO];
    int size = 0;

    while (percobaan_salah < 3) {
        string input_username;
        int input_nim;

        cout << "Masukkan username: ";
        cin >> input_username;

        cout << "Masukkan nim: ";
        cin >> input_nim;

        if (input_username == username && input_nim == nim) {
            cout << "Login berhasil\n";

            int pilihan;
            do {
                displayMenu();
                cout << "Pilih aksi (0-4): ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        lihatListHero(list_hero, size);
                        break;
                    case 2:
                        tambahHero(list_hero, size);
                        break;
                    case 3:
                        updateHero(list_hero, size);
                        break;
                    case 4:
                        hapusHero(list_hero, size);
                        break;
                    case 0:
                        cout << "Keluar dari program.\n";
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                        break;
                }
            } while (pilihan != 0);

            break;
        } else {
            percobaan_salah++;
            int sisa_percobaan = 3 - percobaan_salah;
            cout << "Login gagal. Sisa percobaan: " << sisa_percobaan << endl;

            if (percobaan_salah == 3) {
                cout << "Anda telah mencapai batas percobaan.\n";
                break;
            }
        }
    }

    return 0;
}
