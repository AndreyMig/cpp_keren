#include "guest.h"

const string ageTypes[3] = { "Child", "Adult", "Elder" };
const string feels[3] = { "Happy", "Afraid", "Thrilled" };

Guest::Guest(const Person& person, AgeType type, Feel feel, const Ticket& ticket) : Person(person), IObserver(person.getName()), type(type), feel(feel), ticket(&ticket)
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
	os << Person::name << " : I am " << feels[feel] << endl;
}

//Observer method
void Guest::notify(const string& observerName, int precentage, ostream& os) const
{
	os << observerName << ": Discount in food section??  "<< precentage <<"% ???? I HAVE TO GET THERE NOW!!" << endl;
}

//print
ostream& operator<<(ostream& os, const Guest& g)
{
	os << (Person&)g << endl;
	os << "is " << ageTypes[g.type] << " and is " << feels[g.feel];
	return os;
}