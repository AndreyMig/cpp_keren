#ifndef __OPERATOR_H
#define __OPERATOR_H

#include <ostream>
#include "person.h"
#include "ticket.h"
using namespace std;
 
class Operator : public Person
{
public:
	Operator(const Person& person,int id);

	int getID() const;
	void setID(int id);

	//actions
	bool checkTicket(const Ticket& ticket) const; //check if ticket is relevant for the ride 
												  //(AgeTypeAvailable of a facility and if VipTicket required)

	//print
	friend ostream& operator<<(ostream& os, const Operator& o);

private:
	int id;
};

#endif