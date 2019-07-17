#pragma once
#include <vector>
#include <iostream>



template<class T>
void QuickSortTemplateWithArea(std::vector<T>& list, int begin, int end)
{
	int count = end - begin;
	if (count <= 1)
		return;

	int mid = begin + count / 2;
	int pivot = list[mid];

	std::vector<int> frontv, backv;
	for (auto it = begin; it < mid; ++it)
	{
		if (list[it] < pivot)
		{
			frontv.push_back(list[it]);
		}
		else
		{
			backv.push_back(list[it]);
		}
	}
	// skip mid
	for (auto it = mid + 1; it < end; ++it)
	{
		if (list[it] < pivot)
		{
			frontv.push_back(list[it]);
		}
		else
		{
			backv.push_back(list[it]);
		}
	}
	frontv.push_back(pivot);
	mid = frontv.size() + begin - 1;
	frontv.insert(frontv.end(), backv.begin(), backv.end());
	int copyend = frontv.size();
	for (int i = 0; i < copyend; ++i)
	{
		list[i + begin] = frontv[i];
	}

	// If you want to visualize how it works, uncomment following lines
	/*std::cout << "Visualize QuickSort : ";
	PrintVector(std::cout, list);*/

	QuickSortTemplateWithArea(list, begin, mid);
	QuickSortTemplateWithArea(list, (mid + 1), end);
}

template<class T>
void QuickSortTemplate(std::vector<T>& list)
{
	QuickSortTemplateWithArea(list, 0, list.size());
}

std::ostream& PrintVector(std::ostream& os, std::vector<int>& vec)
{
	os << "[Vector]" << std::endl;
	auto end = vec.end();
	for (auto it = vec.begin(); it != end; ++it)
	{
		os << *it << " | ";
	}
	os << std::endl;
	return os;
}

void generate(std::vector<int>& list, int from, int to)
{
	for (; from <= to; from++)
		list.push_back(from);
}

void shuffle(std::vector<int>& list, int count)
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

/*
[Example Code]

#include <iostream>
#include "MyQuickSort_Vector_Int.h"
using namespace std;



int main()
{
	vector<int> list;
	generate(list, 1, 10);
	shuffle(list, 3);
	PrintVector(cout, list);
	MyQuickSort(list, 0, list.size());
	PrintVector(cout, list);
	return 0;
}
*/