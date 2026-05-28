#include "notepad.h"
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


void writeFile(string filename) {
    
    ofstream outFile(filename);
    
    if (!outFile) {
        cout << "Error: Could not create file!" << endl;
        return;
    }

    cout << "\n--- Beginning to write in the file (" << filename << ") ---" << endl;
    cout << "Enter your text here. To finish writing and save, type 'END' on a new line:" << endl;

    string line;
    
    cin.ignore(); 

   
    while (true) {
        getline(cin, line); 
        
        if (line == "END") { 
            break;
        }
        outFile << line << endl; 
    }

    outFile.close(); 
    cout << "File saved successfully.\n" << endl;
}


void readFile(string filename) {
    
    ifstream inFile(filename);

    
    if (!inFile) {
        cout << "\nError: The file '" << filename << "' does not exist or could not be opened!" << endl;
        return;
    }

    cout << "\n--- Contents of the file (" << filename << ") ---" << endl;
    string line;
    
    
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "----------------------------------------\n" << endl;

    inFile.close();
}


void appendFile(string filename) {
   
    ofstream outFile(filename, ios::app);

    if (!outFile) {
        cout << "Error: Could not open file for appending!" << endl;
        return;
    }

    cout << "\n--- Beginning to append to the file (" << filename << ") ---" << endl;
    cout << "Enter the text to append. To finish appending, type 'END' on a new line:" << endl;

    string line;
    cin.ignore(); 
    while (true) {
        getline(cin, line);
        
        if (line == "END") { 
            break;
        }
        outFile << line << endl; 

    outFile.close(); 
    cout << "Text appended successfully.\n" << endl;
}