#ifndef __TICKET_H
#define __TICKET_H

#include <ostream>
#include <string>
using namespace std;

class Ticket
{
public:
	Ticket(const string date, double price);
	virtual ~Ticket();

	//getters
	double getPrice() const;
	const string getDate() const;

	//setters
	void setPrice(double price);
	void setDate(const string date);

	//print
	friend ostream& operator<<(ostream& os, const Ticket& t);

private:
	double price;
	string date; //  (dd/mm/yyyy) + '/0' [e.g -  "24/08/2015"]
};

#endif // !__TICKET_H
