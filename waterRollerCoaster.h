#ifndef __WATER_ROLLER_COASTER_H
#define __WATER_ROLLER_COASTER_H

#include <ostream>
#include "waterSlide.h"
#include "rollerCoaster.h"
#include "operator.h"
using namespace std;

class WaterRollerCoaster : public WaterSlide,public RollerCoaster
{
public:
	WaterRollerCoaster(const WaterSlide& slide,const RollerCoaster& rollerCoaster);

	//print
	friend ostream& operator<<(ostream& os, const WaterRollerCoaster& wrc);
};

#endif