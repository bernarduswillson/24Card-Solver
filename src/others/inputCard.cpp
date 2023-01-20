#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inputTerminal(int *CardInt) {
    string Card[4];
    bool flag = false;
    cout << endl;
    cout << "Masukkan 4 kartu dengan input seperti berikut: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K" << endl;
    while (flag == false) {
        cout << "Masukkan kartu: ";
        cin >> Card[0] >> Card[1] >> Card[2] >> Card[3];
        for (int i = 0; i < 4; i++) {
            if (Card[i] == "A" || Card[i] == "2" || Card[i] == "3" || Card[i] == "4" || Card[i] == "5" || Card[i] == "6" || Card[i] == "7" || Card[i] == "8" || Card[i] == "9" || Card[i] == "10" || Card[i] == "J" || Card[i] == "Q" || Card[i] == "K") {
                flag = true;
            }
            else {
                flag = false;
                cout << "!MASUKAN TIDAK SESUAI, MOHON ULANGI MASUKAN!" << endl;
                cout << endl;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (Card[i] == "A") {
            CardInt[i] = 1;
        }
        else if (Card[i] == "2") {
            CardInt[i] = 2;
        }
        else if (Card[i] == "3") {
            CardInt[i] = 3;
        }
        else if (Card[i] == "4") {
            CardInt[i] = 4;
        }
        else if (Card[i] == "5") {
            CardInt[i] = 5;
        }
        else if (Card[i] == "6") {
            CardInt[i] = 6;
        }
        else if (Card[i] == "7") {
            CardInt[i] = 7;
        }
        else if (Card[i] == "8") {
            CardInt[i] = 8;
        }
        else if (Card[i] == "9") {
            CardInt[i] = 9;
        }
        else if (Card[i] == "10") {
            CardInt[i] = 10;
        }
        else if (Card[i] == "J") {
            CardInt[i] = 11;
        }
        else if (Card[i] == "Q") {
            CardInt[i] = 12;
        }
        else if (Card[i] == "K") {
            CardInt[i] = 13;
        }
    }
}

void inputRandom(int *CardInt) {
    srand(time(NULL));
    CardInt[0] = (rand() % 13) + 1;
    CardInt[1] = (rand() % 13) + 1;
    CardInt[2] = (rand() % 13) + 1;
    CardInt[3] = (rand() % 13) + 1;
    cout << endl;
    cout << "Kartu yang didapat adalah: ";
    for (int i = 0; i < 4; i++) {
        if (CardInt[i] == 1) {
            cout << "A ";
        }
        else if (CardInt[i] == 11) {
            cout << "J ";
        }
        else if (CardInt[i] == 12) {
            cout << "Q ";
        }
        else if (CardInt[i] == 13) {
            cout << "K ";
        }
        else {
            cout << CardInt[i] << " ";
        }
    }
    cout << endl;
}