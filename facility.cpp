#pragma warning(disable: 4996 4290)

#include "facility.h"
#include "vipTicket.h"
#include "utils.h"
#include <typeinfo.h>

Facility::Facility(const char* name, int maxNumOfPassangers, bool ageTypeAvailable[], Operator* mainOperator, bool needVIPTicket) : 
name(NULL), maxNumOfPassangers(maxNumOfPassangers), mainOperator(mainOperator), needVIPTicket(needVIPTicket), numOfPassengers(0)
{
	setName(name);

	guests = new Guest*[this->maxNumOfPassangers];

	copyArrays(ageTypeAvailable,this->ageTypeAvailable,Guest::AGE_TYPE_SIZE);
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

		this->guests = new Guest*[this->maxNumOfPassangers];
		copyArrays(other.ageTypeAvailable,this->ageTypeAvailable,Guest::AGE_TYPE_SIZE);

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

const Guest*const* Facility::getGuests() const
{
	return guests;
}

const Operator& Facility::getOperator() const
{
	return *mainOperator;
}

//setters

//maximum number of guests to get on ride
void Facility::setMaxNumOfPassengers(int maxNumOfPassangers) throw (const char*)
{
	//check if there are already more guests then allowed then take some off
	if(maxNumOfPassangers < this->numOfPassengers) 
		throw "Can't limit the capacity of facility because there are more people in the facility.";

	this->maxNumOfPassangers = maxNumOfPassangers;
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

void Facility::setAgeTypeByIndex(int index, bool allowed) throw (const char*)
{
	int ix = index % Guest::AGE_TYPE_SIZE;
	if(ix != index)
		throw "Illegal index.";

	ageTypeAvailable[ix] = allowed;
}

//actions
//start the facility (start each passenger "have fun" action, and remove guests!!!!) 
void Facility::start(ostream& o) throw (const char*)
{
	if(mainOperator == NULL)
		throw "No Operator yet, can't activate facility.";

	o << "** " << name << " started **" << endl;
	for(int i = 0; i < numOfPassengers; i++)
	{
		guests[i]->haveFun(o);
		guests[i] = NULL;
	}
	o << endl;
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
			throw "Guest need to have a VIP Ticket.";
	}

	guests[this->numOfPassengers++] = &passenger;
	return *this;
}

// remove a passenger to passengers list
const Facility& Facility::operator-=(const Guest& passenger) throw(const char*)
{
	//look for the guest
	int guestLocation = findPointerInArray(&passenger, (void**)guests, numOfPassengers);

	if(guestLocation == -1)
		throw "Guest not found";

	//close gaps 
	closeGaps(guestLocation, (void**)guests, numOfPassengers);

	return *this;
}

const Facility& Facility::operator--() throw (const char*)
{
	if(numOfPassengers > maxNumOfPassangers-1)
		throw "Can't change the waiting line size, there are people waiting in line";

	maxNumOfPassangers--;
	return *this;
}

//print
ostream& operator<<(ostream& os, const Facility& f)
{
	os << "Facility : " << f.name << endl;
	os << "Operator : " << *f.mainOperator << endl;

	if(f.needVIPTicket)
		os << "[Facility Require VIP Ticket]" << endl;

	if(f.numOfPassengers > 0)
	{
		os << "Waiting in line:" << endl;
		for(int i = 0; i < f.numOfPassengers; i++)
		{
			os << *f.guests[i] << endl;
		}
	}
	else
		os << "Facility has no waiting line." << endl;

	os << endl;
	return os;
}
