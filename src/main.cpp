#include <iostream>
#include <string>
#include <chrono>
#include "others\inputCard.cpp"
#include "algorithm\numbers.cpp"
#include "algorithm\operators.cpp"
#include "others\saveDat.cpp"
#include "others\splashScreen.cpp"

using namespace std;

int main() {
    int input;
    int CardInt[4];
    bool flag = false;
    using Clock = chrono::high_resolution_clock;
    welcomeScreen();  
    while (flag == false) {
        menu();
        cin >> input;
        if (input == 1) {
            inputTerminal(CardInt);
            flag = true;
        }
        else if (input == 2) {
            inputRandom(CardInt);
            flag = true;
        }
        else if (input == 3) {
            help();
            flag = false; 
        }
        else if (input == 4) {
            exit(0);
        }
        else {
            cout << "!MASUKAN TIDAK SESUAI, MOHON ULANGI MASUKAN!" << endl;
            flag = false;
        }
    }
    auto start = Clock::now();
    int Cards[4];
    for (int i = 0; i < 4; i++) {
        Cards[i] = CardInt[i];
    }
    sortArr(CardInt);
    string saveRes[10000] = {};
    int row = 0;
    int count = 0;
    string op1, op2, op3;
    do {
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 5; j++ ) {
                for (int k = 1; k < 5; k++) {
                    // ((A _ B) _ C) _ D
                    if (operators(operators(operators(CardInt[0], CardInt[1], i), CardInt[2], j), CardInt[3], k) == 24) {
                        string Card1 = to_string(CardInt[0]);
                        string Card2 = to_string(CardInt[1]);
                        string Card3 = to_string(CardInt[2]);
                        string Card4 = to_string(CardInt[3]);
                        opOutput(i, j, k, &op1, &op2, &op3);
                        saveRes[count] = "(("+Card1+" "+op1+" "+Card2+") "+op2+" "+Card3+") "+op3+" "+Card4;
                        count++;
                    }
                    //  (A _ (B _ C)) _ D
                    if (operators(operators(CardInt[0], operators(CardInt[1], CardInt[2], i), j), CardInt[3], k) == 24) {
                        string Card1 = to_string(CardInt[0]);
                        string Card2 = to_string(CardInt[1]);
                        string Card3 = to_string(CardInt[2]);
                        string Card4 = to_string(CardInt[3]);
                        opOutput(i, j, k, &op1, &op2, &op3);
                        saveRes[count] = "("+Card1+" "+op2+" ("+Card2+" "+op1+" "+Card3+")) "+op3+" "+Card4;
                        count++;
                    }
                    // (A _ B) _ (C _ D)
                    if (operators(operators(CardInt[0], CardInt[1], i), operators(CardInt[2], CardInt[3], j), k) == 24) {
                        string Card1 = to_string(CardInt[0]);
                        string Card2 = to_string(CardInt[1]);
                        string Card3 = to_string(CardInt[2]);
                        string Card4 = to_string(CardInt[3]);
                        opOutput(i, j, k, &op1, &op2, &op3);
                        saveRes[count] = "("+Card1+" "+op1+" "+Card2+") "+op3+" ("+Card3+" "+op2+" "+Card4+")";
                        count++;
                    }
                    // A _ ((B _ C) _ D)
                    if (operators(CardInt[0], operators(operators(CardInt[1], CardInt[2], i), CardInt[3], j), k) == 24) {
                        string Card1 = to_string(CardInt[0]);
                        string Card2 = to_string(CardInt[1]);
                        string Card3 = to_string(CardInt[2]);
                        string Card4 = to_string(CardInt[3]);
                        opOutput(i, j, k, &op1, &op2, &op3);
                        saveRes[count] = Card1+" "+op3+" (("+Card2+" "+op1+" "+Card3+") "+op2+" "+Card4+")";
                        count++;
                    }
                }
            }
        }
        row += 1;
    } while (permutation(CardInt));
    if (count == 0) {
        cout << "==================" << endl;
        cout << "Tidak ada solusi!" << endl;
    }
    else {
        cout << "=====================" << endl;
        cout << count << " SOLUSI DITEMUKAN!"<< endl;
        cout << "=====================" << endl;
        cout << "Solusi: " << endl;
        for (int i = 0; i < count; i++) {
            cout << saveRes[i] << endl;
        }
    }
    auto end = Clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "================================" << endl;
    cout << "Execution time: " << ms << " milliseconds" << endl;
    cout << "================================" << endl;
    cout << endl;
    save(saveRes, count, Cards);
    string input1;
    bool flag1 = false;
    while (flag1 == false) {
        cout << endl;
        cout << "Apakah Anda ingin mencoba angka lain? (y/n): ";
        cin >> input1;
        if (input1 == "y") {
            flag1 = true;
            main();
        }
        else if (input1 == "n") {
            exit(0);
        }
        else {
            cout << "!MASUKAN TIDAK SESUAI, MOHON ULANGI MASUKAN!" << endl;
            flag1 = false;
        }
    }
}