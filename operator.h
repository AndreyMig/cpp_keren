#ifndef __OPERATOR_H
#define __OPERATOR_H

#include <ostream>
#include "person.h"
#include "ticket.h"
using namespace std;
 
class Operator : public Person
{
public:
	Operator(const Person& person);

	int getID() const;

	//print
	friend ostream& operator<<(ostream& os, const Operator& o);

private:
	static int ID_GEN;
	int id;
};

#endif