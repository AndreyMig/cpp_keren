#ifndef __GUEST_H
#define __GUEST_H

#include <ostream>
#include <iostream>
#include "person.h"
#include "ticket.h"
using namespace std;
 
class Guest : public Person
{
public:
	static const int AGE_TYPE_SIZE = 3;
	enum AgeType
	{
		CHILD,
		ADULT,
		ELDER
	};

	enum Feel
	{
		HAPPY,
		AFRAID,
		THRILLED
	};

	Guest(const Person& person, AgeType type, Feel feel, const Ticket& ticket);

	//getters
	const Ticket* getTicket() const;
	AgeType getType() const;
	Feel getFeel() const;

	//setters
	void setFeel(Feel feel);
	void setAgeType(AgeType type);

	//actions
	void haveFun(ostream& os=cout) const; //print the guest feeling

	//print
	friend ostream& operator<<(ostream& os, const Guest& g);

private:
	const Ticket* ticket; // pointer because polymorphism (can be ticket or vip ticket)
	AgeType type;
	Feel feel;

	Guest(const Guest& other);
	const Guest& operator=(const Guest& other);
};

#endif