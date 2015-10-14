#include <ostream>
#include <string>

using namespace std;

class IObserver
{
public:	
	IObserver(const string& name) : name(name) {}
	/*IObserver(const string& name1) : name1(name1) {}*/
	virtual void notify(const string& name, int precentage) const = 0;
	virtual IObserver* clone() const = 0;
	const string& getName() const { return name; }
	

}; 
