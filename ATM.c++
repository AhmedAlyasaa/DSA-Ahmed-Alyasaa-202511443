#include <iostream>
#include <fstream>

using namespace std;


void showHistory();
void learnCpp();

int main() {

    int choice;

    do {

        cout << "\n===== FOUNDATIONS AND HISTORY OF C++ =====\n";
        cout << "1. History of C++\n";
        cout << "2. Learn C++ Concepts\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1:
            showHistory();
            break;

        case 2:
            learnCpp();
            break;

        case 3:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}


void showHistory() {

    cout << "\n===== HISTORY OF C++ =====\n";

    cout << "1. C++ was developed by Bjarne Stroustrup.\n";
    cout << "2. C++ started as an extension of C language.\n";
    cout << "3. The language was created in 1979.\n";
    cout << "4. C++ supports object-oriented programming.\n";
    cout << "5. It is widely used in software development.\n";
}


void learnCpp() {

    int topic;

    cout << "\n===== LEARN C++ =====\n";
    cout << "1. Data Types\n";
    cout << "2. Control Flow\n";
    cout << "3. Loops\n";
    cout << "4. Arrays\n";
    cout << "5. File Streams\n";
    cout << "Choose Topic: ";
    cin >> topic;

    switch (topic) {

    case 1:
        cout << "\nData Types: int, float, char, string, bool\n";
        break;

    case 2:
        cout << "\nControl Flow: if, else, switch\n";
        break;

    case 3:
        cout << "\nLoops: for loop, while loop, do while loop\n";
        break;

    case 4:
        cout << "\nArrays store multiple values in one variable.\n";
        break;

    case 5: {

        ifstream file("chapter.txt");

        if (file.is_open()) {

            string line;

            cout << "\n===== FILE CONTENT =====\n";

            while (getline(file, line)) {
                cout << line << endl;
            }

            file.close();
        }
        else {
            cout << "\nUnable to open file.\n";
        }

        break;
    }

    default:
        cout << "\nInvalid Topic!\n";
    }
}