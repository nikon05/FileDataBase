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

//         Функционал
// ---------------------------- //

void menu();
int main();

void userChoiceFolder() {
    int choice;

    system("cls");
    cout << " " << endl;
    cout << "Вы работаете в папке: " + folderName << endl;
    cout << " " << endl;

    cout << "Выберите действие: \n 1. Создать файл в папке \n 2. Удалить файл в папке \n 3. Создание или выбор другой папки \n 4. Ввод данных в файл \n 5. Список всех файлов в папке \n 6. Меню \n 0. Выход" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла, который хотите удалить: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите его разрешение: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(folderName + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "Файл успешно был удалён!" << endl;

        userChoiceFolder();
    }
    else if (choice == 3) {
        system("cls");
        cout << "Напишите название папки: " << endl;
        cout << "\nЕсли папка уже существует, то вы просто в неё войдёте!" << endl;
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        string enter;

        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string path = folderName + "/";

        cout << "Список файлов в папке (Кроме папок): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\nВведите любую цифру, чтобы закрыть: " << endl;
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
                cout << "Err: Это не цифра!" << endl;
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
        cout << "Err: Неизвестное действие!";
        userChoiceFolder();
    }
}
void userChoiceSpace() {
    int choice;
    system("cls");

    cout << " " << endl;
    cout << "Вы работаете в пространстве" << endl;
    cout << " " << endl;

    cout << "Выберите действие: \n 1. Создать файл \n 2. Удалить файл \n 3.Ввод данных \n 4. Список всех файлов в пространстве \n 5. Меню \n 0. Выход" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
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
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла, который хотите удалить: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите его разрешение: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(fileName + "." + Expansion);
        cout << " " << endl;
        cout << "Файл успешно был удалён!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        system("cls");
        string fileName;
        string Expansion;

        string enter;

        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
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
    else if (choice == 4) {
        system("cls");
        string path = ".";

        cout << "Список файлов (Кроме папок): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }

        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\nВведите любую цифру, чтобы закрыть: " << endl;
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
                cout << "Err: Это не цифра!" << endl;
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
        cout << "Err: Неизвестное действие!";
        userChoiceSpace();
    }
}
void userChoicePath() {
    int choice;
    system("cls");

    cout << " " << endl;
    cout << "Вы работаете по пути: " + userPath << endl;
    cout << " " << endl;

    cout << "Выберите действие: \n 1. Создать файл в папке \n 2. Удалить файл в папке \n 3. Выбор другого пути \n 4. Ввод данных в файл \n 5. Список всех файлов в папке \n 6. Меню \n 0. Выход" << endl;
    cout << " " << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        fout.open(userPath + "/" + fileName + "." + Expansion);
        if (!fout.is_open()) {
            cout << "Err: Файл не был создан!" << endl;
            userChoicePath();
        }
        else {
            cout << "Файл с названием: " + fileName + "." + Expansion + " был успешно создан по пути " + userPath << endl;

            fout.close();
            userChoicePath();
        }
    }
    else if (choice == 2) {
        system("cls");
        string fileName;
        string Expansion;

        cout << " " << endl;
        cout << "Введите название файла, который хотите удалить: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;

        cout << "Введите его разрешение: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        remove(userPath + "/" + fileName + "." + Expansion);
        cout << " " << endl;
        cout << "Файл успешно был удалён!" << endl;

        userChoicePath();
    }
    else if (choice == 3) {
        system("cls");
        cout << "Впишите путь в котором будете работать: " << endl;
        cout << "Пример: C:/Папка/Папка" << endl;

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

        cout << "Введите название файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> fileName;
        cout << "Введите расширение файла: ";
        cout << " " << endl;
        cout << "> ";
        cin >> Expansion;

        fout.open(userPath + "/" + fileName + "." + Expansion);
        if (fout.is_open()) {
            cout << "Файл успешно открыт! (Если имя указано не верное, то файл был создан)" << endl;
            cout << "Внимание! Ввод данных не работает с пробелами!" << endl;
            cout << "\n> ";

            cin >> enter;
            fout << enter;

            cout << "Данные были введены!" << endl;
            userChoicePath();

            fout.close();

        }
        else {
            cout << "Err: Файл не был открыт или создан!" << endl;

            userChoicePath();

            fout.close();
        }
    }
    else if (choice == 5) {
        system("cls");
        string path = userPath + "/";

        cout << "Список файлов в папке (Кроме папок): " << endl;
        cout << " " << endl;

        for (const auto& entry : directory_iterator(path)) {
            if (entry.is_regular_file()) {
                cout << entry.path().filename() << endl;
            }
        }
        int number;
        bool whileOn = true;
        while (whileOn == true) {
            cout << "\nВведите любую цифру, чтобы закрыть: " << endl;
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
                cout << "Err: Это не цифра!" << endl;
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
        cout << "Err: Неизвестное действие!";
        userChoicePath();
    }
}

//            Меню
// ---------------------------- // 

void menu() {
    int choice;

    cout << " " << endl;
    cout << "Выберете рабочее место: \n 1. Работа в Папке \n 2. Работа в Пространстве \n 3. Работа по Пути \n 4. Выход" << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        cout << "Напишите название папки: " << endl;
        cout << "\nЕсли папка уже существует, то вы просто в неё войдёте!" << endl;

        cout << " " << endl;
        cout << "> ";
        cin >> folderName;

        path folderPath = current_path() / folderName;

        if (!exists(folderPath)) {
            create_directory(folderPath);
            cout << "Папка была успешно создана!\n";

            userChoiceFolder();
        }
        else {
            cout << "Вы успешно вошли в папку!" << endl;

            userChoiceFolder();
        }
    }
    else if (choice == 2) {
        cout << "Вы перешли в пространство!" << endl;

        userChoiceSpace();
    }
    else if (choice == 3) {
        cout << "Впишите путь в котором будете работать: " << endl;
        cout << "Пример: C:/Папка/Папка" << endl;

        cout << " " << endl;
        cout << "> ";
        cin >> userPath;

        userChoicePath();
    }
    else if (choice == 4) {
        cout << "Exit";
    }
    else {
        cout << "Err: Неккоректное значение!" << endl;
        menu();
    }
}

int main() {
	setlocale(LC_ALL, "Russian");

    cout << "|=======================================================|" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                  FILEDATABASE v1.2                    |" << endl;
    cout << "|      by Fakyouka(Максим) & nikon_05(Никита)           |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|=======================================================|" << endl;
    menu();

	return 0;
}