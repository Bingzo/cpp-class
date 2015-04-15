/**
 * @file markmanage.cpp
 * @Synopsis  Simple management system of student's marks in C++
 * @author Binzo   
 * @version 1.0.0
 * @date 2015-04-15
 */

#include <iostream>
#include <fstream>
using namespace std;

// global variables
char fileName[] = "mark.txt";
int marks[100];
int Nrec; // number of records

// display the main menu
void displayMenu();
// read from file "mark. txt"
void readFromFile();
// save the records of marks to file "mark.txt"
void saveToFile();

// six options
void record();
void display();
void query();
void insert(); // insert is different from record
void mydelete(); // since delete is the keyword in C++
void sort();

int main(){
    int isQuit = false; 
    int opt; //option
    while( !isQuit ){
        displayMenu(); // menu
        readFromFile(); // read from "mark.txt"
        cout << "Do your choice: " << endl;
        cin >> opt;
        switch( opt ){
            case 1:
                record();
                break;
            case 2:
                display();
                break;
            case 3:
                query();
                break;
            case 4:
                insert();
                break;
            case 5:
                mydelete();
                break;
            case 6:
                sort();
                break;
            case 0:
                isQuit = true;
                break;
            default:
                cout << " !!! Illegal input !!!" << endl;
                cout << endl;
        }
    }
}

void displayMenu(){
    cout << " ********* Main Menu *********" << endl;
    cout << " *       1: RECORD           *" << endl;
    cout << " *       2: DISPLAY          *" << endl;
    cout << " *       3: QUERY            *" << endl;
    cout << " *       4: INSERT           *" << endl;
    cout << " *       5: DELETE           *" << endl;
    cout << " *       6: SORT             *" << endl;
    cout << " *       0: QUIT             *" << endl;
    cout << " *****************************" << endl;
}

void readFromFile(){
    ifstream ifs( fileName, ios_base::in );
    int i = 0;
    while( !ifs.eof() ){
        ifs >> marks[i];
        ++ i;
    }
    Nrec = i - 1; // 
}

void saveToFile(){
    ofstream ofs( fileName, ios_base::trunc );
    int i = 0;
    while( i < Nrec ){
        ofs << marks[i] << ' ';
        ++ i;
    }
}

void record(){
    int i = Nrec;
    int m;
    cout << "Enter -1 to stop entering numbers: ";
    while( true ){
        cin >> m;
        if( -1 == m ){
            break;
        }
        marks[i] = m;
        ++ i;
    }
    cout << ( i - Nrec ) << " record(s) has(have) been added." << endl;
    Nrec = i;
    saveToFile();
    cout << endl;
}

void display(){
    cout << endl;
    cout << Nrec << " records found: ";
    for( int i = 0; i < Nrec; i ++ ){
        if( i % 10 == 0 ){
            cout << endl;
        }
        cout << marks[i] << ' ';
    }
    cout << endl << endl;
}

void query(){
    int id;
    cout << "Enter the ID(1~" << Nrec << ") of the record: ";
    cin >> id;
    if( id > Nrec ){
        cout << "No such a record. ID should be less than (or equal to) " << Nrec << endl;
    }
    else{
        -- id;
        cout << "Found the record: " << marks[id] << endl;
    }
    cout << endl;
}

void insert(){
    int id;
    int m;
    cout << "Enter the ID(1~" << Nrec << ") in front of which you wanna insert the mark: ";
    cin >> id;
    cout << "Enter the mark: ";
    cin >> m;
    if( id > Nrec ){
        cout << "No such a record. ID should be less than (or equal to) " << Nrec << endl;
    }
    else{
        -- id;
        for( int i = Nrec+1; i > id; i -- ){
            marks[i] = marks[i-1];
        }
        marks[id] = m; 
        ++ Nrec;
        cout << "The record has been inserted succussfully" << endl;
        saveToFile();
    }
    cout << endl;
}

void mydelete(){
    int id;
    cout << "Enter the ID(1~" << Nrec << ") of the record: ";
    cin >> id;
    if( id > Nrec ){
        cout << "No such a record. ID should be less than (or equal to) " << Nrec << endl;
    }
    else{
        cout << "Found the record. Deleting..." << endl;
        -- id;
        for( int i = id; i < Nrec; i ++ ){
            marks[i] = marks[i+1];
        }
        -- Nrec;
        cout << "Successfully deleted the record." << endl;
        saveToFile();
    }
    cout << endl;
}

void sort(){
    cout << "Sorting..." << endl;
    int marks_cp[100];
    for( int i = 0; i < Nrec; i ++ ){
        marks_cp[i] = marks[i];
    }
    for( int j = 1; j < Nrec; j ++ ){
        int key = marks_cp[j];
        int i = j - 1;
        while( i >= 0 && marks_cp[i] > key ){
            marks_cp[i+1] = marks_cp[i];
            -- i;
        }
        marks_cp[i+1] = key;
    }
    cout << "Sorted marks: " << endl;
    for( int i = 0; i < Nrec; i ++ ){
        if( i % 10 == 0 ){
            cout << endl;
        }
        cout << marks_cp[i] << ' ';
    }
    cout << endl << endl;
}
