#include "rollerCoaster.h"

RollerCoaster::RollerCoaster(const Facility&  facility,int height,int numOfLoops)
	:Facility(facility), height(height), numOfLoops(numOfLoops)
{
}

RollerCoaster::RollerCoaster(const RollerCoaster& other) : Facility(other)
{
	*this = other;
}

RollerCoaster::~RollerCoaster()
{
}

const RollerCoaster& RollerCoaster::operator=(const RollerCoaster& other)
{
	if(this != &other)
	{
		Facility::operator=(other);
		this->height = other.height;
		this->numOfLoops = other.numOfLoops;
	}
	return *this;
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
	os << "** RollerCoaster(" << rc.height << " m " << rc.numOfLoops << " loops" << ") **" << (Facility&)rc;
	return os;
}
  