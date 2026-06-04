#include <iostream>
#include <string>
using namespace std;

// PROSEDUR MENU
void tampilanMenu() {
    cout << "==== Kasir Aksesoris Handphone ====" << endl;
    cout << "PRODUK: " << endl;
    cout << "1. Tempered Glass  : Rp. 100.000" << endl;
    cout << "2. Earphone        : Rp. 85.000" << endl;
    cout << "3. Charger HP      : Rp. 80.000" << endl;
    cout << "4. Kabel Data      : Rp. 20.000" << endl << endl;
}

// PROSEDUR CETAK STRUK
void cetakStruk(string namaBarang, int harga, int kuantitas,
                int diskon, double pajak, double totalTagihan,
                int bayar, double kembali) {

    cout << "\n======= STRUK PEMBELIAN =======" << endl;
    cout << "Tanggal     : " << __DATE__ << endl;
    cout << "Barang      : " << namaBarang << endl;
    cout << "Harga/item  : Rp " << harga << endl;
    cout << "Jumlah      : " << kuantitas << endl;
    cout << "Diskon      : Rp " << diskon << endl;
    cout << "Pajak       : Rp " << pajak << endl;
    cout << "Total       : Rp " << totalTagihan << endl;
    cout << "Bayar       : Rp " << bayar << endl;
    cout << "Kembali     : Rp " << kembali << endl;
    cout << "===============================\n" << endl;
}

// FUNGSI TOTAL BELANJA
int totalBelanja(int harga, int jumlah) {
    return harga * jumlah;
}

// FUNGSI PAJAK (0.5%)
double hitungPajak(int total) {
    return total * 0.005;
}

// FUNGSI TOTAL TAGIHAN
double totalTagihan(int total, int diskon, double pajak) {
    return total - diskon + pajak;
}

int main() {

    int pilihan, jumlah, bayar;
    char ulang;

    do {
        tampilanMenu();

        cout << "Pilih barang (1-4): ";
        cin >> pilihan;

        cout << "Jumlah beli: ";
        cin >> jumlah;

        cout << "Masukkan uang bayar: Rp ";
        cin >> bayar;

        string namaBarang;
        int harga;

        switch (pilihan) {
            case 1:
                namaBarang = "Tempered Glass";
                harga = 100000;
                break;
            case 2:
                namaBarang = "Earphone";
                harga = 85000;
                break;
            case 3:
                namaBarang = "Charger HP";
                harga = 80000;
                break;
            case 4:
                namaBarang = "Kabel Data";
                harga = 20000;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                continue;
        }

        int total = totalBelanja(harga, jumlah);
        int diskon = 0;
        double pajak = hitungPajak(total);
        double totalAkhir = totalTagihan(total, diskon, pajak);
        double kembali = bayar - totalAkhir;

        cetakStruk(namaBarang, harga, jumlah, diskon,
                   pajak, totalAkhir, bayar, kembali);

        cout << "Ingin transaksi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}