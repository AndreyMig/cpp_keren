#pragma warning(disable: 4996 4290)

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

const string& Facility::getFacilityName() const
{
	return name;
}

const vector<bool> Facility::getAgeTypeAvailable() const
{
	return ageTypeAvailable;
}

const vector<const Guest*> Facility::getGuests() const
{
	return guests;
}


//setters
void Facility::setNeedVIPTicket(bool needVIPTicket)
{
	this->needVIPTicket = needVIPTicket;
}

void Facility::setFacilityName(const string& name)
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


//start the facility (start each passenger "have fun" action, and remove guests!!!!) 
void Facility::start(ostream& o)
{
	o << "** " << name << " started **" << endl;

	vector<const Guest*>::iterator  itr    = guests.begin();
	vector<const Guest*>::iterator  itrEnd = guests.end();
	for (; itr!= itrEnd; ++itr)
		(*itr)->haveFun(o);

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

	guests.push_back(&passenger);
	return *this;
}

// remove a passenger to passengers list
const Facility& Facility::operator-=(const Guest& passenger) throw(const string)
{
	vector<const Guest*>::iterator  found;

	found = find(guests.begin(), guests.end(), &passenger);

	if(found == guests.end())
		throw "Guest not found";

	guests.erase(found);

	return *this;
}

//print
ostream& operator<<(ostream& os, const Facility& f)
{
	os << "Facility : " << f.name << endl;
	os << "Operator : " << *f.mainOperator << endl;

	if(f.needVIPTicket)
		os << "[Facility Require VIP Ticket]" << endl;

	if(f.guests.size() > 0)
	{
		os << "Waiting in line:" << endl;

		vector<const Guest*>::const_iterator  itr    = f.guests.begin();
		vector<const Guest*>::const_iterator  itrEnd = f.guests.end();
		for (; itr!= itrEnd; ++itr)
			os << *(*itr) << endl;
	}
	else
		os << "Facility has no waiting line." << endl;

	os << endl;
	return os;
}
