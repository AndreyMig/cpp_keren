#include "vipTicket.h"

const char* vipTypes[2] = {"First Class","Fast Line"};

VIPTicket::VIPTicket(const Ticket& ticket, VIPType theType) : Ticket(ticket), type(theType)
{
}

VIPType VIPTicket::getTicketType() const
{
	return type;
}

void VIPTicket::setType(VIPType type)
{
	this->type = type;
}

//print
ostream& operator<<(ostream& os, const VIPTicket& t)
{
	os << (Ticket&)t << " VIP details: " << vipTypes[t.type];
	return os;
}
