#ifndef __PARK_H
#define __PARK_H

#include <ostream>
#include "facility.h"
#include "operator.h"
#include "guest.h"
#include "vipTicket.h"

using namespace std;

class Park
{
public:
	static const double TICKET_PRICE;
	static const double VIP_TICKET_PRICE;

	Park(const char* name, int maxFacilities, int maxOperators, int maxGuests);
	Park(const Park& other);
	~Park();
	const Park& operator=(const Park& other);

	//getters
	const char* getName() const;
	const Facility*const* getFacilities() const;
	const Operator*const* getOperators() const;
	const Guest*const* getGuests() const;

	//setters
	void setName(const char* name);

	//actions
	// person buy ticket from park, the park create this person as a guest,
	Guest& buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, char date[], bool isVip=false, VIPTicket::VIPType vipKind=VIPTicket::FREE_FOOD); 

	const Park& operator+=(Facility& facility); //add facility to park
	const Park& operator-=(const Facility& facility);// remove facility from park
	const Park& operator+=(Operator& _operator);//add operator to park
	const Park& operator-=(const Operator& _operator);// remove operator from park
	const Park& operator+=(Guest& guest);		// add guest to park
	const Park& operator-=(const Guest& guest);		//remove guest from park
	const Operator& operator[] (int id) const;

	//print
	friend ostream& operator<<(ostream& os, const Park& p);

private:
	char* name;

	Facility** facilities; 
	int numOfFacilities;
	int maxFacilities;

	Operator** operators;
	int numOfOperators;
	int maxOperators;

	Guest** guests;
	int numOfGuests;
	int maxGuests;
};

#endif