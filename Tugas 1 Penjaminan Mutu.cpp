#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double hitungGaji(int jamKerja, double rateNormal, double rateLembur) {
    int jamNormal = 40;
    if (jamKerja <= jamNormal) {
        return jamKerja * rateNormal;
    } else {
        double gajiNormal = jamNormal * rateNormal;
        double gajiLembur = (jamKerja - jamNormal) * rateLembur;
        return gajiNormal + gajiLembur;
    }
}

pair<string, double> statusTabungan(double pemasukan, double pengeluaran) {
    if (pemasukan > pengeluaran) {
        return make_pair("bisa menabung", pemasukan - pengeluaran);
    } else if (pemasukan == pengeluaran) {
        return make_pair("tidak bisa menabung", 0);
    } else {
        return make_pair("cari tambahan", 0);
    }
}

void hitungDanTampilkan(string nama, int jamKerja, double rateNormal, double pengeluaran) {
    double rateLembur = rateNormal * 1.5;
    double gaji = hitungGaji(jamKerja, rateNormal, rateLembur);
    pair<string, double> status = statusTabungan(gaji, pengeluaran);

    cout << fixed << setprecision(2);  // Set format for currency output
    cout << "\nHasil perhitungan untuk " << nama << ":\n";
    cout << "Jam kerja: " << jamKerja << " jam\n";
    cout << "Rate normal: Rp. " << rateNormal << "/jam\n";
    cout << "Pengeluaran: Rp. " << pengeluaran << endl;
    cout << "Gaji: Rp. " << gaji << endl;
    cout << "Status: " << status.first << endl;
    if (status.first == "bisa menabung") {
        cout << "Jumlah yang bisa ditabung: Rp. " << status.second << endl;
    }
    cout << string(40, '-') << endl;  // Print a line of 40 dashes
}

int main() {
    // Kasus John Travolta
    hitungDanTampilkan("John Travolta", 52, 15000, 600000);
    // Beberapa kasus dengan nilai yang lain
    hitungDanTampilkan("Alice", 40, 20000, 750000);
    hitungDanTampilkan("Bob", 45, 18000, 900000);

    return 0;
}
