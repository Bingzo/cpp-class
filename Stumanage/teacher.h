#ifndef TEACHEAR_H__
#define TEACHEAR_H__

#include "person.h"
#include "student.h"
#include <ostream>

class teacher: virtual public person{
public:
	teacher(){}
	teacher(int i, std::string n):person(i, n){}
	
	void setStudentMark( student &s, int m ){
		s.getCurriculum().setMark( m );
	}
	int getStudentMark( student &s ){
		return s.getCurriculum().getMark();
	}
	std::string getStudentLevel( student &s ){
		return s.getCurriculum().getLevel();
	}

    friend std::ostream& operator<<( std::ostream &os, const teacher &t);
};

#include <iomanip>
std::ostream& operator<<( std::ostream &os, const teacher &t){
	const int W = 15;
	os << std::setw(W) << t.getId() << std::setw(W) << t.getName();
	return os;
}

#endif
