#include <iostream>
using namespace std;

struct barang{
    string nama;
    float harga;
    int stok;
}; barang Barang[1000];

int menu, jumlahBarang=0, menuPerbarui, urutanBarang, AscDesc;
char kembali;
void MENU(), tambahBarang(), tampilkanBarang(barang Barang[], int jumlahBarang), cariBarang(), hapusBarang(), kosong();
void menuPerbaruiBarang(), perbaruiBarang(), perbaruiHarga(), menuTampilkanBarang(), swapBarang(barang &a, barang &b);
void menuAscDesc(), ascNama(barang Barang[], int jumlahBarang), descNama(barang Barang[], int jumlahBarang);
void ascHarga(barang Barang[], int jumlahBarang), descHarga(barang Barang[], int jumlahBarang);
void ascStok(barang Barang[], int jumlahBarang), descStok(barang Barang[], int jumlahBarang);

int main(){
    do{
    MENU();
    switch(menu){
        case 1  : tambahBarang();                               break;
        case 2  : if(jumlahBarang>0){menuTampilkanBarang();} 
                  else{kosong();}                               break;
        case 3  : if(jumlahBarang>0){perbaruiBarang();} 
                  else{kosong();}                               break;
        case 4  : if(jumlahBarang>0){cariBarang();} 
                  else{kosong();}                               break;
        case 5  : if(jumlahBarang>0){hapusBarang();} 
                  else{kosong();}                               break;
        default : system("cls");
            cout << "==================\n";
            cout << "| Menu tidak ada |\n";
            cout << "==================\n";                     break;    
        }
        cout << "\nApakah anda ingin kembali ke menu? (y/t) "; cin >> kembali;        
        }while (kembali == 'y' || kembali == 'Y');
}

void MENU(){
    system("cls");
    cout << "============================\n";
    cout << "|           MENU           |\n";
    cout << "============================\n";
    cout << "| 1. Tambah Barang         |\n";
    cout << "| 2. Tampilkan Barang      |\n";
    cout << "| 3. Perbarui Data Barang  |\n";
    cout << "| 4. Cari Barang           |\n";
    cout << "| 5. Hapus Data Barang     |\n";
    cout << "| 6. Data Penjualan        |\n";
    cout << "| 7. Laporan Keuangan      |\n";
    cout << "============================\n";    
    cout << "Pilih menu : "; cin >> menu;      
}

void tambahBarang(){
    system("cls");
    cout << "===================================\n";
    cout << "|          Tambah Barang          |\n";    
    cout << "===================================\n";
    cout << "Nama Barang : ";
    cin >> Barang[jumlahBarang].nama;
    cout << "Harga : ";
    cin >> Barang[jumlahBarang].harga;
    cout << "Stok : ";
    cin >> Barang[jumlahBarang].stok;   
    jumlahBarang = jumlahBarang+1; 
}

void menuTampilkanBarang(){
    system("cls");
    cout << "============================\n";
    cout << "|   Urutkan Berdasarkan:   |\n";
    cout << "============================\n";
    cout << "| 1. Nama                  |\n";
    cout << "| 2. Harga                 |\n";
    cout << "| 3. Stok                  |\n";
    cout << "============================\n";  
    cout << "Pilih menu : "; cin >> urutanBarang;
    menuAscDesc();
}

void menuAscDesc(){
    system("cls");
    cout << "============================\n";
    cout << "|       Urutkan Dari:      |\n";
    cout << "============================\n";
    cout << "| 1. Terkecil ke terbesar  |\n";
    cout << "| 2. Terbesar ke terkecil  |\n";
    cout << "============================\n";  
    cout << "Pilih menu : "; cin >> AscDesc;
    
    if(urutanBarang==1 && AscDesc==1){
        ascNama(Barang, jumlahBarang);
    }else if(urutanBarang==1 && AscDesc==2){
        descNama(Barang, jumlahBarang);
    }else if(urutanBarang==2 && AscDesc==1){
        ascHarga(Barang, jumlahBarang);
    }else if(urutanBarang==2 && AscDesc==2){
        descHarga(Barang, jumlahBarang);
    }else if(urutanBarang==3 && AscDesc==1){
        ascStok(Barang, jumlahBarang);
    }else if(urutanBarang==3 && AscDesc==2){
        descStok(Barang, jumlahBarang);
    }else{
        cout << "==================\n";
        cout << "| Menu tidak ada |\n";
        cout << "==================\n"; 
    }
}

void ascNama(barang Barang[], int jumlahBarang){
    for (int i=0; i<jumlahBarang-1;i++){
        for (int j=0; j<jumlahBarang-1-i; j++){
            if (Barang[j].nama>Barang[j+1].nama){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descNama(barang Barang[], int jumlahBarang){
    for(int i=0; i<jumlahBarang-1; i++){
        for(int j=0; j<jumlahBarang-1-i; j++){
            if(Barang[j].nama<Barang[j+1].nama){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void ascHarga(barang Barang[], int jumlahBarang){
    for (int i=0; i<jumlahBarang-1;i++){
        for (int j=0; j<jumlahBarang-1-i; j++){
            if (Barang[j].harga>Barang[j+1].harga){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descHarga(barang Barang[], int jumlahBarang){
    for(int i=0; i<jumlahBarang-1; i++){
        for(int j=0; j<jumlahBarang-1-i; j++){
            if(Barang[j].harga<Barang[j+1].harga){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void ascStok(barang Barang[], int jumlahBarang){
    for (int i=0; i<jumlahBarang-1;i++){
        for (int j=0; j<jumlahBarang-1-i; j++){
            if (Barang[j].stok>Barang[j+1].stok){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descStok(barang Barang[], int jumlahBarang){
    for(int i=0; i<jumlahBarang-1; i++){
        for(int j=0; j<jumlahBarang-1-i; j++){
            if(Barang[j].stok<Barang[j+1].stok){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void tampilkanBarang(barang Barang[], int jumlahBarang){
    system("cls");
    cout << "====================================\n";
    cout << "|           Daftar Barang          |\n";    
    cout << "====================================\n";
    for(int j=0; j<jumlahBarang; j++){
        cout << "Nama Barang : " << Barang[j].nama << endl;
        cout << "Harga       : " << Barang[j].harga << endl;
        cout << "Stok        : " << Barang[j].stok << endl;
        cout << "------------------------------------" << endl;
    }
}

void swapBarang(barang &a, barang &b){
    barang temp = a;
    a = b;
    b = temp;
}

void cariBarang(){
    system("cls");
    string namaBarang;
    int index = -1;
    bool ada = false;

    cout << "Nama barang : ";
    cin >> namaBarang;

    for(int j=0; j<jumlahBarang; j++){
        if(Barang[j].nama == namaBarang){
            ada = true;
            index = j;
            break;
        }
    }

    if(ada){
        system("cls");
        cout << "Nama Barang : " << Barang[index].nama << endl;
        cout << "Harga       : " << Barang[index].harga << endl;
        cout << "Stok        : " << Barang[index].stok << endl;
    }else{
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";}  
}

void menuPerbaruiBarang(){
    system("cls");
    cout << "====================================\n";
    cout << "| Pilih Data yang Ingin Diperbarui |\n";
    cout << "====================================\n";
    cout << "| 1. Harga                         |\n";
    cout << "| 2. Stok                          |\n";
    cout << "====================================\n";   
    cout << "Pilih menu : "; cin >> menuPerbarui;    
}

void perbaruiHarga(){
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang         : ";
    cin >> namaBarang;
    for(j=0; j<jumlahBarang; j++){
        if(namaBarang == Barang[j].nama){
            ada = true;
            index = j;
        }
    }
    if(ada){
        float hargaBaru;
        cout << "Masukkan harga baru : ";
        cin >> hargaBaru;
        Barang[index].harga = hargaBaru;
        cout << "============================================\n";
        cout << "---------Harga berhasil diperbarui!---------\n";
    }else{
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";}   
}

void perbaruiStok(){
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang        : ";
    cin >> namaBarang;
    for(j=0; j<jumlahBarang; j++){
        if(namaBarang == Barang[j].nama){
            ada = true;
            index = j;
        }
    }
    if(ada){
        int stokBaru;
        cout << "Masukkan stok baru : ";
        cin >> stokBaru;
        Barang[index].stok = stokBaru;
        cout << "============================================\n";
        cout << "---------Stok berhasil diperbarui!----------\n";
    }else{
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";}   
}

void perbaruiBarang(){
    menuPerbaruiBarang();
    switch(menuPerbarui){
        case 1  : perbaruiHarga(); break;
        case 2  : perbaruiStok();  break;        
        default : system("cls");
            cout << "==================\n";
            cout << "| Menu tidak ada |\n";
            cout << "==================\n";
        break;  
    }
}

void hapusBarang(){
    system("cls");
    string namaBarang;
    int j, index;
    bool ada = false;
    cout << "Nama barang : ";
    cin >> namaBarang;
    for(j=0; j<jumlahBarang; j++){
        if(namaBarang == Barang[j].nama){
            ada = true;
            index = j;
            break;
        }
    }
    if(ada){
        for (int k=index; k<jumlahBarang-1; k++){
            Barang[k] = Barang[k+1];
        }
        jumlahBarang--; 
        cout << "============================================\n";
        cout << "-------Data barang berhasil dihapus!--------\n";
    }else{
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";
    }
}

void kosong(){
    system("cls");
    cout << "===============================\n";
    cout << "| Anda belum menambahkan data |\n";
    cout << "===============================\n";
}