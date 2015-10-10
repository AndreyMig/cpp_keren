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
	this->name = strdup(name);
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
const Facility** Park::getFacilities() const
{
	return this->facilities;
}
Facility** Park::getFacilities(){
	return this->facilities;
}
const Operator** Park::getOperators() const
{
	return this->operators;
}
Operator** Park::getOperators(){
	return this->operators;
}
const Guest** Park::getGuests() const{
	return this->guests;
}
Guest** Park::getGuests(){
	return this->guests;
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

	//return *this;
}

Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, bool isVip = false){

	Guest *newGuest = new Guest(person, type, feel);



	//TODO check that it is correct that it returns value not address
	return *newGuest;

}

/*Add guest to park*/
const Park& operator+=(const Guest& guest){


	return *this;
}
/*Remove guest from park*/
const Park& operator-=(const Guest& guest){

}


Park::~Park(){
	//TODO DESTROY ALL DYNAMIC
}

