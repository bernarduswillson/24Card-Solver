#include <iostream>

using namespace std;

double operators(double a, double b, int n) {
    double result;
    if (n==1) {
        result = a + b;
    }
    else if (n==2) {
        result = a - b;
    }
    else if (n==3) {
        result = a * b;
    }
    else if (n==4) {
        result = a / b;
    }
    return result;
}

void opOutput(int i, int j, int k, string *op1, string *op2, string *op3) {
    if (i == 1) {
        *op1 = "+";
    }
    else if (i == 2) {
        *op1 = "-";
    }
    else if (i == 3) {
        *op1 = "*";
    }
    else if (i == 4) {
        *op1 = "/";
    }
    if (j == 1) {
        *op2 = "+";
    }
    else if (j == 2) {
        *op2 = "-";
    }
    else if (j == 3) {
        *op2 = "*";
    }
    else if (j == 4) {
        *op2 = "/";
    }
    if (k == 1) {
        *op3 = "+";
    }
    else if (k == 2) {
        *op3 = "-";
    }
    else if (k == 3) {
        *op3 = "*";
    }
    else if (k == 4) {
        *op3 = "/";
    }
}