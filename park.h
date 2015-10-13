#ifndef __PARK_H
#define __PARK_H

#include <ostream>
#include "facility.h"
#include "operator.h"
#include "guest.h"
#include "vipTicket.h"
#include "MyLinkedList.h"
#include <string>
#include <vector>

using namespace std;

class Park
{
public:
	static const double TICKET_PRICE;
	static const double VIP_TICKET_PRICE;

	Park(const string& name);

	//getters
	const string& getName() const;
	const vector<Facility*> getFacilities() const; // TODO
	const vector<Operator*> getOperators() const;
	const MyLinkedList<Guest*> getGuests() const;

	//setters
	void setName(const string& name);

	//actions
	// person buy ticket from park, the park create this person as a guest,
	Guest& buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, const string& date, bool isVip=false, VIPTicket::VIPType vipKind=VIPTicket::FREE_FOOD); 

	const Park& operator+=(Facility& facility);				//add facility to park
	const Park& operator-=(const Facility& facility);		// remove facility from park
	const Park& operator+=(Operator& _operator);			//add operator to park
	const Park& operator-=(const Operator& _operator);		// remove operator from park
	const Park& operator+=(Guest* guest);					// add guest to park
	const Park& operator-=(Guest* guest);				   // TODO to keren: missing const explain in cpp file
	const Operator& operator[] (int id) const;

	//print
	friend ostream& operator<<(ostream& os, const Park& p);

private:
	string name;

	vector<Facility*> facilities;
	vector<Operator*> operators;
	MyLinkedList<Guest*> guests;


	Park(const Park& other);
	const Park& operator=(const Park& other);
};

#endif