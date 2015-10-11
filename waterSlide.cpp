#include "waterSlide.h"

WaterSlide::WaterSlide(const Facility& facility, int literOfWater) : Facility(facility), literOfWater(literOfWater)
{
}

int WaterSlide::getLiterOfWater() const
{
	return literOfWater;
}

void WaterSlide::setLiterOfWater(int literOfWater)
{
	this->literOfWater = literOfWater;
}

//print
ostream& operator<<(ostream& os, const WaterSlide& ws)
{
	os << "** WaterSlide(" << ws.literOfWater << " liters) **" << (Facility&)ws;
	return os;
}

