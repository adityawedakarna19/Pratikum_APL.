#include <iostream>
#include <string>
#include <cstdlib> // Untuk std::cin.ignore() dan std::cin.getline()

using namespace std;

const int MAX_HERO = 30; // Ditempatkan di luar fungsi main agar dapat diakses oleh fungsi lainnya

struct Hero {
    string nama;
    string role;
};

void displayMenu() {
    cout << "\nMenu:\n"
         << "1. Lihat List Hero\n"
         << "2. Tambah Hero\n"
         << "3. Update Hero\n"
         << "4. Hapus Hero\n"
         << "5. Quick Sort (Ascending)\n"
         << "6. Selection Sort (Ascending)\n"
         << "7. Merge Sort (Descending)\n"
         << "8. Interpolation Search\n"
         << "9. Binary Search\n"
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

void quickSort(Hero arr[], int low, int high);
int partition(Hero arr[], int low, int high);

void quickSort(Hero arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(Hero arr[], int low, int high) {
    Hero pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].nama <= pivot.nama) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void selectionSort(Hero arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nama < arr[min_index].nama) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

void merge(Hero arr[], int l, int m, int r);

void merge(Hero arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Hero L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama >= R[j].nama) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Hero arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int interpolationSearch(const Hero list_hero[], int size, const string& target);

int interpolationSearch(const Hero list_hero[], int size, const string& target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= list_hero[low].nama && target <= list_hero[high].nama) {
        if (low == high) {
            if (list_hero[low].nama == target)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (list_hero[high].nama.compare(list_hero[low].nama))) * (target.compare(list_hero[low].nama)));

        if (list_hero[pos].nama == target)
            return pos;

        if (list_hero[pos].nama < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int binarySearch(const Hero list_hero[], int size, const string& target);

int binarySearch(const Hero list_hero[], int size, const string& target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (list_hero[mid].nama == target)
            return mid;
        else if (list_hero[mid].nama < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    Hero list_hero[MAX_HERO];
    int size = 0;
    int choice;
    string target; // Variabel target dideklarasikan di luar switch statement

    do {
        displayMenu();
        cout << "\nPilihan Anda: ";
        cin >> choice;

        switch (choice) {
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
            case 5:
                quickSort(list_hero, 0, size - 1);
                cout << "\nList Hero setelah diurutkan dengan Quick Sort (Ascending):\n";
                lihatListHero(list_hero, size);
                break;
            case 6:
                selectionSort(list_hero, size);
                cout << "\nList Hero setelah diurutkan dengan Selection Sort (Ascending):\n";
                lihatListHero(list_hero, size);
                break;
            case 7:
                mergeSort(list_hero, 0, size - 1);
                cout << "\nList Hero setelah diurutkan dengan Merge Sort (Descending):\n";
                lihatListHero(list_hero, size);
                break;
            case 8: {
                cout << "\nMasukkan nama hero yang ingin dicari: ";
                cin.ignore();
                getline(cin, target);
                int result = interpolationSearch(list_hero, size, target);
                if (result != -1)
                    cout << "Hero ditemukan di indeks ke-" << result << endl;
                else
                    cout << "Hero tidak ditemukan.\n";
                break;
            }
            case 9: {
                cout << "\nMasukkan nama hero yang ingin dicari: ";
                cin.ignore();
                getline(cin, target);
                int result = binarySearch(list_hero, size, target);
                if (result != -1)
                    cout << "Hero ditemukan di indeks ke-" << result << endl;
                else
                    cout << "Hero tidak ditemukan.\n";
                break;
            }
            case 0:
                cout << "\nProgram selesai.\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}
