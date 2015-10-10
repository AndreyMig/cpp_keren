#ifndef __FACILITY_H
#define __FACILITY_H

#include <ostream>
#include "guest.h"
#include "operator.h"
using namespace std;
 
class Facility
{
public:
	Facility(const char* name, int maxNumOfPassangers, bool ageTypeAvailable[], const Operator* mainOperator, bool needVIPTicket = false);
	Facility(const Facility& other);
	virtual ~Facility();
	const Facility& operator=(const Facility& other);

	//getters
	int getMaxNumOfPassengers() const;
	bool doesNeedVIPTicket() const;
	const char* getName() const;
	bool* getAgeTypeAvailable() const;
	const Guest** getGuests() const;
	Guest** getGuests(); //for changes

	//setters
	void setMaxNumOfPassengers(int maxNumOfPassangers); //maximum number of guests to get on ride
	void setNeddVIPTicket(bool needVIPTicket);
	void setName(const char* name);
	void setAgeTypeByIndex(int index);

	//actions
	void start() const;									//start the facility (start each passenger "have fun" action, and remove all guests!!!! [operator -=]) 
	const Facility& operator+=(const Guest& passenger); // add a passenger to passengers list only if operator accept!!!! (call for operator 'checkTicket' method)
	const Facility& operator-=(const Guest& passenger); // remove a passenger to passengers list
	Guest& operator[] (const char* guestName);			// get the guest in the list by name

	//print
	friend ostream& operator<<(ostream& os, const Facility& f);

private:
	char* name;
	bool ageTypeAvailable[Guest::AgeTypeSize]; //array of age type available for this facility
	bool needVIPTicket;
	Guest** passengers; // array of guest on facility (dynamic)
	int maxNumOfPassangers;
	int numOfPassengers;
	Operator* mainOperator;
};

#endif