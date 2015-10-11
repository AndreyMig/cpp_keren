#include "operator.h"


int Operator::getID() const{
	return this->id;
}
void Operator::setID(int id){
	this->id = id;
}

bool Operator::checkTicket(const Ticket& ticket) const{

	//TODO implement check ticket
	return true;
}


//print
ostream& operator<<(ostream& os, const Operator& o)
{
	os << "Operator : " << o.id << endl;
	

	return os;
}

