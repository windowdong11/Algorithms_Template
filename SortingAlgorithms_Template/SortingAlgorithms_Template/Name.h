#pragma once
#include <ostream>
#include <string>

class Name
{
private:
	std::string name_;
public:
	void setName(std::string name);
	std::string getName();

public:
	Name() {}
	Name(std::string name) : name_(name) {}

	inline bool operator>(const Name& name)
	{
		const auto originlength = name_.length();
		const auto comparelength = name_.length();

		if (originlength > comparelength)
			return true;
		else if (originlength == comparelength)
		{
			for (size_t idx = 0; idx < originlength; ++idx)
			{
				if (name_[idx] > name.name_[idx])
					return true;
				else if (name_[idx] < name.name_[idx])
					return false;
			}
			return false; // same
		}
		else
			return false;
	}
	inline bool operator<(const Name& name)
	{
		const auto originlength = name_.length();
		const auto comparelength = name_.length();

		if (originlength < comparelength)
			return true;
		else if (originlength == comparelength)
		{
			for (size_t idx = 0; idx < originlength; ++idx)
			{
				if (name_[idx] < name.name_[idx])
					return true;
				else if (name_[idx] > name.name_[idx])
					return false;
			}
			return false; // same
		}
		else
			return false;
	}
	inline bool operator>=(const Name& name)
	{
		const auto originlength = name_.length();
		const auto comparelength = name_.length();

		if (originlength > comparelength)
			return true;
		else if (originlength == comparelength)
		{
			for (size_t idx = 0; idx < originlength; ++idx)
			{
				if (name_[idx] > name.name_[idx])
					return true;
				else if (name_[idx] < name.name_[idx])
					return false;
			}
			return true; // same
		}
		else
			return false;
	}
	inline bool operator<=(const Name& name)
	{
		const auto originlength = name_.length();
		const auto comparelength = name_.length();

		if (originlength < comparelength)
			return true;
		else if (originlength == comparelength)
		{
			for (size_t idx = 0; idx < originlength; ++idx)
			{
				if (name_[idx] < name.name_[idx])
					return true;
				else if (name_[idx] > name.name_[idx])
					return false;
			}
			return true; // same
		}
		else
			return false;
	}
	inline Name& operator++()
	{
		for (int idx = static_cast<int>(name_.length()) - 1; idx >= 0; --idx)
		{
			char& lastchar = name_[idx];
			if (lastchar < ('z' - 1) || lastchar < ('Z' - 1))
			{
				++lastchar;
				break;
			}
			else if (lastchar == 'Z')
			{
				lastchar = 'a';
				break;
			}
		}
		return *this;
	}

	inline Name operator++(int)
	{
		Name temp = *this;
		operator++();
		return temp;
	}

	friend std::ostream& operator<<(std::ostream& os, const Name& name);
};



