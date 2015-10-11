#ifndef __PARK_H
#define __PARK_H

#include <ostream>
#include "facility.h"
#include "operator.h"
#include "guest.h"
#include <list>
using namespace std;
 
class Park
{
public:
	Park(const char* name, int maxFacilities, int maxOperators, int maxGuests);
	Park(const Park& other);
	~Park();
	const Park& operator=(const Park& other);

	//getters
	const char* getName() const;
	const Facility** getFacilities() const;
	const Operator** getOperators() const;
	const Guest** getGuests() const;
	Facility**  getFacilities(); //gettets for changing
	Operator** getOperators();
	list<Guest*> Park::getGuests();

	//setters
	void setName(const char* name);
	void setFacilities(const Facility** facilities);
	void setOperators(const Operator** operators);
	void setGuests(const Guest** guests);

	//actions
	Guest& buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, bool isVip = false); // person buy ticket from park, the park create this person as a guest,
																									  // and add him to the park ( operator += );

	const Park& operator+=(const Facility& facility); //add facility to park
	const Park& operator-=(const Facility& facility);// remove facility from park
	const Park& operator+=(const Operator& _operator);//add operator to park
	const Park& operator-=(const Operator& _operator);// remove operator from park
	const Park& operator+=(Guest& guest);		// add guest to park
	const Park& operator-=(const Guest& guest);		//remove guest from park

	//print
	friend ostream& operator<<(ostream& os, const Park& p);

private:
	char* name;
	Facility** facilities; 
	Operator** operators;
	list<Guest*> guestsList;
	//Guest** guests;
	int numOfFacilities;
	int numOfOperators;
	int numOfGuests;
	int maxFacilities;
	int maxOperators;
	int maxGuests;
	const int Park::findGuestInParkByName(const char* guestName) const;
};

#endif