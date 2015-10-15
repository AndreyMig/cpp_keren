#ifndef __PARK_H
#define __PARK_H

#include <ostream>
#include "facility.h"
#include "operator.h"
#include "guest.h"
#include "vipTicket.h"
#include "IObserver.h"
#include <string>
#include <vector>

using namespace std;

class Park
{
public:
	static const double TICKET_PRICE;
	static const double VIP_TICKET_PRICE;

	Park(const string& name);
	~Park();

	//getters
	const string& getName() const;
	const vector<Facility*> getFacilities() const;
	const vector<Operator*> getOperators() const;
	const vector<Guest*> getGuests() const; 

	//setters
	void setName(const string& name);

	//actions
	// person buy ticket from park, the park create this person as a guest
	Guest& buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, const string& date, bool isVip=false, VIPTicket::VIPType vipKind=VIPTicket::FREE_FOOD); 

	//add or remove facility
	const Park& operator+=(Facility& facility);				// add facility to park
	const Park& operator-=(const Facility& facility);		// remove facility from park

	//add or remove operator
	const Park& operator+=(Operator& theOperator);			// add operator to park
	const Park& operator-=(const Operator& theOperator);	// remove operator from park

	//add or remove guest
	const Park& operator+=(Guest& guest);					// add guest to park
	const Park& operator-=(const Guest& guest);				// remove guest from park
	
	//find operator by id
	const Operator& operator[] (int id) const;

	//print
	friend ostream& operator<<(ostream& os, const Park& p);

	// Observer
	void registerObserver(const IObserver* obs);
	void discountOnFoodSection(int precenatge) const;

private:
	string name;

	vector<const IObserver*> viewers;
	vector<Operator*> operators;
	vector<Guest*> guests;
	vector<Facility*> facilities;

	Park(const Park& other);
	const Park& operator=(const Park& other);
};

#endif