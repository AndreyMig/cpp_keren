#include "waterRollerCoaster.h"

WaterRollerCoaster::WaterRollerCoaster(const WaterSlide& slide,const RollerCoaster& rollerCoaster)
	: Facility(slide), WaterSlide(slide), RollerCoaster(rollerCoaster)
{
}

//print
ostream& operator<<(ostream& os, const WaterRollerCoaster& wrc)
{
	os << "**WaterRollerCoaster**" << endl;
	os << wrc.literOfWater << " liters of water" << endl;
	os << wrc.height << " meters " << wrc.numOfLoops << " loops" << endl;
	os << (Facility&)wrc;
	return os;
}