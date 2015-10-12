#pragma warning(disable: 4996 4290)
#include "person.h"

Person::Person(const char* name, int age, double height) : name(NULL), age(age), height(height)
{
	setName(name);
}

Person::Person(const Person& other) : name(NULL)
{
	*this = other;
}

Person::~Person()
{
	delete[] name;
}

const Person& Person::operator=(const Person& other)
{
	if(this != &other)
	{
		setName(other.name);
		this->age = other.age;
		this->height = other.height;
	}
	return *this;
}

//getters
const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

double Person::getHeight() const
{
	return height;
}

//setters
void Person::setName(const char* name)
{
	delete[] this->name;
	this-> name = strdup(name);
}

void Person::setAge(int age) throw (const char*)
{
	if(age < 0)
		throw "Age must be greater than 0";
	this->age = age;
}

void Person::setHeight(double height) throw (const char*)
{
	if(height < 0)
		throw "Height must be greater than 0";
	this->height = height;
}

//print
ostream& operator<<(ostream& os, const Person& p)
{
	os << p.name << " (" << p.age << "yo," << p.height << "m)";
	return os;
}

