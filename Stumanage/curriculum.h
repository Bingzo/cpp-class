#ifndef CURRICULUM_H__
#define CURRICULUM_H__

#include <string>

class curriculum{
public:
	curriculum(){
		mark = -1;
		level = "NAN";
	}
	curriculum( int m, std::string l );
	//curriculum( curriculum & cur );
	virtual ~curriculum(){}

	void setMark ( int m ){
		mark = m;
	}
	int getMark() const{
		return mark;
	}

	void setLevel( std::string l ){
		level = l;
	}
	std::string getLevel() const{
		return level;
	}

private:
	int mark;
	std::string level;

};

curriculum::curriculum( int m, std::string l ){
	mark = m;
	level = l;
}

#endif