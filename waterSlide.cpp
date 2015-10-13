#include "waterSlide.h"

WaterSlide::WaterSlide(const Facility& facility, int literOfWater) : Facility(facility), literOfWater(literOfWater)
{
}

WaterSlide::WaterSlide(const WaterSlide& other) : Facility(other)
{
	*this = other;
}

WaterSlide::~WaterSlide()
{
}

const WaterSlide& WaterSlide::operator=(const WaterSlide& other)
{
	if(this != &other)
	{
		Facility::operator=(other);
		this->literOfWater = other.literOfWater;
	}
	return *this;
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

