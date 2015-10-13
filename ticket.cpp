#pragma warning(disable: 4996 4290)
#include "ticket.h"
#include <string.h>

Ticket::Ticket(const string date, double price) throw(const string) : price(price)
{
	setDate(date);
}

Ticket::~Ticket()
{
}

//getters
double Ticket::getPrice() const
{
	return price;
}

const string Ticket::getDate() const
{
	return date;
}

//setters
void Ticket::setPrice(double price)
{
	this->price = price;
}

void Ticket::setDate(const string date) throw(const string)
{
	//check if date is in valid len
	unsigned int sizeOfDate = sizeof(this->date)/sizeof(this->date[0]);
	if(this->date.length() >= sizeOfDate)
		throw "Date is too long - do not exceed the format dd/mm/yyyy";

	this->date = date;
}

//print
ostream& operator<<(ostream& os, const Ticket& t)
{
	os << "Ticket date:"  << t.date << " cost " << t.price;
	return os;
}

