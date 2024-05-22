#include <iostream>
#include <string>
#include <vector>
using namespace std;

int playerChoise;
const int N = 3;
const int C = 1;

void showDataBase() {

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
}

void choiseParagraph() {

    cout << "1. Add file" << endl;
    cout << "2. Remove file" << endl;
    cout << "3. Show DataBase" << endl;

    cin >> playerChoise;
    if (playerChoise == 1) {
        cout << "Add file" << endl;
    }
    else if (playerChoise == 2) {
        cout << "Remove file" << endl;
    }
    else if (playerChoise == 3) {
        cout << "Show DataBase" << endl;
        showDataBase();
    }
    else {
        cout << "Error : Incorrect paragraph" << endl;
    }

}

int main() {

    cout << "File DataBase" << endl;
    cout << " " << endl;
    choiseParagraph();

}