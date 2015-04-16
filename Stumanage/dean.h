#ifndef DEAN_H__
#define DEAN_H__

#include "person.h"

class dean: virtual public person{
public:
	dean(){}
	dean(int i, std::string n):person(i, n){}

	void setStudentLevel( student &s, int m ){
        std::string l;
        if( "Han" == s.getNationality() ){
            m < 60? l = "unqualified" : l = "qualified";
        }else{
            m < 50? l = "unqualified" : l = "qualified";
        }
		s.getCurriculum().setLevel( l );
	}
	std::string getStudentLevel( student &s ){
		return s.getCurriculum().getLevel();
	}
	int getStudentMark( student &s ){
		return s.getCurriculum().getMark();
	}

    friend std::ostream& operator<<( std::ostream &os, const dean &d);
};

#include <iomanip>
std::ostream& operator<<( std::ostream &os, const dean &d){
	const int W = 15;
	os << std::setw(W) << d.getId() << std::setw(W) << d.getName();
	return os;
}


#endif
