#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

using namespace std;
namespace fs = filesystem;
using namespace fs;

ofstream fout;
ifstream fin;

path folderPath;
string folderName;
string userPath;
bool userOn = true;

//         ����������
// ---------------------------- //

void menu();
int main();

void userChoiceFolder() {
    int choice;

    system("cls");
    cout << " " << endl;
    cout << "�� ��������� � �����: " + folderName << endl;
    cout << " " << endl;

    cout << "�������� ��������: \n 1. ������� ���� � ����� \n 2. ������� ���� � ����� \n 3. �������� ��� ����� ������ ����� \n 4. ���� ������ � ���� \n 5. ������ ���� ������ � ����� \n 6. ���� \n 0. �����" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����, ������� ������ �������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ��� ����������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(folderName + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "���� ������� ��� �����!" << endl;

        userChoiceFolder();
    }
    else if (choice == 3) {
        system("cls");
        cout << "�������� �������� �����: " << endl;
        cout << "\n���� ����� ��� ����������, �� �� ������ � �� ������!" << endl;
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        string enter;

        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string path = folderName + "/";

        cout << "������ ������ � ����� (����� �����): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\n������� ����� �����, ����� �������: " << endl;
            cout << "> ";

            cin >> number;
            if (number >= 0) {
                whileOn = false;
                userChoiceFolder();
            }
            else if (number < 0) {
                whileOn = false;
                userChoiceFolder();
            }
            else {
                cout << "Err: ��� �� �����!" << endl;
            }
        }
    }
    else if (choice == 6) {
        system("cls");
        menu();
    }
    else if (choice == 0) {
        cout << "Exit";
    }
    else {
        system("cls");
        cout << "Err: ����������� ��������!";
        userChoiceFolder();
    }
}
void userChoiceSpace() {
    int choice;
    system("cls");

    cout << " " << endl;
    cout << "�� ��������� � ������������" << endl;
    cout << " " << endl;

    cout << "�������� ��������: \n 1. ������� ���� \n 2. ������� ���� \n 3.���� ������ \n 4. ������ ���� ������ � ������������ \n 5. ���� \n 0. �����" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����, ������� ������ �������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ��� ����������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(fileName + "." + Expansion);
        cout << " " << endl;
        cout << "���� ������� ��� �����!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        system("cls");
        string fileName;
        string Expansion;

        string enter;

        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
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
    else if (choice == 4) {
        system("cls");
        string path = ".";

        cout << "������ ������ (����� �����): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\n������� ����� �����, ����� �������: " << endl;
            cout << "> ";

            cin >> number;
            if (number >= 0) {
                whileOn = false;
                userChoiceSpace();
            }
            else if (number < 0) {
                whileOn = false;
                userChoiceSpace();
            }
            else {
                cout << "Err: ��� �� �����!" << endl;
            }
        }

    }
    else if (choice == 5) {
        system("cls");
        menu();
    }
    else if (choice == 0) {
        cout << "Exit";
    }
    else {
        cout << "Err: ����������� ��������!";
        userChoiceSpace();
    }
}
void userChoicePath() {
    int choice;
    system("cls");

    cout << " " << endl;
    cout << "�� ��������� �� ����: " + userPath << endl;
    cout << " " << endl;

    cout << "�������� ��������: \n 1. ������� ���� � ����� \n 2. ������� ���� � ����� \n 3. ����� ������� ���� \n 4. ���� ������ � ���� \n 5. ������ ���� ������ � ����� \n 6. ���� \n 0. �����" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        fout.open(userPath + "/" + fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: ���� �� ��� ������!" << endl;
            userChoicePath();
        }
        else {
            cout << "���� � ���������: " + fileName + "." + Expansion + " ��� ������� ������ �� ���� " + userPath << endl;

            fout.close();
            userChoicePath();
        }
    }
    else if (choice == 2) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "������� �������� �����, ������� ������ �������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "������� ��� ����������: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(userPath + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "���� ������� ��� �����!" << endl;

        userChoicePath();
    }
    else if (choice == 3) {
        system("cls");
        cout << "������� ���� � ������� ������ ��������: " << endl;
        cout << "������: C:/�����/�����" << endl;

        cout << " " << endl;
        cout << "> ";
        cin >> userPath;

        userChoicePath();
    }
    else if (choice == 4) {
        system("cls");
        string fileName;
        string Expansion;

        string enter;

        cout << "������� �������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "������� ���������� �����: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        fout.open(userPath + "/" + fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "���� ������� ������! (���� ��� ������� �� ������, �� ���� ��� ������)" << endl;
            cout << "��������! ���� ������ �� �������� � ���������!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "������ ���� �������!" << endl;
            userChoicePath();

            fout.close();

        }
        else {
            cout << "Err: ���� �� ��� ������ ��� ������!" << endl;

            userChoicePath();

            fout.close();
        }
    }
    else if (choice == 5) {
        system("cls");
        string path = userPath + "/";

        cout << "������ ������ � ����� (����� �����): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }
        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\n������� ����� �����, ����� �������: " << endl;
            cout << "> ";

            cin >> number;
            if (number >= 0) {
                whileOn = false;
                userChoicePath();
            }
            else if (number < 0) {
                whileOn = false;
                userChoicePath();
            }
            else {
                cout << "Err: ��� �� �����!" << endl;
            }
        }
        
    }
    else if (choice == 6) {
        system("cls");
        menu();
    }
    else if (choice == 0) {
        cout << "Exit";
    }
    else {
        cout << "Err: ����������� ��������!";
        userChoicePath();
    }
}

//            ����
// ---------------------------- // 

void menu() {
    int choice;

    cout << " " << endl;
    cout << "�������� ������� �����: \n 1. ������ � ����� \n 2. ������ � ������������ \n 3. ������ �� ���� \n 4. �����" << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        cout << "�������� �������� �����: " << endl;
        cout << "\n���� ����� ��� ����������, �� �� ������ � �� ������!" << endl;

        cout << " " << endl;
        cout << "> ";
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "����� ���� ������� �������!\n";

            userChoiceFolder();
        }
        else {
            cout << "�� ������� ����� � �����!" << endl;

            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        cout << "�� ������� � ������������!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        cout << "������� ���� � ������� ������ ��������: " << endl;
        cout << "������: C:/�����/�����" << endl;

        cout << " " << endl;
        cout << "> ";
        cin >> userPath;

        userChoicePath();
    }
    else if (choice == 4) {
        cout << "Exit";
    }
    else {
        cout << "Err: ������������ ��������!" << endl;
        menu();
    }
}

int main() {
	setlocale(LC_ALL, "Russian");

    cout << "|=======================================================|" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                  FILEDATABASE v1.2                    |" << endl;
    cout << "|      by Fakyouka(������) & nikon_05(������)           |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|=======================================================|" << endl;
    menu();

	return 0;
}