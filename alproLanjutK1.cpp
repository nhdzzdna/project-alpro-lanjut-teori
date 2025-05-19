#include <iostream>
using namespace std;

struct id{
    string huruf;
    int angka;
};

struct barang
{
    string nama;
    float harga;
    int stok;
    struct id idBarang;
    int kategori;
    int rak;
    string Kategori;
};

barang Barang[1000];

int menu, pilihkategori, jumlahBarang = 0, menuPerbarui, urutanBarang, AscDesc;
char kembali;
void MENU(), pilihKategori(), tambahBarang(), tampilkanBarang(barang Barang[], int jumlahBarang), cariBarang(), hapusBarang(), kosong();
void menuPerbaruiBarang(), perbaruiBarang(), perbaruiNama(), perbaruiRak(), menuTampilkanBarang(), swapBarang(barang &a, barang &b);
void menuAscDesc(), ascNama(barang Barang[], int jumlahBarang), descNama(barang Barang[], int jumlahBarang);
void ascID(barang Barang[], int jumlahBarang), descID(barang Barang[], int jumlahBarang);
void ascStok(barang Barang[], int jumlahBarang), descStok(barang Barang[], int jumlahBarang);
void ascKategori(barang Barang[], int jumlahBarang), descKategori(barang Barang[], int jumlahBarang), ascRak(barang Barang[], int jumlahBarang), descRak(barang Barang[], int jumlahBarang);



int main()
{
    do
    {
        MENU();
        switch (menu)
        {
        case 1:
            tambahBarang();
            break;
        case 2:
            if (jumlahBarang > 0)
            {
                menuTampilkanBarang();
            }
            else
            {
                kosong();
            }
            break;
        case 3:
            if (jumlahBarang > 0)
            {
                perbaruiBarang();
            }
            else
            {
                kosong();
            }
            break;
        case 4:
            if (jumlahBarang > 0)
            {
                cariBarang();
            }
            else
            {
                kosong();
            }
            break;
        case 5:
            if (jumlahBarang > 0)
            {
                hapusBarang();
            }
            else
            {
                kosong();
            }
            break;
        default:
            system("cls");
            cout << "==================\n";
            cout << "| Menu tidak ada |\n";
            cout << "==================\n";
            break;
        }
        cout << "\nApakah anda ingin kembali ke menu? (y/t) ";
        cin >> kembali;
    } while (kembali == 'y' || kembali == 'Y');
}

void MENU()
{
    system("cls");
    cout << "============================\n";
    cout << "|           MENU           |\n";
    cout << "============================\n";
    cout << "| 1. Tambah Barang         |\n";
    cout << "| 2. Tampilkan Barang      |\n";
    cout << "| 3. Perbarui Data Barang  |\n";
    cout << "| 4. Cari Barang           |\n";
    cout << "| 5. Hapus Data Barang     |\n";
    cout << "============================\n";
    cout << "Pilih menu : ";
    cin >> menu;
}

void tambahBarang()
{
    system("cls");
    cout << "===================================\n";
    cout << "|          Tambah Barang          |\n";
    cout << "===================================\n";
    cout << "Nama Barang : ";
    cin >> Barang[jumlahBarang].nama;
    cout << "Stok        : ";
    cin >> Barang[jumlahBarang].stok;
    cout << "===================================\n";
    cout << "Kategori Barang" << endl;
    cout << "-----------------------------------\n";
    cout << "1. Makanan" << endl;
    cout << "2. Minuman" << endl;
    cout << "3. Pakaian" << endl;
    cout << "4. Elektronik" << endl;
    cout << "5. Perlengkapan rumah tangga" << endl;
    cout << "6. Lainnya" << endl;
    cout << "-----------------------------------\n";
    cout << "Pilih kategori : ";
    cin >> pilihkategori;
    cout << "===================================\n";
    pilihKategori();
    int rakSementara;
    cout << "Lokasi barang di rak (1-25) :";
    cin >> rakSementara;
    if (rakSementara > 25 || rakSementara < 1)
    {
        cout << "Lokasi rak tidak ada" << endl;
    }else{
        Barang[jumlahBarang].rak = rakSementara;
    }
    cout << "===================================\n";

    if(jumlahBarang<9){
        Barang[jumlahBarang].idBarang.huruf = "A0";
        Barang[jumlahBarang].idBarang.angka = jumlahBarang+1;
    }else{
        Barang[jumlahBarang].idBarang.huruf = "A";
        Barang[jumlahBarang].idBarang.angka = jumlahBarang+1;        
    }    

    jumlahBarang = jumlahBarang+1; 
    cout << "Id   : " << Barang[jumlahBarang-1].idBarang.huruf << Barang[jumlahBarang-1].idBarang.angka << endl;
}

void pilihKategori()
{
    if (pilihkategori == 1)
    {
        Barang[jumlahBarang].kategori = 1;
        Barang[jumlahBarang].Kategori = "Makanan";
    }
    else if (pilihkategori == 2)
    {
        Barang[jumlahBarang].kategori = 2;
        Barang[jumlahBarang].Kategori = "Minuman";
    }
    else if (pilihkategori == 3)
    {
        Barang[jumlahBarang].kategori = 3;
        Barang[jumlahBarang].Kategori = "Pakaian";
    }
    else if (pilihkategori == 4)
    {
        Barang[jumlahBarang].kategori = 4;
        Barang[jumlahBarang].Kategori = "Elektronik";
    }
    else if (pilihkategori == 5)
    {
        Barang[jumlahBarang].kategori = 5;
        Barang[jumlahBarang].Kategori = "Perlengkapan Rumah Tangga";
    }
    else if (pilihkategori == 6)
    {
        Barang[jumlahBarang].kategori = 6;
        Barang[jumlahBarang].Kategori = "Lainnya";
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }
}

void menuTampilkanBarang()
{
    system("cls");
    cout << "============================\n";
    cout << "|   Urutkan Berdasarkan:   |\n";
    cout << "============================\n";
    cout << "| 1. Nama                  |\n";
    cout << "| 2. ID                    |\n";
    cout << "| 3. Stok                  |\n";
    cout << "| 4. Kategori              |\n";
    cout << "| 5. Lokasi Rak            |\n";
    cout << "============================\n";
    cout << "Pilih menu : ";
    cin >> urutanBarang;
    menuAscDesc();
}

void menuAscDesc()
{
    system("cls");
    cout << "============================\n";
    cout << "|       Urutkan Dari:      |\n";
    cout << "============================\n";
    cout << "| 1. Terkecil ke terbesar  |\n";
    cout << "| 2. Terbesar ke terkecil  |\n";
    cout << "============================\n";
    cout << "Pilih menu : ";
    cin >> AscDesc;

    if (urutanBarang == 1 && AscDesc == 1)
    {
        ascNama(Barang, jumlahBarang);
    }
    else if (urutanBarang == 1 && AscDesc == 2)
    {
        descNama(Barang, jumlahBarang);
    }
    else if (urutanBarang == 2 && AscDesc == 1)
    {
        ascID(Barang, jumlahBarang);
    }
    else if (urutanBarang == 2 && AscDesc == 2)
    {
        descID(Barang, jumlahBarang);
    }
    else if (urutanBarang == 3 && AscDesc == 1)
    {
        ascStok(Barang, jumlahBarang);
    }
    else if (urutanBarang == 3 && AscDesc == 2)
    {
        descStok(Barang, jumlahBarang);
    }
    else if (urutanBarang == 4 && AscDesc == 1)
    {
        ascKategori(Barang, jumlahBarang);
    }
    else if (urutanBarang == 4 && AscDesc == 2)
    {
        descKategori(Barang, jumlahBarang);
    }
    else if (urutanBarang == 5 && AscDesc == 1)
    {
        ascRak(Barang, jumlahBarang);
    }
    else if (urutanBarang == 5 && AscDesc == 2)
    {
        descRak(Barang, jumlahBarang);
    }
    else
    {
        cout << "==================\n";
        cout << "| Menu tidak ada |\n";
        cout << "==================\n";
    }
}

void ascNama(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].nama > Barang[j + 1].nama)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descNama(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].nama < Barang[j + 1].nama)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void ascID(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].idBarang.angka > Barang[j + 1].idBarang.angka)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descID(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].idBarang.angka< Barang[j + 1].idBarang.angka)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void ascStok(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].stok > Barang[j + 1].stok)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descStok(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].stok < Barang[j + 1].stok)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}
void ascKategori(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].kategori > Barang[j + 1].kategori)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}
void descKategori(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].kategori < Barang[j + 1].kategori)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}
void ascRak(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].rak > Barang[j + 1].rak)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}
void descRak(barang Barang[], int jumlahBarang)
{
    for (int i = 0; i < jumlahBarang - 1; i++)
    {
        for (int j = 0; j < jumlahBarang - 1 - i; j++)
        {
            if (Barang[j].rak < Barang[j + 1].rak)
            {
                swapBarang(Barang[j], Barang[j + 1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void tampilkanBarang(barang Barang[], int jumlahBarang)
{
    system("cls");
    cout << "====================================\n";
    cout << "|           Daftar Barang          |\n";
    cout << "====================================\n";
    for (int j = 0; j < jumlahBarang; j++)
    {
        cout << "Nama Barang : " << Barang[j].nama << endl;
        cout << "Id          : " << Barang[j].idBarang.huruf << Barang[j].idBarang.angka << endl;  
        cout << "Stok        : " << Barang[j].stok << endl;
        cout << "Kategori    : " << Barang[j].kategori << endl;
        cout << "Rak         : " << Barang[j].rak << endl;
        cout << "------------------------------------" << endl;
    }
}

void swapBarang(barang &a, barang &b)
{
    barang temp = a;
    a = b;
    b = temp;
}

void cariBarang()
{
    system("cls");
    string namaBarang;
    int index = -1;
    bool ada = false;

    cout << "Nama barang : ";
    cin >> namaBarang;

    for (int j = 0; j < jumlahBarang; j++)
    {
        if (Barang[j].nama == namaBarang)
        {
            ada = true;
            index = j;
            break;
        }
    }

    if (ada)
    {
        system("cls");
        cout << "Nama Barang : " << Barang[index].nama << endl;
        cout << "Id          : " << Barang[index].idBarang.huruf << Barang[index].idBarang.angka << endl;  
        cout << "Stok        : " << Barang[index].stok << endl;
        cout << "Kategori    : " << Barang[index].kategori << endl;
        cout << "Rak         : " << Barang[index].rak << endl;  
    }
    else
    {
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}

void menuPerbaruiBarang()
{
    system("cls");
    cout << "====================================\n";
    cout << "| Pilih Data yang Ingin Diperbarui |\n";
    cout << "====================================\n";
    cout << "| 1. Nama barang                   |\n";
    cout << "| 2. Stok                          |\n";
    cout << "| 3. Kategori                      |\n";
    cout << "| 4. Lokasi rak                    |\n";   
    cout << "====================================\n";
    cout << "Pilih menu : ";
    cin >> menuPerbarui;
}

void perbaruiNama()
{
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang         : ";
    cin >> namaBarang;
    for (j = 0; j < jumlahBarang; j++)
    {
        if (namaBarang == Barang[j].nama)
        {
            ada = true;
            index = j;
        }
    }
    if (ada)
    {
        string namaBaru;
        cout << "Masukkan nama baru : ";
        cin >> namaBaru;
        Barang[index].nama = namaBaru;
        cout << "============================================\n";
        cout << "---------Harga berhasil diperbarui!---------\n";
    }
    else
    {
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}

void perbaruiStok()
{
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang        : ";
    cin >> namaBarang;
    for (j = 0; j < jumlahBarang; j++)
    {
        if (namaBarang == Barang[j].nama)
        {
            ada = true;
            index = j;
        }
    }
    if (ada)
    {
        int stokBaru;
        cout << "Masukkan stok baru : ";
        cin >> stokBaru;
        Barang[index].stok = stokBaru;
        cout << "============================================\n";
        cout << "---------Stok berhasil diperbarui!----------\n";
    }
    else
    {
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}
void perbaruiRak()
{
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang        : ";
    cin >> namaBarang;
    for (j = 0; j < jumlahBarang; j++)
    {
        if (namaBarang == Barang[j].nama)
        {
            ada = true;
            index = j;
        }
    }
    if (ada)
    {
        int rakBaru;
        cout << "Masukkan lokasi rak baru (1-25) : ";
        cin >> rakBaru;
        Barang[index].rak = rakBaru;
        cout << "============================================\n";
        cout << "---------Stok berhasil diperbarui!----------\n";
    }
    else
    {
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}

void perbaruiBarang(){
    menuPerbaruiBarang();
    switch (menuPerbarui)
    {
    case 1:
        perbaruiNama();
        break;
    case 2:
        perbaruiStok();
        break;
    case 3:
        perbaruiRak();
        break;
    default:
        system("cls");
        cout << "==================\n";
        cout << "| Menu tidak ada |\n";
        cout << "==================\n";
        break;
    }
}

void hapusBarang()
{
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang : ";
    cin >> namaBarang;
    for (j = 0; j < jumlahBarang; j++)
    {
        if (namaBarang == Barang[j].nama)
        {
            ada = true;
            index = j;
            break;
        }
    }
    if (ada)
    {
        for (int k = index; k < jumlahBarang - 1; k++)
        {
            Barang[k] = Barang[k + 1];
        }
        jumlahBarang--;
        cout << "============================================\n";
        cout << "-------Data barang berhasil dihapus!--------\n";
    }
    else
    {
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}

void kosong()
{
    system("cls");
    cout << "===============================\n";
    cout << "| Anda belum menambahkan data |\n";
    cout << "===============================\n";
}