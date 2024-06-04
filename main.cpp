#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <fstream>

using namespace std;
namespace fs = filesystem;
using namespace fs;

path folderPath;
string folderName;

ofstream fout;
ifstream fin;

void userChoiceSpace();

void userChoiceFolder() {
    int choice;
    cout << " " << endl;
    cout << "�� ��������� � �����: " + folderName << endl;
    cout << " " << endl;

    cout << "�������� ��������: \n 1. ������� ���� � ����� \n 2. ������� ���� � ����� \n 3. �������� ��� ����� ������ ����� \n 4. ���� ������ � ���� \n 5. ������� � ������������ \n 6. ������ ���� ������ � ����� \n 0. �����" << endl;
    cin >> choice;

    if (choice == 1) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����: ";
        cin >> fileName;

        cout << "������� ���������� �����: ";
        cin >> Expansion;

        fout.open(folderName + "/" + fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: ���� �� ��� ������!" << endl;
            userChoiceFolder();
        }
        else {
            cout << "���� � ���������: " + fileName + "." + Expansion + " ��� ������� ������ � ����� " + folderName << endl;

            fout.close();
            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����, ������� ������ �������: ";
        cin >> fileName;

        cout << "������� ��� ����������: ";
        cin >> Expansion;

        remove(folderName + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "���� ������� ��� �����!" << endl;
        
        userChoiceFolder();
    }
    else if (choice == 3) {
        cout << "�������� �������� �����: " << endl;
        cout << "\n���� ����� ��� ����������, �� �� ������ � �� ������!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "�������!\n";

            userChoiceFolder();
        }
        else {
            cout << "�� ������� ����� � ����� " + folderName;

            userChoiceFolder();
        }
    }
    else if (choice == 4) {
        string fileName;
        string Expansion;

        string enter;

        cout << "������� �������� �����: ";
        cin >> fileName;
        cout << "������� ���������� �����: ";
        cin >> Expansion;

        fout.open(folderName + "/" + fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "���� ������� ������! (���� ��� ������� �� ������, �� ���� ��� ������)" << endl;
            cout << "��������! ���� ������ �� �������� � ���������!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "������ ���� �������!" << endl;
            userChoiceFolder();

            fout.close();

        }
        else {
            cout << "Err: ���� �� ��� ������ ��� ������!" << endl;
            
            userChoiceFolder();

            fout.close();
        }
    }
    else if (choice == 5) {
        cout << "\n �� ������� ������� � ������������!" << endl;
        userChoiceSpace();
    }
    else if (choice == 6) {
        string path = folderName + "/";

        cout << "������ ������ � ����� (����� �����): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        userChoiceFolder();
    }
    else if (choice == 0) {
        cout << "Exit";
    }
    else {
        cout << "Err: ����������� ��������!";
        userChoiceFolder();
    }
}

void userChoiceSpace() {
    int choice;
    cout << " " << endl;
    cout << "�� ��������� � ������������" << endl;
    cout << " " << endl;

    cout << "�������� ��������: \n 1. ������� ���� \n 2. ������� ���� \n 3. ������� � ����� \n 4. ���� ������ � ���� \n 5. ������ ���� ������ � ������������\n 0. �����" << endl;
    cin >> choice;

    if (choice == 1) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����: ";
        cin >> fileName;

        cout << "������� ���������� �����: ";
        cin >> Expansion;

        fout.open(fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: ���� �� ��� ������!" << endl;
            userChoiceSpace();
        }
        else {
            cout << "���� � ���������: " + fileName + "." + Expansion + " ��� ������� ������ � ������������" << endl;

            fout.close();
            userChoiceSpace();
        }
    }
    else if (choice == 2) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����, ������� ������ �������: ";
        cin >> fileName;

        cout << "������� ��� ����������: ";
        cin >> Expansion;

        remove(fileName + "." + Expansion);
        cout << " " << endl;
        cout << "���� ������� ��� �����!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        cout << "�������� �������� �����: " << endl;
        cout << "\n���� ����� ��� ����������, �� �� ������ � �� ������!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "�������!\n";

            userChoiceFolder();
        }
        else {
            cout << "�� ������� ����� � ����� " + folderName;

            userChoiceFolder();
        }
    }
    else if (choice == 4) {
        string fileName;
        string Expansion;

        string enter;

        cout << "������� �������� �����: ";
        cin >> fileName;
        cout << "������� ���������� �����: ";
        cin >> Expansion;

        fout.open(fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "���� ������� ������! (���� ��� ������� �� ������, �� ���� ��� ������)" << endl;
            cout << "��������! ���� ������ �� �������� � ���������!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "������ ���� �������!" << endl;
            userChoiceSpace();

            fout.close();

        }
        else {
            cout << "Err: ���� �� ��� ������ ��� ������!" << endl;

            userChoiceSpace();

            fout.close();
        }
    }
    else if (choice == 5) {
        string path = ".";

        cout << "������ ������ (����� �����): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        userChoiceSpace();
    }
    else if (choice == 0) {
        cout << "Exit";
    }
    else {
        cout << "Err: ����������� ��������!";
        userChoiceSpace();
    }
}

int main() {
    int choice;
    setlocale(LC_ALL, "Russian");

    cout << "==============================" << endl;
    cout << "|                            |" << endl;
    cout << "|       FILEDATABASE         |" << endl;
    cout << "|   by Fakyouka & nikon_05   |" << endl;
    cout << "|                            |" << endl;
    cout << "==============================" << endl;

    cout << " " << endl;

    cout << "�������� ������� �����: \n 1. � ����� \n 2. � ������������ \n 3. ������" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "�������� �������� �����: " << endl;
        cout << "\n���� ����� ��� ����������, �� �� ������ � �� ������!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "�������!\n";

            userChoiceFolder();
        }
        else {
            cout << "�� ������� ����� � �����" << endl;

            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        userChoiceSpace();
    }
    else if (choice == 3) {
        int back;
        cout << "������ ����������: Fakyouka(������) & nikon_05(������)" << endl;
        cout << " " << endl;
        cout << "������� ����� �����, ����� �����: ";

        cin >> back;

        if (back >= 0) {
            main();
        }
        else {
            main();
        }
    }
    else {
        cout << "Err: ����������� ������������!" << endl;
        main();
    }

    return 0;
}