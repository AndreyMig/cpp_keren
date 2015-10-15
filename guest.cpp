#include "guest.h"

const char* ageTypes[3] = {"Child", "Adult", "Elder"};
const char* feels[3] = {"Happy", "Afraid", "Thrilled"};

Guest::Guest(const Person& person, AgeType type, Feel feel, const Ticket& ticket) : Person(person), type(type), feel(feel), ticket(&ticket)
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

void Guest::setAgeType(AgeType type)
{
	this->type = type;
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