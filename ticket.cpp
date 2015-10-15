#include "ticket.h"
#include <string.h>

Ticket::Ticket(const string& date, double price) : price(price), date(date)
{
}

Ticket::~Ticket()
{
}

//getters
double Ticket::getPrice() const
{
	return price;
}

const string& Ticket::getDate() const
{
	return date;
}

//setters
void Ticket::setPrice(double price)
{
	this->price = price;
}

void Ticket::setDate(const string& date)
{
	this->date = date;
}

//print
ostream& operator<<(ostream& os, const Ticket& t)
{
	os << "date:"  << t.date << " cost " << t.price << " ";
	t.toOs(os);
	return os;
}

void Ticket::toOs(ostream& os) const
{
}
