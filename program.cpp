#include "park.h"
#include "waterSlide.h"
#include "rollerCoaster.h"
#include "waterRollerCoaster.h"

int main(int argc, const char* argv[])
{
	try
	{
		//init park
		Park disneyWorld("Disney World",10,15,100);
		//init operators
		Operator o1(Person("Keren", 19, 1.85));
		Operator o2(Person("Daniel", 21, 1.75));
		Operator o3(Person("Amir", 26, 1.60));
		Operator o4(Person("Eytan", 28, 1.80));

		disneyWorld += o1;
		disneyWorld += o2;
		disneyWorld += o3;
		disneyWorld += o4;
		
		//init facilities
		bool ageTypes[] = {true, true, false};
		WaterSlide waterSlide(Facility("KAMIKAZA", 2 , ageTypes, &o1), 800);
		ageTypes[2] = true;
		RollerCoaster rollerCoasterA(Facility("BALERINE", 30, ageTypes, &o2), 4, 0);
		ageTypes[0] = false;
		RollerCoaster rollerCoasterB(Facility("ANACONDA", 16, ageTypes, &o3), 30, 2);
		ageTypes[2] = false;
		Facility f("HYDRA", 12, ageTypes, &o4);
		WaterRollerCoaster waterRollerCoaster(WaterSlide(f,1000), RollerCoaster(f, 40, 7));

		disneyWorld += waterSlide;
		disneyWorld += rollerCoasterA;
		disneyWorld += rollerCoasterB;
		disneyWorld += waterRollerCoaster;

		//create persons to enter park
		Person p1("Adam",13,1.25);
		Person p2("Adir", 21, 1.55);
		Person p3("Adi", 27, 1.68);
		Person p4("Adva", 72, 1.45);

		Guest& g1 = disneyWorld.buyTicket(p1, Guest::CHILD, Guest::THRILLED,"09/09/2015");
		Guest& g2 = disneyWorld.buyTicket(p2, Guest::ADULT, Guest::HAPPY,"09/09/2015" ,true);
		Guest& g3 = disneyWorld.buyTicket(p3, Guest::ADULT, Guest::HAPPY,"08/09/2015");
		Guest& g4 = disneyWorld.buyTicket(p4, Guest::CHILD, Guest::AFRAID,"05/09/2015");

		//add guest to facility
		waterSlide += g1;
		waterSlide += g2;
		waterSlide.start(); //start() should remove all guests

		waterSlide += g3;
		waterSlide += g4;
		waterSlide.start();

		rollerCoasterA += g1;
		rollerCoasterA += g2;
		rollerCoasterA += g3;
		rollerCoasterA += g4;

		waterRollerCoaster += g1;
		waterRollerCoaster += g2;
		waterRollerCoaster += g3;
		waterRollerCoaster += g4;

		cout << disneyWorld << endl;
		rollerCoasterA.start();
		waterRollerCoaster.start();
		cout << disneyWorld << endl;
	}
	catch(const char* msg)
	{
		cout << "Problem occured..." << endl;
		cout << msg << endl;
		cout << "Finishing.." << endl;
	}
}