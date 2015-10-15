#include "waterRollerCoaster.h"

WaterRollerCoaster::WaterRollerCoaster(const WaterSlide& ws, const RollerCoaster& rc) : Facility(ws), WaterSlide(ws), RollerCoaster(rc)
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