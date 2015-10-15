 #ifndef __GUEST_H
#define __GUEST_H

#include <ostream>
#include <iostream>
#include <string>
#include "person.h"
#include "ticket.h"
#include "IObserver.h"
using namespace std;
 
class Guest : public Person, public IObserver
{
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

	virtual void notify(const string& observerName, int precentage, ostream& os=cout) const;

private:
	const Ticket* ticket; // pointer because polymorphism (can be ticket or vip ticket)
	AgeType type;
	Feel feel;

	Guest(const Guest& other);
	const Guest& operator=(const Guest& other);
};

#endif