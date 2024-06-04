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
    cout << "Вы работаете в папке: " + folderName << endl;
    cout << " " << endl;

    cout << "Выберите действие: \n 1. Создать файл в папке \n 2. Удалить файл в папке \n 3. Создание или выбор другой папки \n 4. Ввод данных в файл \n 5. Переход в пространство \n 6. Список всех файлов в папке \n 0. Выход" << endl;
    cin >> choice;

    if (choice == 1) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла: ";
        cin >> fileName;

        cout << "Введите расширение файла: ";
        cin >> Expansion;

        fout.open(folderName + "/" + fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: Файл не был создан!" << endl;
            userChoiceFolder();
        }
        else {
            cout << "Файл с названием: " + fileName + "." + Expansion + " был успешно создан в папке " + folderName << endl;

            fout.close();
            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла, который хотите удалить: ";
        cin >> fileName;

        cout << "Введите его разрешение: ";
        cin >> Expansion;

        remove(folderName + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "Файл успешно был удалён!" << endl;
        
        userChoiceFolder();
    }
    else if (choice == 3) {
        cout << "Напишите название папки: " << endl;
        cout << "\nЕсли папка уже существует, то вы просто в неё войдёте!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "Успешно!\n";

            userChoiceFolder();
        }
        else {
            cout << "Вы успешно вошли в папку " + folderName;

            userChoiceFolder();
        }
    }
    else if (choice == 4) {
        string fileName;
        string Expansion;

        string enter;

        cout << "Введите название файла: ";
        cin >> fileName;
        cout << "Введите расширение файла: ";
        cin >> Expansion;

        fout.open(folderName + "/" + fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "Файл успешно открыт! (Если имя указано не верное, то файл был создан)" << endl;
            cout << "Внимание! Ввод данных не работает с пробелами!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "Данные были введены!" << endl;
            userChoiceFolder();

            fout.close();

        }
        else {
            cout << "Err: Файл не был открыт или создан!" << endl;
            
            userChoiceFolder();

            fout.close();
        }
    }
    else if (choice == 5) {
        cout << "\n Вы успешно перешли в пространство!" << endl;
        userChoiceSpace();
    }
    else if (choice == 6) {
        string path = folderName + "/";

        cout << "Список файлов в папке (Кроме папок): " << endl;
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
        cout << "Err: Неизвестное действие!";
        userChoiceFolder();
    }
}

void userChoiceSpace() {
    int choice;
    cout << " " << endl;
    cout << "Вы работаете в пространстве" << endl;
    cout << " " << endl;

    cout << "Выберите действие: \n 1. Создать файл \n 2. Удалить файл \n 3. Переход в папки \n 4. Ввод данных в файл \n 5. Список всех файлов в пространстве\n 0. Выход" << endl;
    cin >> choice;

    if (choice == 1) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла: ";
        cin >> fileName;

        cout << "Введите расширение файла: ";
        cin >> Expansion;

        fout.open(fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: Файл не был создан!" << endl;
            userChoiceSpace();
        }
        else {
            cout << "Файл с названием: " + fileName + "." + Expansion + " был успешно создан в пространстве" << endl;

            fout.close();
            userChoiceSpace();
        }
    }
    else if (choice == 2) {
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла, который хотите удалить: ";
        cin >> fileName;

        cout << "Введите его разрешение: ";
        cin >> Expansion;

        remove(fileName + "." + Expansion);
        cout << " " << endl;
        cout << "Файл успешно был удалён!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        cout << "Напишите название папки: " << endl;
        cout << "\nЕсли папка уже существует, то вы просто в неё войдёте!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "Успешно!\n";

            userChoiceFolder();
        }
        else {
            cout << "Вы успешно вошли в папку " + folderName;

            userChoiceFolder();
        }
    }
    else if (choice == 4) {
        string fileName;
        string Expansion;

        string enter;

        cout << "Введите название файла: ";
        cin >> fileName;
        cout << "Введите расширение файла: ";
        cin >> Expansion;

        fout.open(fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "Файл успешно открыт! (Если имя указано не верное, то файл был создан)" << endl;
            cout << "Внимание! Ввод данных не работает с пробелами!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "Данные были введены!" << endl;
            userChoiceSpace();

            fout.close();

        }
        else {
            cout << "Err: Файл не был открыт или создан!" << endl;

            userChoiceSpace();

            fout.close();
        }
    }
    else if (choice == 5) {
        string path = ".";

        cout << "Список файлов (Кроме папок): " << endl;
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
        cout << "Err: Неизвестное действие!";
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

    cout << "Выберете рабочее место: \n 1. В папке \n 2. В пространстве \n 3. Авторы" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Напишите название папки: " << endl;
        cout << "\nЕсли папка уже существует, то вы просто в неё войдёте!" << endl;
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "Успешно!\n";

            userChoiceFolder();
        }
        else {
            cout << "Вы успешно вошли в папку" << endl;

            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        userChoiceSpace();
    }
    else if (choice == 3) {
        int back;
        cout << "Авторы приложения: Fakyouka(Максим) & nikon_05(Никита)" << endl;
        cout << " " << endl;
        cout << "Введите любое число, чтобы выйти: ";

        cin >> back;

        if (back >= 0) {
            main();
        }
        else {
            main();
        }
    }
    else {
        cout << "Err: Неизвестное пространство!" << endl;
        main();
    }

    return 0;
}