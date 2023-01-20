#include <iostream>

using namespace std;

void sortArr(int *CardInt) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (CardInt[j] > CardInt[j + 1]) {
                int temp = CardInt[j];
                CardInt[j] = CardInt[j + 1];
                CardInt[j + 1] = temp;
            }
        }
    }
}

void reverseArr(int *first, int *last) { 
    while (first != last && first != --last) {
        iter_swap(first++, last);
    }
}

bool permutation(int* CardInt) {
    int i = 3;
    int j = 3;
    while (i > 0 && CardInt[i - 1] >= CardInt[i]) {
        i--;
    }
    if (i == 0) {
        return false;
    }
    else {
        while (CardInt[j] <= CardInt[i - 1]) {
            j--;
        }
        swap(CardInt[i - 1], CardInt[j]);
        reverseArr(CardInt + i, CardInt + 4);
        return true;
    }
}