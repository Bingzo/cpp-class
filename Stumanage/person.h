#ifndef PERSON_H__
#define PERSON_H__

#include <string>

class person{
public:
	person();
	person(int i, std::string n);
	virtual ~person(){}

	void setId( int i );
	void setName( std::string n );
	int getId() const;
	std::string getName() const;

private:
	int id;
	std::string name;

};

person::person(){
	id = -1;
	name = "NAN";
}

person::person( int i, std::string n ){
	id = i;
	name = n;
}

void person::setId( int i ){
	id = i;
}

void person::setName( std::string n ){
	name = n;
}

int person::getId() const{
	return id;
}

std::string person::getName() const{
	return name;
}

#endif