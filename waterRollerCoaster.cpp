#include "waterRollerCoaster.h"

WaterRollerCoaster::WaterRollerCoaster(const WaterSlide& slide,const RollerCoaster& rollerCoaster)
	: Facility(slide), WaterSlide(slide), RollerCoaster(rollerCoaster)
{
}

//print
ostream& operator<<(ostream& os, const WaterRollerCoaster& wrc)
{
	os << "**WaterRollerCoaster**" << endl;
	os << literOfWater << " liters of water" << endl;
	os << height << " meters " << numOfLoops << " loops" << endl;
	os << (Facility&)wrc;
	return os;
}