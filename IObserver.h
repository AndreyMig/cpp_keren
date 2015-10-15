#ifndef __IOBSERVER_H
#define __IOBSERVER_H

#include <string>

class IObserver
{
	string observerName;
public:	
	IObserver(const string& observerName) : observerName(observerName) {}
	virtual void notify(const string& observerName, int precentage, ostream& os=cout) const =0;
	const string& getObserverName() const { return observerName; }
}; 

#endif
