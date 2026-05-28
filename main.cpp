#include "notepad.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice;
    string filename;

   
    do {
        
        cout << "SIMPLE NOTEPAD" << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                cout << "Enter filename to create: ";
                cin >> filename;
                writeFile(filename); 
                break;

            case 2:
                cout << "Enter filename to read: ";
                cin >> filename;
                readFile(filename); 
                break;

            case 3:
                cout << "Enter filename to append to: ";
                cin >> filename;
                appendFile(filename); 
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                
                cout << "Invalid choice! Please try again.\n" << endl;
                break;
        }
    } while (choice != 4); 

    return 0;
}