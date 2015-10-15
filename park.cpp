#pragma warning(disable: 4996 4290)
#include "park.h"
#include "utils.h"

const double Park::TICKET_PRICE = 150.0;
const double Park::VIP_TICKET_PRICE = 250.0;

Park::Park(const char* name, int maxFacilities, int maxOperators, int maxGuests)
	: name(NULL), maxFacilities(maxFacilities), maxOperators(maxOperators), maxGuests(maxGuests)
{
	setName(name);
	this->facilities = new Facility*[maxFacilities];
	this->operators = new Operator*[maxOperators];
	this->guests = new Guest*[maxGuests];

	numOfOperators = 0;
	numOfFacilities = 0;
	numOfGuests = 0;
}

Park::~Park(){
	delete[] facilities;
	delete[] operators;
	delete[] guests;
}

//setters
void Park::setName(const char* name)
{
	delete[] this->name;
	this->name = strdup(name);
}

//getters
const char* Park::getName() const
{
	return name;
}

const Facility*const* Park::getFacilities() const
{
	return this->facilities;
}

const Operator*const* Park::getOperators() const
{
	return this->operators;
}


const Guest*const* Park::getGuests() const
{
	return this->guests;
}

//operators
Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, char date[], bool isVip, VIPTicket::VIPType vipKind) throw (const char*)
{

	//Check that the max number of guests is not exceeded
	if (this->numOfGuests >= this->maxGuests)
	{
		throw "Reached guests capacity.";
	}

	Ticket *t;

	if(isVip)
		t = new VIPTicket(Ticket(date,VIP_TICKET_PRICE),vipKind);
	else
		t = new Ticket(date,VIP_TICKET_PRICE);

	Guest *newGuest = new Guest(person, type, feel, *t);

	*this += *newGuest;

	return *newGuest;
}
 
/*Add guest to park*/
const Park& Park::operator+=(Guest& guest) throw (const char*)
{
	if (this->numOfGuests >= this->maxGuests)
		throw "Reached guests capacity.";

	this->guests[this->numOfGuests++] = &guest;
	return *this;
}

/*Remove guest from park*/ 
const Park& Park::operator-=(const Guest& guest) throw (const char*)
{
	int ix = findPointerInArray(&guest, (void**)guests, numOfGuests);
	if(ix == -1)
		throw "Guest not found";

	closeGaps(ix, (void**)guests, numOfGuests);

	return *this;
}
//add facility to park
const Park& Park::operator+=(Facility& facility) throw (const char*)
{
	if (this->numOfFacilities >= this->maxFacilities)
		throw "Reached guests capacity.";

	this->facilities[this->numOfFacilities++] = &facility;
	return *this;
}
// remove facility from park
const Park& Park::operator-=(const Facility& facility) throw (const char*)
{
	int ix = findPointerInArray(&facility, (void**)facilities, numOfFacilities);
	if(ix == -1)
		throw "Facility not found";

	closeGaps(ix, (void**)facilities, numOfFacilities);
	return *this;
}

//add operator to park
const Park& Park::operator+=(Operator& theOperator) throw (const char*)
{
	if (this->numOfOperators >= this->maxOperators)
		throw "Reached operators capacity.";

	this->operators[this->numOfOperators++] = &theOperator;
	return *this;
}
// remove operator from park
const Park& Park::operator-=(const Operator& theOperator) throw (const char*)
{
	int ix = findPointerInArray(&theOperator, (void**)operators, numOfOperators);
	if(ix == -1)
		throw "Operator not found";

	closeGaps(ix, (void**)operators, numOfOperators);
	return *this;
}


const Operator& Park::operator[] (int id) const throw(const char*)
{
	const Operator* g = NULL;

	for(int i = 0; i < numOfOperators; i++)
	{
		if(operators[i]->getID() == id)
		{
			g = operators[i];
			break;
		}
	}

	if(g)
		return *g;

	throw "Operator not found..";
}

//print
ostream& operator<<(ostream& os, const Park& p)
{
	os << ">>>>>>>> Welcome to the Park : " << p.name << " <<<<<<<<" << endl;
	if(p.numOfFacilities > 0)
	{
		os << "* Facilities *" << endl;
		for(int i = 0; i < p.numOfFacilities; i++)
		{
			os << "--------------------" << endl;
			os << *p.facilities[i] << endl;
			os << "--------------------" << endl;
		}
	}
	else
		os << "Park has no facilites yet." << endl;
	os << endl;
	return os;
}

