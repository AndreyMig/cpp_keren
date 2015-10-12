#pragma warning(disable: 4996)

#include "facility.h"
#include "vipTicket.h"
#include <string.h>
#include <typeinfo.h>


void copyArrays(const bool* src, bool* dst, int size)
{
	for(int i = 0; i < size; i++)
		dst[i] = src[i];
}

Facility::Facility(const char* name, int maxNumOfPassangers, bool ageTypeAvailable[], Operator* mainOperator, bool needVIPTicket) : 
name(NULL), maxNumOfPassangers(maxNumOfPassangers), mainOperator(mainOperator), needVIPTicket(needVIPTicket)
{
	setName(name);

	guests = new Guest*[this->maxNumOfPassangers];
	this->numOfPassengers = 0;

	copyArrays(ageTypeAvailable,this->ageTypeAvailable,Guest::AgeTypeSize);
}

Facility::Facility(const Facility& other) : name(NULL)
{
	*this = other;
}

Facility::~Facility()
{
	delete[] name;
	delete[] guests;
}

const Facility& Facility::operator=(const Facility& other)
{
	if(this != &other)
	{
		setName(other.name);
		setMaxNumOfPassengers(other.maxNumOfPassangers);
		setNeedVIPTicket(other.needVIPTicket);

		guests = new Guest*[this->maxNumOfPassangers];
		copyArrays(other.ageTypeAvailable,this->ageTypeAvailable,Guest::AgeTypeSize);

		this->numOfPassengers = other.numOfPassengers;
		this->mainOperator = other.mainOperator;

	}
	return *this;
}


//getters
int Facility::getMaxNumOfPassengers() const
{
	return maxNumOfPassangers;
}

bool Facility::doesNeedVIPTicket() const
{
	return needVIPTicket;
}

const char* Facility::getName() const
{
	return name;
}

const bool* Facility::getAgeTypeAvailable() const
{
	return ageTypeAvailable;
}

Guest** Facility::getGuests()
{
	return guests;
}


//setters

//maximum number of guests to get on ride
void Facility::setMaxNumOfPassengers(int maxNumOfPassangers)
{
	//check if there are already more guests then allowed then take some off
	if(maxNumOfPassangers < this->numOfPassengers) 
	{
		//int takeOffRide = this->numOfPassengers - maxNumOfPassangers;

		//for(int i = 0; i < takeOffRide; i++)
		//{
		//	guests[this->numOfPassengers-1-i] = NULL;
		//}

		//this->numOfPassengers -= takeOffRide;
		throw "Can't limit the capacity of facility because there are more people in the facility.";
	}
	else
	{
		this->maxNumOfPassangers = maxNumOfPassangers;
	}
}

void Facility::setNeedVIPTicket(bool needVIPTicket)
{
	this->needVIPTicket = needVIPTicket;
}

void Facility::setName(const char* name)
{
	delete[] this->name;
	this->name = strdup(name);
}

void Facility::setAgeTypeByIndex(int index, bool allowed)
{
	int ix = index % Guest::AgeTypeSize;
	ageTypeAvailable[ix] = allowed;
}

//actions
//start the facility (start each passenger "have fun" action, and remove guests!!!!) 
void Facility::start()
{
	for(int i = 0; i < numOfPassengers; i++)
	{
		guests[i]->haveFun();
		guests[i] = NULL;
	}

	numOfPassengers = 0;
}

// add a passenger to passengers list 
const Facility& Facility::operator+=(Guest& passenger) throw(const char*)
{
	//no more place
	if(numOfPassengers == maxNumOfPassangers)
		throw "Facility is full.";

	//check if has vip is needed and if guest have a vip ticket
	if(needVIPTicket)
	{
		const Ticket* t = passenger.getTicket();
		if(typeid(*t) != typeid(VIPTicket))
		{
			throw "Guest need to have a VIP Ticket.";
		}
	}

	guests[this->numOfPassengers++] = &passenger;
	return *this;
}

// remove a passenger to passengers list
const Facility& Facility::operator-=(const Guest& passenger) throw(const char*)
{
	int i;
	bool found = false;

	//look for the guest
	for(i = 0; i < numOfPassengers; i++)
	{
		if(guests[i] == &passenger)
		{
			guests[i] = NULL;
			found = true;
			break;
		}
	}

	//close gaps 
	if(found)
	{
		for(i++ ; i < numOfPassengers+1; i++)
		{
			guests[i-1] = guests[i];
		}
		numOfPassengers--;
	}
	else
	{
		throw "Guest not found";
	}

	return *this;
}

const Guest* Facility::findGuest(const char* guestName) const
{
	for(int i = 0; i < numOfPassengers; i++)
	{
		if(strcmp(guests[i]->getName(),guestName) == 0)
			return guests[i];
	}

	return NULL;
}

//THIS IS NOT GOOD (Keren to Shirin)
const Guest& Facility::operator[] (const char* guestName) const throw(const char*)
{
	const Guest* g = findGuest(guestName);
	if(g)
		return *g;

	throw "Guest not found..";
}

//print
ostream& operator<<(ostream& os, const Facility& f)
{
	os << "Facility : " << f.name << endl;
	os << "Operator : " << *f.mainOperator << endl;

	if(f.needVIPTicket)
		os << "[Facility Require VIP Ticket]" << endl;

	os << "Waiting in line:" << endl;
	for(int i = 0; i < f.numOfPassengers; i++)
	{
		os << *f.guests[i] << endl;
	}

	os << endl;

	return os;
}
