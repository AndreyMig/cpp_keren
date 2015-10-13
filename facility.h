#ifndef __FACILITY_H
#define __FACILITY_H

#include <ostream>
#include "guest.h"
#include "operator.h"
#include <string>
#include <vector>

using namespace std;

class Facility
{
public:
	Facility(const string& name, vector<bool> ageTypeAvailable, Operator* mainOperator, bool needVIPTicket = false);
	virtual ~Facility();

	//getters
	bool doesNeedVIPTicket() const;
	const string& getFacilityName() const;
	const vector<bool> getAgeTypeAvailable() const;
	const vector<const Guest*> getGuests() const;

	//setters
	void setNeedVIPTicket(bool needVIPTicket);
	void Facility::setFacilityName(const string& name);
	void setAgeTypeByIndex(int index, bool allowed);

	//actions
	void start(ostream& o=cout);									//start the facility (start each passenger "have fun" action, and remove all guests!!!! [operator -=]) 
	const Facility& operator+=(Guest& passenger); // add a passenger to passengers list only if operator accept!!!! (call for operator 'checkTicket' method)
	const Facility& operator-=(const Guest& passenger); // remove a passenger to passengers list

	//print
	friend ostream& operator<<(ostream& os, const Facility& f);

protected:
	string name;
	vector<bool> ageTypeAvailable;
	bool needVIPTicket;

	vector<const Guest*> guests;
	Operator* mainOperator;

private:
	const Guest* findGuest(const string guestName) const;
};

#endif