#include <iostream>
using namespace std;

struct id{
    string huruf;
    int angka;
};

struct barang{
    string nama;
    int stok;
    struct id idBarang;
}; barang Barang[1000];

int menu, jumlahBarang=0, menuPerbarui, urutanBarang, AscDesc;
char kembali;
void MENU(), tambahBarang(), tampilkanBarang(barang Barang[], int jumlahBarang), cariBarang(), hapusBarang(), kosong();
void menuPerbaruiBarang(), perbaruiBarang(), menuTampilkanBarang(), swapBarang(barang &a, barang &b);
void menuAscDesc(), ascNama(barang Barang[], int jumlahBarang), descNama(barang Barang[], int jumlahBarang);
void ascID(barang Barang[], int jumlahBarang), descID(barang Barang[], int jumlahBarang);
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
    cout << "Stok : ";
    cin >> Barang[jumlahBarang].stok;  
    
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

void menuTampilkanBarang(){
    system("cls");
    cout << "============================\n";
    cout << "|   Urutkan Berdasarkan:   |\n";
    cout << "============================\n";
    cout << "| 1. Nama                  |\n";
    cout << "| 2. ID                 |\n";
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

void ascID(barang Barang[], int jumlahBarang){
    for (int i=0; i<jumlahBarang-1;i++){
        for (int j=0; j<jumlahBarang-1-i; j++){
            if (Barang[j].idBarang.angka>Barang[j+1].idBarang.angka){
                swapBarang(Barang[j], Barang[j+1]);
            }
        }
    }
    tampilkanBarang(Barang, jumlahBarang);
}

void descID(barang Barang[], int jumlahBarang){
    for(int i=0; i<jumlahBarang-1; i++){
        for(int j=0; j<jumlahBarang-1-i; j++){
            if(Barang[j].idBarang.angka<Barang[j+1].idBarang.angka){
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
        cout << "Stok        : " << Barang[j].stok << endl;
        cout << "Id          : " << Barang[j].idBarang.huruf << Barang[j].idBarang.angka << endl;      
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
        cout << "Stok        : " << Barang[index].stok << endl;
        cout << "Id          : " << Barang[index].idBarang.huruf << Barang[index].idBarang.angka << endl;  
    }else{
        cout << "============================================\n";
        cout << "----------Barang tidak ditemukan!-----------\n";}  
}

void menuPerbaruiBarang(){
    system("cls");
    cout << "====================================\n";
    cout << "| Pilih Data yang Ingin Diperbarui |\n";
    cout << "====================================\n";
    cout << "| 1. Stok                          |\n";
    cout << "====================================\n";   
    cout << "Pilih menu : "; cin >> menuPerbarui;    
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
        case 1  : perbaruiStok();  break;        
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