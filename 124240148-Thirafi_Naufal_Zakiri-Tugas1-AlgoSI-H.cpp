#include <iostream>
using namespace std;

// Buat nyimpen data batalyon
struct Batalyon
{
    int id;
    char namaJenderal[50];
    char tipePasukan[20];
    int jumlahPasukan;
};

Batalyon daftarBatalyon[100]; // Array buat nyimpen daftar batalyon
int jumlahBatalyon = 0;       // Jumlah batalyon yang udah ditambah
int idCounter = 1;            // Biar ID unik tiap batalyon

// Fungsi buat nambah batalyon
void tambahBatalyon()
{
    if (jumlahBatalyon >= 100)
    { // Cek kalo kapasitas penuh
        cout << "Kapasitas batalyon penuh!" << endl;
        return;
    }

    cout << "Input General Name: ";
    cin >> daftarBatalyon[jumlahBatalyon].namaJenderal;

    // Ngecek kalo jenderal udah ada
    for (int i = 0; i < jumlahBatalyon; i++)
    {
        int j = 0, sama = 1;
        while (daftarBatalyon[i].namaJenderal[j] != '\0' && daftarBatalyon[jumlahBatalyon].namaJenderal[j] != '\0')
        {
            if (daftarBatalyon[i].namaJenderal[j] != daftarBatalyon[jumlahBatalyon].namaJenderal[j])
            {
                sama = 0;
                break;
            }
            j++;
        }
        if (sama && daftarBatalyon[i].namaJenderal[j] == '\0' && daftarBatalyon[jumlahBatalyon].namaJenderal[j] == '\0')
        {
            cout << "Error: Jenderal sudah terdaftar!" << endl;
            return;
        }
    }

    cout << "Input Soldier Type (Infantry/Kavaleri/Archer): ";
    cin >> daftarBatalyon[jumlahBatalyon].tipePasukan;

    if (!(daftarBatalyon[jumlahBatalyon].tipePasukan[0] == 'I' ||
          daftarBatalyon[jumlahBatalyon].tipePasukan[0] == 'K' ||
          daftarBatalyon[jumlahBatalyon].tipePasukan[0] == 'A'))
    {
        cout << "Error: Tipe pasukan tidak valid!" << endl;
        return;
    }

    cout << "Input Soldier Qty: ";
    cin >> daftarBatalyon[jumlahBatalyon].jumlahPasukan;

    if (daftarBatalyon[jumlahBatalyon].jumlahPasukan < 1)
    {
        cout << "Error: Jumlah pasukan harus lebih dari 0!" << endl;
        return;
    }

    daftarBatalyon[jumlahBatalyon].id = idCounter++;
    jumlahBatalyon++;
    cout << "Batalyon berhasil ditambahkan!" << endl;

    // Opsi buat balik ke menu atau keluar
    char pilihan;
    cout << "Apakah anda ingin kembali ke log out? (Y/N): ";
    cin >> pilihan;
    if (pilihan == 'Y' || pilihan == 'y')
    {
        exit(0);
    }
}

// Fungsi buat nyari batalyon sesuai nama jenderal
void cariBatalyon()
{
    if (jumlahBatalyon == 0)
    {
        cout << "Tidak ada batalyon yang terdaftar." << endl;
        return;
    }

    char cariNama[50];
    cout << "Nama General yang ingin Anda cari: ";
    cin >> cariNama;

    for (int i = 0; i < jumlahBatalyon; i++)
    {
        int j = 0, sama = 1;
        while (daftarBatalyon[i].namaJenderal[j] != '\0' && cariNama[j] != '\0')
        {
            if (daftarBatalyon[i].namaJenderal[j] != cariNama[j])
            {
                sama = 0;
                break;
            }
            j++;
        }
        if (sama && daftarBatalyon[i].namaJenderal[j] == '\0' && cariNama[j] == '\0')
        {
            cout << "General ditemukan!\nID: " << daftarBatalyon[i].id
                 << "\nNama: " << daftarBatalyon[i].namaJenderal
                 << "\nTipe Pasukan: " << daftarBatalyon[i].tipePasukan
                 << "\nJumlah Pasukan: " << daftarBatalyon[i].jumlahPasukan << endl;

            // Opsi buat balik ke menu atau keluar
            char pilihan;
            cout << "Apakah anda ingin kembali ke log out? (Y/N): ";
            cin >> pilihan;
            if (pilihan == 'Y' || pilihan == 'y')
            {
                exit(0);
            }
            return;
        }
    }
    cout << "General tidak ditemukan." << endl;
}

int main()
{
    int pilihan;
    do
    {
        cout << "\nDaftar Menu\n1. Tambah Batalyon\n2. Cari Batalyon\n3. Keluar\nPilih Menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            cariBatalyon();
            break;
        case 3:
            cout << "Keluar dari program..." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (true);
}
