#include "rollerCoaster.h"

RollerCoaster::RollerCoaster(const Facility&  facility,int height,int numOfLoops)
	:Facility(facility), height(height), numOfLoops(numOfLoops)
{
}

//getters
int RollerCoaster::getHeight() const
{
	return height;
}

int RollerCoaster::getNumOfLoops() const
{
	return numOfLoops;
}

//setters
void RollerCoaster::setHeight(int height)
{
	this->height = height;
}

void RollerCoaster::setNumOfLoops(int numOfLoops)
{
	this->numOfLoops = numOfLoops;
}

//print
ostream& operator<<(ostream& os, const RollerCoaster& rc)
{
	os << "** RollerCoaster(" << rc.height << " m " << rc.numOfLoops << " loops" << ") **" << (Facility)rc;
	return os;
}
