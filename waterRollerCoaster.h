#ifndef __WATER_ROLLER_COASTER_H
#define __WATER_ROLLER_COASTER_H

#include <ostream>
#include "waterSlide.h"
#include "rollerCoaster.h"

using namespace std;

class WaterRollerCoaster : public WaterSlide, public RollerCoaster
{
public:
	WaterRollerCoaster(const WaterSlide& ws, const RollerCoaster& rc);

	//print
	friend ostream& operator<<(ostream& os, const WaterRollerCoaster& wrc);

private:
	WaterRollerCoaster(const WaterRollerCoaster& other);
	const WaterRollerCoaster& operator=(const WaterRollerCoaster& other);
};

#endif