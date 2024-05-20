#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 3;
const int C = 1;

int main() {

    string weightFile = "10";
    string nameFile = "main";
    string typeFile = ".cpp";

    cout << "FileName" << " " << "Type" << " " << "Weight" << endl;
    cout << endl;
    string mass[C][N] = { {nameFile, typeFile, weightFile} };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) {
            cout << mass[j][i];
            cout << "    ";
        }
    }

    return 0;
}