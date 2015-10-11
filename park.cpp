#pragma warning(disable: 4996)
#include "park.h"

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

Park::Park(const Park& other) : name(NULL)
{
	*this = other;
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

//TODO I removed all const returning get functions 
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
const Park& Park::operator=(const Park& other)
{
	if (this != &other)
	{
		setName(other.name);
		this->maxFacilities = other.maxFacilities;
		this->maxOperators = other.maxOperators;
		this->maxGuests = other.maxGuests;
	}

	return *this;
}

Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, char date[], bool isVip, VIPTicket::VIPType vipKind) throw (const char*)
{

	//Check that the max number of guests is not exceeded
	if (this->numOfGuests >= this->maxGuests)
	{
		throw "Max number of guests, Can't add more.";
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
const Park& Park::operator+=(Guest& guest)
{
	this->guests[this->numOfGuests++] = &guest;
	return *this;
}

/*Remove guest from park*/
const Park& Park::operator-=(const Guest& guest)
{
	
	//TODO TEST

	return *this;
}


//print
ostream& operator<<(ostream& os, const Park& p)
{
	os << "Park : " << p.name << endl;
	os << "Number of facilities in park  : " << p.numOfFacilities << "out of "<< p.maxFacilities <<"possible"<< endl;
	os << "Number of Guests in park  : " << p.numOfGuests << "out of " << p.maxGuests << "possible" << endl;
	
	return os;
}

