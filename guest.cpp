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

//Observer methods
void Guest::notify(const string& name, int precentage) const{

	//TODO is it okay that virtual is definde in guest.h but not here?

	cout << "Icecream is now cheaper by "<< precentage <<"% ???? I HAVE TO GET IT NOW!!" << "'\n";


}

//print
ostream& operator<<(ostream& os, const Guest& g)
{
	os << (Person&)g << endl;
	os << "is " << ageTypes[g.type] << " and is " << feels[g.feel];
	return os;
}