#pragma warning(disable: 4290)

#include "facility.h"
#include "vipTicket.h"
#include <string.h>
#include <typeinfo.h>
#include <algorithm>


Facility::Facility(const string& name, vector<bool> ageTypeAvailable, Operator* mainOperator, bool needVIPTicket)
	: name(name), mainOperator(mainOperator), needVIPTicket(needVIPTicket), ageTypeAvailable(ageTypeAvailable)
{} 

Facility::Facility(const Facility& other)
{
	*this = other;
}

Facility::~Facility()
{}

const Facility& Facility::operator=(const Facility& other)
{
	if(this != &other)
	{
		this->name = other.name;
		this->ageTypeAvailable = other.ageTypeAvailable;
		this->needVIPTicket = other.needVIPTicket;
		this->guests = other.guests;
		this->mainOperator = other.mainOperator;
	}
	return *this;
}

//getters
bool Facility::doesNeedVIPTicket() const
{
	return needVIPTicket;
}

const string& Facility::getName() const
{
	return name;
}

const vector<bool> Facility::getAgeTypeAvailable() const
{
	return ageTypeAvailable;
}

const MyLinkedList<Guest*> Facility::getGuests() const
{
	return guests;
}

const Operator& Facility::getOperator() const
{
	return *mainOperator;
}

//setters
void Facility::setNeedVIPTicket(bool needVIPTicket)
{
	this->needVIPTicket = needVIPTicket;
}

void Facility::setName(const string& name)
{
	this->name = name;
}

void Facility::setAgeTypeByIndex(int index, bool allowed) throw (const string)
{
	int ix = index % Guest::AgeTypeSize;
	if(ix != index)
		throw "Illegal index.";

	ageTypeAvailable[ix] = allowed;
}

void Facility::setOperator(Operator& mainOperator)
{
	this->mainOperator = &mainOperator;
}

//start the facility (start each passenger "have fun" action, and remove guests!!!!) 
void Facility::start(ostream& o) throw (const char*)
{
	if(mainOperator == NULL)
		throw "No Operator yet, can't activate facility.";

	o << "** " << name << " started **" << endl;

	Node<Guest*>* cur = guests.getHead();
	while(cur != NULL)
	{
		Guest* g = cur->getValue();
		g->haveFun(o);
		cur = cur->getNext();
	}

	o << endl;
	guests.clear();
}

// add a passenger to passengers list 
const Facility& Facility::operator+=(Guest& passenger) throw (const string)
{
	//check if has vip is needed and if guest have a vip ticket
	if(needVIPTicket)
	{
		const Ticket* t = passenger.getTicket();
		if(typeid(*t) != typeid(VIPTicket))
			throw "Guest need to have a VIP Ticket.";
	}

	guests.addLast(&passenger);
	return *this;
}

// linkedlist works on guest* and sending const means working on const guest*
// remove a passenger to passengers list
const Facility& Facility::operator-=(Guest& passenger) throw(const string)
{
	if(!guests.isContained(&passenger))
		throw "Guest not found";

	guests.deleteElement(&passenger);

	return *this;
}

//print
ostream& operator<<(ostream& os, const Facility& f)
{
	os << "Facility : " << f.name << endl;
	os << "Operator : " << *f.mainOperator << endl;

	if(f.needVIPTicket)
		os << "[Facility Require VIP Ticket]" << endl;

	const Node<Guest*>* cur = f.guests.getHead();
	if(cur != NULL)
	{
		os << "Waiting in line:" << endl;
		while(cur != NULL)
		{
			Guest* g = cur->getValue();
			os << *g << endl;
			cur = cur->getNext();
		}
	}
	else
		os << "Facility has no waiting line." << endl;

	os << endl;
	return os;
}
