#ifndef __ROLLER_COASTER_H
#define __ROLLER_COASTER_H

#include <ostream>
#include "facility.h"
using namespace std;
 
class RollerCoaster : virtual public Facility
{
public:
	RollerCoaster(const Facility&  facility,int height,int numOfLoops);
	
	//getters
	int getHeight() const;
	int getNumOfLoops() const;

	//setters
	void setHeight(int height);
	void setNumOfLoops(int numOfLoops);

	//print
	friend ostream& operator<<(ostream& os, const RollerCoaster& rc);

private:
	int height;
	int numOfLoops;
};

#endif