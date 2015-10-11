#ifndef __TICKET_H
#define __TICKET_H

#include <ostream>
using namespace std;

class Ticket
{
public:
	Ticket(const char* date, double price);
	virtual ~Ticket();

	//getters
	double getPrice() const;
	const char* getDate() const;

	//setters
	void setPrice(double price);
	void setDate(const char* date);

	//print
	friend ostream& operator<<(ostream& os, const Ticket& t);

private:
	double price;
	char date[11]; //  (dd/mm/yyyy) + '/0' [e.g -  "24/08/2015"]
};

#endif // !__TICKET_H
