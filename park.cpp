#pragma warning(disable: 4290)
#include "park.h"
#include <algorithm>

const double Park::TICKET_PRICE = 150.0;
const double Park::VIP_TICKET_PRICE = 250.0;

Park::Park(const string& name) : name(name)
{}

void deleteGuest(const Guest* g)
{
	delete g->getTicket();
	delete g;
}

Park::~Park()
{
	for_each(guests.begin(), guests.end(), deleteGuest);
}

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

const vector<Facility*>& Park::getFacilities() const
{
	return this->facilities;
}

const vector<Operator*>& Park::getOperators() const
{
	return this->operators;
}

const vector<Guest*>& Park::getGuests() const
{
	return this->guests;
}

Guest& Park::buyTicket(const Person& person, Guest::AgeType type, Guest::Feel feel, const string& date, bool isVip, VIPTicket::VIPType vipKind)
{
	Ticket *t;

	if(isVip)
		t = new VIPTicket(Ticket(date, VIP_TICKET_PRICE), vipKind);
	else
		t = new Ticket(date, TICKET_PRICE);

	Guest *newGuest = new Guest(person, type, feel, t);

	*this += *newGuest;

	return *newGuest;
}

//Add guest to park
const Park& Park::operator+=(Guest& guest)
{
	this->registerObserver(&guest);
	this->guests.push_back(&guest);
	return *this;
}

//Remove guest from park
const Park& Park::operator-=(const Guest& guest) throw (const string)
{
	vector<Guest*>::iterator found = find(guests.begin(), guests.end() ,&guest);
	
	if(found == guests.end())
		throw "Guest not found.";

	guests.erase(found);

	deleteGuest(&guest);

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
const Park& Park::operator+=(Operator& theOperator)
{
	operators.push_back(&theOperator);
	return *this;
}

// remove operator from park
const Park& Park::operator-=(const Operator& theOperator) throw (const string)
{
	vector<Operator*>::iterator found = find(operators.begin(), operators.end() ,&theOperator);

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
//observer pattern
void Park::registerObserver(const IObserver* obs)
{
	this->viewers.push_back(obs);
}

void Park::discountOnFoodSection(int precenatge) const
{
	vector<const IObserver*>::const_iterator  itr = viewers.begin();
	vector<const IObserver*>::const_iterator  itrEnd = viewers.end();
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->notify((*itr)->getObserverName(), precenatge);
	}
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

