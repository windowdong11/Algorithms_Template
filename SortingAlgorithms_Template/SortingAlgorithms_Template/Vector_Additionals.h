#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

/*
This function prints vector to output stream

*/
template<class T>
std::ostream& Print_VectorList(std::ostream& os, std::vector<T>& vec, std::string message = "")
{
	os << message << std::endl;
	auto end = vec.end();
	for (auto it = vec.begin(); it != end; ++it)
	{
		os << *it << " | ";
	}
	os << "[End]" << std::endl;
	return os;
}

/*
This function generates list, generates [from ~ to]

Need
1) prefix increment function Overloading
*/
template<class T>
void Generate_VectorList(std::vector<T>& list, T from, T to)
{
	for (; from <= to; ++from)
		list.push_back(from);
}

template<class T>
void Shuffle_VectorList(std::vector<T>& list, int count)
{
	srand(static_cast<unsigned int>(time(NULL)));

	int listsize = list.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < listsize; j++)
		{
			int rand1 = rand() % listsize;
			int rand2 = rand() % listsize;
			auto tmp = list[rand1];
			list[rand1] = list[rand2];
			list[rand2] = tmp;
		}
	}
}

template<class T>
bool isSorted(std::vector<T>& list)
{
	int end = list.size() - 1;
	for (int idx = 0; idx < end; ++idx)
	{
		if (list[idx] > list[idx])
			return false;
	}
	return true;
}