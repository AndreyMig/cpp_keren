#pragma warning(disable: 4290)
#include "person.h"

Person::Person(const string& name, int age, double height) : name(name), age(age), height(height)
{}

Person::Person(const Person& other)
{
	*this = other;
}

Person::~Person()
{
}

const Person& Person::operator=(const Person& other)
{
	if(this != &other)
	{
		this->name = other.name;
		this->age = other.age;
		this->height = other.height;
	}
	return *this;
}

//getters
const string& Person::getName() const
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
void Person::setName(const string& name)
{
	this->name = name;
}

void Person::setAge(int age) throw (const string)
{
	if(age < 0)
		throw "Age must be greater than 0";
	this->age = age;
}

void Person::setHeight(double height) throw (const string)
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

