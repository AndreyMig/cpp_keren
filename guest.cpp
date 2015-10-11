#include "guest.h"
#include <iostream>

const char* ageTypes[3] = {"Child", "Adult", "Elder"};
const char* feels[3] = {"Happy", "Afraid", "Thrilled"};

Guest::Guest(const Person& person, AgeType type, Feel feel) : Person(person), type(type), feel(feel), ticket(NULL)
{
}

//getters
const Ticket* Guest::getTicket() const
{
	return ticket;
}

Guest::AgeType Guest::getType() const
{
	return type;
}

Guest::Feel Guest::getFeel() const
{
	return feel;
}

//setters
void Guest::setFeel(Feel feel)
{
	this->feel = feel;
}

//actions
//print the guest feeling
void Guest::haveFun(ostream& os) const
{
	os << name << " : I am " << feels[feel] << endl;
}

//print
ostream& operator<<(ostream& os, const Guest& g)
{
	os << (Person&)g << endl;
	os << "is " << ageTypes[g.type] << " and is " << feels[g.feel];
	return os;
}