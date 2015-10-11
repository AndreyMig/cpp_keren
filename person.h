#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>
using namespace std;
using namespace std;
 
class Person
{
public:
	Person(const char* name, int age, double height);
	virtual ~Person();

	//getters
	const char* getName() const;
	int getAge() const;
	double getHeight() const;

	//setters
	void setName(const char* name);
	void setAge(int age);
	void setHeight(double height);

	//print
	friend ostream& operator<<(ostream& os, const Person& p);

protected:
	char* name;
	int age;
	double height;

	Person(const Person& other);
	const Person& operator=(const Person& other);
};


#endif