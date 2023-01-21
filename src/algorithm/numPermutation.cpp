#include <iostream>

using namespace std;

void permutation(int A, int B, int C, int D, int result[24][4], int *counter) {
    int save[1000][4] = {};
    int count = 0;
    int col = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        if (i == 0) {
                            save[count][col] = A;
                            col++;
                        }
                        if (i == 1) {
                            save[count][col] = B;
                            col++;
                        }
                        if (i == 2) {
                            save[count][col] = C;
                            col++;
                        }
                        if (i == 3) {
                            save[count][col] = D;
                            col++;
                        }
                        if (j == 0) {
                            save[count][col] = A;
                            col++;
                        }
                        if (j == 1) {
                            save[count][col] = B;
                            col++;
                        }
                        if (j == 2) {
                            save[count][col] = C;
                            col++;
                        }
                        if (j == 3) {
                            save[count][col] = D;
                            col++;
                        }
                        if (k == 0) {
                            save[count][col] = A;
                            col++;
                        }
                        if (k == 1) {
                            save[count][col] = B;
                            col++;
                        }
                        if (k == 2) {
                            save[count][col] = C;
                            col++;
                        }
                        if (k == 3) {
                            save[count][col] = D;
                            col++;
                        }
                        if (l == 0) {
                            save[count][col] = A;
                            col = 0;
                        }
                        if (l == 1) {
                            save[count][col] = B;
                            col = 0;
                        }
                        if (l == 2) {
                            save[count][col] = C;
                            col = 0;
                        }
                        if (l == 3) {
                            save[count][col] = D;
                            col = 0;
                        }
                        count++;
                    }
                }
            }
        }
    }
    int resultCount = 1;
    int resultCounts = 0;
    int saveCount = 1;
    result[0][0] = save[0][0];
    result[0][1] = save[0][1];
    result[0][2] = save[0][2];
    result[0][3] = save[0][3];
    while (saveCount < count) {
        for (int x = 0; x < resultCount; x++) {
            if (result[x][0] == save[saveCount][0] && result[x][1] == save[saveCount][1] && result[x][2] == save[saveCount][2] && result[x][3] == save[saveCount][3]) {
                break;
            }
            else {
                resultCounts++;
            }
            if (resultCounts == resultCount) {
                result[resultCount][0] = save[saveCount][0];
                result[resultCount][1] = save[saveCount][1];
                result[resultCount][2] = save[saveCount][2];
                result[resultCount][3] = save[saveCount][3];
                resultCount++;
            }
        }
        resultCounts = 0;
        saveCount++;
    }
    *counter = resultCount;
}