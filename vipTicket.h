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
		FREE_FOOD
	};

	VIPTicket(const Ticket& ticket, VIPType theType) ;
	
	VIPType getTicketType() const;
	void setType(VIPType type);

	//print
	virtual void toOs(ostream& os) const;

private:
	VIPType type;
};


#endif