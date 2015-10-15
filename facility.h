#ifndef __FACILITY_H
#define __FACILITY_H

#include <ostream>
#include "guest.h"
#include "operator.h"
using namespace std;
 
class Facility
{
public:
	Facility(const char* name, int maxNumOfPassangers, bool ageTypeAvailable[], Operator* mainOperator, bool needVIPTicket = false);
	virtual ~Facility();

	//getters
	int getMaxNumOfPassengers() const;
	bool doesNeedVIPTicket() const;
	const char* getName() const;
	const bool* getAgeTypeAvailable() const;
	const Guest*const* getGuests() const;
	const Operator& getOperator() const;

	//setters
	void setMaxNumOfPassengers(int maxNumOfPassangers); //maximum number of guests to get on ride
	void setNeedVIPTicket(bool needVIPTicket);
	void setName(const char* name);
	void setAgeTypeByIndex(int index, bool allowed);

	//actions
	void start(ostream& o=cout);									//start the facility (start each passenger "have fun" action, and remove all guests!!!! [operator -=]) 
	const Facility& operator+=(Guest& passenger); // add a passenger to passengers list only if operator accept!!!! (call for operator 'checkTicket' method)
	const Facility& operator-=(const Guest& passenger); // remove a passenger to passengers list
	const Facility& operator--();

	//print
	friend ostream& operator<<(ostream& os, const Facility& f);

protected:
	char* name;
	bool ageTypeAvailable[Guest::AGE_TYPE_SIZE]; //array of age type available for this facility
	bool needVIPTicket;

	Guest** guests; // array of guest on facility (dynamic)
	int maxNumOfPassangers;
	int numOfPassengers;

	Operator* mainOperator;
	
	Facility(const Facility& other);
	const Facility& operator=(const Facility& other);
};

#endif