#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void welcomeScreen() {
    string myText;
    ifstream MyReadFile("src/others/splashScreen.txt");
    while (getline (MyReadFile, myText)) {
    cout << myText << endl;
    }
    MyReadFile.close();
}

void menu() {
    cout << endl;
    cout << "Menu: " << endl;
    cout << "   1.  Input Manual" << endl;
    cout << "   2.  Input Random" << endl;
    cout << "   3.  Help" << endl;
    cout << "   4.  Exit" << endl;
    cout << "input: ";
}

void help() {
    cout << endl;
    cout << "Permainan kartu 24 adalah permainan kartu aritmatika dengan tujuan mencari cara untuk mengubah 4 buah angka random sehingga mendapatkan" << endl;
    cout << "hasil akhir sejumlah 24. Permainan ini menarik cukup banyak peminat dikarenakan dapat meningkatkan kemampuan berhitung serta mengasah" << endl;
    cout << "otak agar dapat berpikir dengan cepat dan akurat. Permainan Kartu 24 biasa dimainkan dengan menggunakan kartu remi. Kartu remi terdiri" << endl;
    cout << "dari 52 kartu yang terbagi menjadi empat suit (sekop, hati, keriting, dan wajik) yang masing-masing terdiri dari 13 kartu (As, 2, 3, 4," << endl;
    cout << "5, 6, 7, 8, 9, 10, Jack, Queen, dan King). Yang perlu diperhatikan hanyalah nilai kartu yang didapat (As, 2, 3, 4, 5, 6, 7, 8, 9, 10," << endl;
    cout << "Jack, Queen, dan King). As bernilai 1, Jack bernilai 11, Queen bernilai 12, King bernilai 13, sedangkan kartu bilangan memiliki nilai" << endl;
    cout << "dari bilangan itu sendiri. Pada awal permainan moderator atau salah satu pemain mengambil 4 kartu dari dek yang sudah dikocok secara" << endl;
    cout << "random. Permainan berakhir ketika pemain berhasil menemukan solusi untuk membuat kumpulan nilainya menjadi 24. Pengubahan nilai tersebut" << endl;
    cout << "dapat dilakukan menggunakan operasi dasar matematika penjumlahan (+), pengurangan (-), perkalian (×), divisi (/) dan tanda kurung ( () )." << endl;
    cout << "Tiap kartu harus digunakan tepat sekali dan urutan penggunaannya bebas." << endl;
    cout << endl;
    cout << "<> Contoh masukan untuk Menu nomor 1: " << endl;
    cout << "A 2 3 4 " << endl;
    cout << "10 J Q K " << endl;
    cout << endl;
    cout << "<> Menu nomor 2 hanya mengeluarkan kartu-kartu random." << endl;
    cout << endl;
    cout << "<> Setelah mendapatkan Solusi dan Jumlah Solusinya, Anda dapat menyimpan data tersebut ke dalam file .txt." << endl;
    cout << endl;
    cout << "Selamat Mencoba :D" << endl;
    system("pause");
}