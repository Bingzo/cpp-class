#ifndef STUDENT_H__
#define STUDENT_H__

#include "person.h"
#include "curriculum.h"
#include <ostream>

class student:virtual public person{
public:
	student(){ 
        nationality = "NAN";
    }
	student(int i, std::string n);
	virtual ~student(){}

	void setNationality( std::string na );
	std::string getNationality() const;
	curriculum getCurriculum() const;

	friend std::ostream& operator<<( std::ostream &os, const student &s);

	curriculum& getCurriculum();

private:
	std::string nationality;
	curriculum curr;

};

student::student(int i, std::string n): person( i, n ){}

void student::setNationality( std::string na ){
	nationality = na;
}

std::string student::getNationality () const{
	return nationality;
}

curriculum &student::getCurriculum(){
	return curr;
}

curriculum student::getCurriculum() const{
	return curr;
}

#include<iomanip>
std::ostream& operator<<( std::ostream &os, const student &s){
	const int W = 15;
	os << std::setw(W) << s.getId() << std::setw(W) << s.getName(); 
    if( "NAN" != s.getNationality() ){
        os << std::setw(W) << s.getNationality();
    }
	if( -1 != s.getCurriculum().getMark() ){
		os << std::setw(W) << s.getCurriculum().getMark() << std::setw(W) << s.getCurriculum().getLevel();
	}
	return os;
}

#endif
