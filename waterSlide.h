#ifndef __WATER_SLIDE_H
#define __WATER_SLIDE_H

#include <ostream>
#include "facility.h"

class WaterSlide : virtual public Facility
{
public:
	WaterSlide(const Facility& facility, int literOfWater);
	virtual ~WaterSlide();

	int getLiterOfWater() const;
	void setLiterOfWater(int literOfWater);

	//print
	friend ostream& operator<<(ostream& os, const WaterSlide& ws);

protected:
	int literOfWater;

	WaterSlide(const WaterSlide& other);
	const WaterSlide& operator=(const WaterSlide& other);
};

#endif