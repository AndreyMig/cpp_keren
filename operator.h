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

	//print
	friend ostream& operator<<(ostream& os, const Operator& o);

private:
	int id;
};

#endif