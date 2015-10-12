#include "operator.h"

int Operator::ID_GEN = 1000;

Operator::Operator(const Person& person) : Person(person), id(ID_GEN++)
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
	os << o.name << " (employee " << o.id << ")" << endl;
	return os;
}

