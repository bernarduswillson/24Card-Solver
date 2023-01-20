#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void save(string saveDat[], int count, int Cards[]) {
    ofstream outdata;
    int i;
    string input;
    bool flag = false;
    while (flag == false) {
        cout << "Apakah Anda ingin menyimpan file? (y/n): ";
        cin >> input;
        if (input == "y") {
            string fileName;
            cout << "Masukkan nama file: ";
            cin >> fileName;
            outdata.open("test/"+fileName+".txt");
            outdata << "KARTU: ";
            for (int i = 0; i < 4; i++) {
                if (Cards[i] == 1) {
                    outdata << "A ";
                }
                else if (Cards[i] == 2) {
                    outdata << "2 ";
                }
                else if (Cards[i] == 3) {
                    outdata << "3 ";
                }
                else if (Cards[i] == 4) {
                    outdata << "4 ";
                }
                else if (Cards[i] == 5) {
                    outdata << "5 ";
                }
                else if (Cards[i] == 6) {
                    outdata << "6 ";
                }
                else if (Cards[i] == 7) {
                    outdata << "7 ";
                }
                else if (Cards[i] == 8) {
                    outdata << "8 ";
                }
                else if (Cards[i] == 9) {
                    outdata << "9 ";
                }
                else if (Cards[i] == 10) {
                    outdata << "10 ";
                }
                else if (Cards[i] == 11) {
                    outdata << "J ";
                }
                else if (Cards[i] == 12) {
                    outdata << "Q ";
                }
                else if (Cards[i] == 13) {
                    outdata << "K ";
                }
            }
            if (count != 0) {
                outdata << endl;
                outdata << "=====================" << endl;
                outdata << count << " SOLUSI DITEMUKAN!"<< endl;
                outdata << "=====================" << endl;
                outdata << "Solusi:" << endl;
                for (i = 0; i < count; ++i)
                    outdata << saveDat[i] << endl;
                outdata << "=====================" << endl;
            }
            else {
                outdata << endl;
                outdata << "=================" << endl;
                outdata << "TIDAK ADA SOLUSI!" << endl;
                outdata << "=================" << endl;
            }
            outdata.close();
            cout << "File berhasil disimpan!" << endl;
            flag = true;
        }
        else if (input == "n") {
            flag = true;
        }
        else {
            cout << "!MASUKAN TIDAK SESUAI, MOHON ULANGI MASUKAN!" << endl;
            cout << endl;
            flag = false;
        }
    }
}

