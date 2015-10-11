#ifndef __GUEST_H
#define __GUEST_H

#include <ostream>
#include "person.h"
#include "ticket.h"
using namespace std;
 
class Guest : public Person
{
private:
	Guest(const Guest& other);
	const Guest& operator=(const Guest& other);
public:
	static const int AgeTypeSize = 3;
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

	Guest(const Person& person, AgeType type, Feel feel);

	//getters
	const Ticket* getTicket() const;
	AgeType getType() const;
	Feel getFeel() const;

	//setters
	void setFeel(Feel feel);

	//actions
	void haveFun() const; //print the guest feeling

	//print
	friend ostream& operator<<(ostream& os, const Guest& g);

private:
	Ticket* ticket;
	AgeType type;
	Feel feel;
};

#endif