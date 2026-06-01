#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
   string lines = "God,Allah-Mungu-Ima";
   stringstream ss(lines);
   string first;
   getline(ss, first, '-');
   cout << first << endl;

   cout << endl;

   string filename = "students.txt";

   ifstream checkFile(filename);
   if (checkFile.peek() == EOF) {
       checkFile.close();
       ofstream file(filename);
       file << "202312051,lithacynthia,18\n";
       file << "202312052,dessama,18\n";
       file << "202312053,david,20\n";
       file.close();
   } else {
       checkFile.close();
   }

   string fileline;
   ifstream readFile(filename);
   string searcRoll;
   cout << "Enter a roll number to search: " << endl;
   cin >> searcRoll;
   bool found = false;

   while (getline(readFile, fileline)) {
       stringstream ss(fileline);
       string roll;
       getline(ss, roll, ',');
       if (roll == searcRoll) {
           cout << "Student was found with details:" << endl;
           cout << fileline << endl;
           found = true;
       }
   }
   if (!found) cout << "The student is not in the list" << endl;
   readFile.close();

   string updateRoll;
   cout << "\nEnter a roll number to update: " << endl;
   cin >> updateRoll;

   string newName, newAge;
   cout << "Enter new name: ";
   cin >> newName;
   cout << "Enter new age: ";
   cin >> newAge;

   ifstream readFile2(filename);
   string allData = "";
   bool updated = false;
   while (getline(readFile2, fileline)) {
       stringstream ss2(fileline);
       string roll;
       getline(ss2, roll, ',');
       if (roll == updateRoll) {
           allData += roll + "," + newName + "," + newAge + "\n";
           updated = true;
       } else {
           allData += fileline + "\n";
       }
   }
   readFile2.close();

   if (!updated) {
       allData += updateRoll + "," + newName + "," + newAge + "\n";
       cout << "Added successfully!" << endl;
   } else {
       cout << "Updated successfully!" << endl;
   }

   ofstream writeFile(filename);
   writeFile << allData;
   writeFile.close();

   string deleteRoll;
   cout << "\nEnter a roll number to delete: " << endl;
   cin >> deleteRoll;

   ifstream readFile3(filename);
   string deleteData = "";
   bool deleted = false;
   while (getline(readFile3, fileline)) {
       stringstream ss3(fileline);
       string roll;
       getline(ss3, roll, ',');
       if (roll == deleteRoll) {
           deleted = true;
       } else {
           deleteData += fileline + "\n";
       }
   }
   readFile3.close();

   ofstream writeFile2(filename);
   writeFile2 << deleteData;
   writeFile2.close();

   if (deleted)
       cout << "Deleted successfully!" << endl;
   else
       cout << "Roll number not found!" << endl;

   return 0;
}