#pragma warning(disable: 4290)
#include "park.h"
#include <algorithm>

const double Park::TICKET_PRICE = 150.0;
const double Park::VIP_TICKET_PRICE = 250.0;

Park::Park(const string& name) : name(name)
{}

//setters
void Park::setName(const string& name)
{
	this->name = name;
}

//getters
const string& Park::getName() const
{
	return name;
}

const vector<Facility*> Park::getFacilities() const
{
	return this->facilities;
}

const vector<Operator*> Park::getOperators() const
{
	return this->operators;
}

const MyLinkedList<Guest*> Park::getGuests() const
{
	return this->guests;
}

Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, const string& date, bool isVip, VIPTicket::VIPType vipKind)
{
	Ticket *t;

	if(isVip)
		t = new VIPTicket(Ticket(date,VIP_TICKET_PRICE),vipKind);
	else
		t = new Ticket(date,VIP_TICKET_PRICE);

	Guest *newGuest = new Guest(person, type, feel, *t);

	*this += newGuest;

	return *newGuest;
}

/*Add guest to park*/
const Park& Park::operator+=(Guest* guest)
{
	this->guests.addLast(guest);
	return *this;
}

/*Remove guest from park*/
/* guest is not const because T type in template class is a pointer and 
const obj* make the obj itself const and therefore can't comply with the template class because 
const T& of isContained is equivalent to Guest* const&(const on pointer) and they are not compatiable*/
const Park& Park::operator-=(Guest* guest) throw (const string)
{
	if(!guests.isContained(guest))
		throw "Guest not found.";

	guests.deleteElement(guest);
	return *this;
}

//add facility to park
const Park& Park::operator+=(Facility& facility)
{
	facilities.push_back(&facility);
	return *this;
}
// remove facility from park
const Park& Park::operator-=(const Facility& facility) throw (const string)
{
	vector<Facility*>::iterator found = find(facilities.begin(), facilities.end() ,&facility);

	if(found == facilities.end())
		throw "Facility not found";

	facilities.erase(found);

	return *this;
}

//add operator to park
const Park& Park::operator+=(Operator& _operator)
{
	operators.push_back(&_operator);
	return *this;
}
// remove operator from park
const Park& Park::operator-=(const Operator& _operator) throw (const string)
{
	vector<Operator*>::iterator found = find(operators.begin(), operators.end() ,&_operator);

	if(found == operators.end())
		throw "Operator not found";

	operators.erase(found);

	return *this;
}

const Operator& Park::operator[] (int id) const throw(const string)
{
	const Operator* g = NULL;

	vector<Operator*>::const_iterator  itr    = operators.begin();
	vector<Operator*>::const_iterator  itrEnd = operators.end();
	for (; itr!= itrEnd; ++itr)
	{
		if((*itr)->getID() == id)
		{
			g = *itr;
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
	if(p.facilities.size() > 0)
	{
		os << "* Facilities *" << endl;

		vector<Facility*>::const_iterator  itr    = p.facilities.begin();
		vector<Facility*>::const_iterator  itrEnd = p.facilities.end();
		for (; itr!= itrEnd; ++itr)
		{
			os << "--------------------" << endl;
			os << *(*itr) << endl;
			os << "--------------------" << endl;
		}
	}
	else
		os << "Park has no facilites yet." << endl;
	os << endl;
	return os;
}

