#ifndef __VIP_TICKET_H
#define __VIP_TICKET_H

#include <ostream>
#include "ticket.h"
using namespace std;

class VIPTicket : public Ticket
{
public:
	enum VIPType
	{
		FIRST_CLASS,
		FAST_LINE
	};

	VIPTicket(const Ticket& ticket, VIPType theType) ;
	
	VIPType getTicketType() const;
	void setType(VIPType type);

	//print
	friend ostream& operator<<(ostream& os, const VIPTicket& t);

private:
	VIPType type;
};


#endif