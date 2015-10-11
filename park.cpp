#include "park.h"

Park::Park(const char* name, int maxFacilities, int maxOperators, int maxGuests)
{
	
	setName(name);
	this->maxFacilities = maxFacilities;
	this->maxOperators = maxOperators;
	this->maxGuests = maxGuests;

}

Park::Park(const Park& other) : name(NULL)
{
	//TODO
	*this = other;
}

//setters
void Park::setName(const char* name)
{
	delete[] this->name;
	this->name = _strdup(name);
}
void Park::setFacilities(const Facility** facilities){
	//TODO   const?
	//this->facilities = facilities;

}
void Park::setOperators(const Operator** operators){
	//TODO   const?
}
void Park::setGuests(const Guest** guests){
	//TODO   const?
}


//getters
const char* Park::getName() const
{
	return name;
}

//TODO I removed all const returning get functions
//const Facility** Park::getFacilities() const
//{
//	return this->facilities;
//}

Facility** Park::getFacilities(){
	return this->facilities;
}
//
//const Operator** Park::getOperators() const
//{
//	return this->operators;
//}
Operator** Park::getOperators(){
	return this->operators;
}
//
//const Guest** Park::getGuests() const{
//	return this->guests;
//}
list<Guest*> Park::getGuests(){
	return this->guestsList;
}


//operators
const Park& Park::operator=(const Park& other)
{


	//TODO 

	//if (this != &other)
	//{
	//	setName(other.name);
	//	this->maxFacilities = other.maxFacilities;
	//	this->maxOperators = other.maxOperators;
	//	this->maxGuests = other.maxGuests;

	//}

	return *this;
}

Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, bool isVip) 
{

	//Check that the max number of guests is not exceeded
	if (this->numOfGuests < this->maxGuests)
	{
		//TODO how to handle max num exceeded
		//throw "Max number of guests, Can't add more.";
	}

	Guest *newGuest = new Guest(person, type, feel);


	*this += *newGuest;


	//TODO check that it is correct that it returns value not address
	return *newGuest;

}

/*Add guest to park*/
const Park& Park::operator+=(Guest& guest)
{
	this->guestsList.push_back(&guest);
	this->numOfGuests++;
	//this->guests[this->numOfGuests++] = &guest;
	return *this;
}

/*Remove guest from park*/
const Park& Park::operator-=(const Guest& guest)
{
	
	//TODO TEST

	list<Guest*>::iterator  itr = this->guestsList.begin();
	list<Guest*>::iterator  itrEnd = this->guestsList.end();
	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(((Guest*)*itr)->getName(), guest.getName()) == 0)
		{
			this->guestsList.erase(itr);
			return *this;
		}
		
	}
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



Park::~Park(){
	//TODO DESTROY ALL DYNAMIC
}

