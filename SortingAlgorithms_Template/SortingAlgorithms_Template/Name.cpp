#include "Name.h"

void Name::setName(std::string name)
{
	name_ = name;
}

std::string Name::getName()
{
	return name_;
}

std::ostream& operator<<(std::ostream& os, const Name& name)
{
	os << name.name_;
	return os;
}
