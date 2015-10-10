#ifndef __WATER_SLIDE_H
#define __WATER_SLIDE_H

#include <ostream>
#include "facility.h"

class WaterSlide : virtual public Facility
{
public:
	WaterSlide(const Facility& facility, int literOfWater);

	int getLiterOfWater() const;
	void setLiterOfWater(int literOfWater);

	//print
	friend ostream& operator<<(ostream& os, const WaterSlide& ws);

protected:
	int literOfWater;
};

#endif