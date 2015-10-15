#include "vipTicket.h"

const string vipTypes[2] = { "First Class", "Fast Line" };

VIPTicket::VIPTicket(const Ticket& ticket, VIPType theType) :Ticket(ticket), type(theType)
{
}

void VIPTicket::setType(VIPType type)
{
	this->type = type;
}

VIPTicket::VIPType VIPTicket::getTicketType() const
{
	return type;
}

//print
void VIPTicket::toOs(ostream& os) const
{
	os << "[VIP type: " << vipTypes[type] << "]";
}

