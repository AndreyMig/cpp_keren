#include "operator.h"

Operator::Operator(const Person& person,int id) : Person(person), id(id)
{
}

int Operator::getID() const{
	return this->id;
}
void Operator::setID(int id){
	this->id = id;
}

//print
ostream& operator<<(ostream& os, const Operator& o)
{
	os << "Operator : " << o.id << endl;
	return os;
}

