#include "student.h"
#include "teacher.h"
#include "dean.h"
#include <iostream>
//#include <vector>
#include <iomanip>
using namespace std;

enum post{
	DEAN, TEACHER, STUDENT
};

int main ( int argc, char *argv[] ){

	const int W = 15;

	cout << "-----------------------" << endl;
	cout << "Welcome to the management system of student curriculums." << endl;
	cout << "-----------------------" << endl;
    cout << endl;

	//vector<student> vStu;
    student stu[3];
    string name[3] = { "Ming", "Qin", "Hua" };
    for( int i = 0; i < 3; i ++ ){
        stu[i].setId( 2013000+i );
        stu[i].setName( name[i] );
    }
	//vStu.push_back( stu );

    cout << "Built 3 records:" << endl;
    cout << endl;
	cout << "\t   " << setw(W) << "ID" << setw(W) << "NAME" << setw(W) << \
		"NATIONALITY" << setw(W) << "MARK" << setw(W) << "LEVEL" << endl;
    cout << endl;
    for( int i = 0; i < 3; i ++ ){
        cout << "\t-->" << stu[i] << endl;   
    }

    teacher tea( 1998000, "TeaLi" );
    dean dea( 1996000, "DeaXu" );   


    string na[3] = { "Han", "Zang", "Han" };
    cout << endl;
    cout << "Editing the nationality by the student himself/herself." << endl;
    for( int i = 0; i < 3; i ++ ){
        cout << "This is " << stu[i].getName() << "( ID " << stu[i].getId() << " )." << endl;
        stu[i].setNationality( na[i] );
    }

    int marks[3] = { 59, 51, 61 };
    cout << endl;
    cout << "Editing the marks by the teacher." << endl;
    cout << "This is " << tea.getName() << "( ID " << tea.getId() << " )." << endl;
    for( int i = 0; i < 3; i ++ ){
        tea.setStudentMark( stu[i], marks[i] );
    }

    cout << endl;
    cout << "Editing the levels by the dean." << endl;
    cout << "This is " << dea.getName() << "( ID " << dea.getId() << " )." << endl;
    for( int i = 0; i < 3; i ++ ){
        dea.setStudentLevel( stu[i], dea.getStudentMark(stu[i]) );
    }

    cout << endl;
    cout << "Edited records:" << endl;
    cout << endl;
	cout << "\t   " << setw(W) << "ID" << setw(W) << "NAME" << setw(W) << \
		"NATIONALITY" << setw(W) << "MARK" << setw(W) << "LEVEL" << endl;
    cout << endl;
    for( int i = 0; i < 3; i ++ ){
        cout << "\t-->" << stu[i] << endl;   
    }

	////while( 1 ){
	//	cout << "Found " << vStu.size() << " records:" << endl;
	//	cout << setw(W) << "ID" << setw(W) << "NAME" << setw(W) << \
	//		"NATIONALITY" << setw(W) << "MARK" << setw(W) << "LEVEL" << endl;
	//	for( vector<student>::iterator i = vStu.begin(); i != vStu.end(); i ++ ){
	//		cout << *i << endl;
	//	}
	//	cout << endl;

	//	int inputError = 0;
	//	post po;
	//
	//	do{
	//		cout << "(a) DEAN, (b) TEACHER or (c) STUDENT ?" << endl;
	//		char ch;
	//		cin >> ch;
	//		switch(ch){
	//		case 'a':
	//		case 'A':
	//			inputError = 0;
	//			po = DEAN;
	//			cout << "You are a dean." << endl;
	//			break;
	//		case 'b':
	//		case 'B':
	//			inputError = 0;
	//			po = TEACHER;
	//			cout << "You are a teacher." << endl;
	//			cout << "Set the mark of a student (y/n)?" << endl;
	//			char yesno;
	//			cin >> yesno;
	//			if( 'y' == yesno || 'Y' == yesno ){
	//				cout << "Input the student's ID: ";
	//				int id;
	//				cin >> id;
	//				cout << "Input the student's ID: ";
	//				int mark;
	//				cin >> mark;
	//				for( vector<student>::iterator i = vStu.begin(); i != vStu.end(); i ++ ){
	//					if( (*i).getId() == id ){
	//						//setStudentMark( *i, mark );
	//					}
	//				}					
	//			}
	//			break;
	//		case 'c':
	//		case 'C':
	//			inputError = 0;
	//			po = STUDENT;
	//			cout << "You are a student." << endl;
	//			break;
	//		default:
	//			inputError = 1;
	//			cout << "Input error!" << endl;
	//		}
	//	}while( inputError );
	//	
	////}

	return 0;
}
