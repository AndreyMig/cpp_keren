#ifndef __FACILITY_H
#define __FACILITY_H

#include <ostream>
#include "guest.h"
#include "operator.h"
#include <string>
#include <vector>
#include "MyLinkedList.h"

using namespace std;

class Facility
{
public:
	Facility(const string& name, vector<bool> ageTypeAvailable, Operator* mainOperator, bool needVIPTicket = false);
	virtual ~Facility();

	//getters
	bool doesNeedVIPTicket() const;
	const string& getName() const;
	const vector<bool> getAgeTypeAvailable() const;
	const MyLinkedList<const Guest*> getGuests() const;
	const Operator& getOperator() const;

	//setters
	void setNeedVIPTicket(bool needVIPTicket);
	void Facility::setName(const string& name);
	void setAgeTypeByIndex(int index, bool allowed);
	void setOperator(Operator& mainOperator); // maybe const

	//actions
	void start(ostream& o=cout);									//start the facility (start each passenger "have fun" action, and remove all guests!!!! [operator -=]) 
	const Facility& operator+=(Guest& passenger);					// add a passenger to passengers list only if operator accept!!!! (call for operator 'checkTicket' method)
	const Facility& operator-=(const Guest& passenger);				// remove a passenger to passengers list

	//print
	friend ostream& operator<<(ostream& os, const Facility& f);

protected:
	string name;
	vector<bool> ageTypeAvailable;
	bool needVIPTicket;

	MyLinkedList<const Guest*> guests;
	Operator* mainOperator;

	Facility(const Facility& other);
	const Facility& operator=(const Facility& other);
};

#endif