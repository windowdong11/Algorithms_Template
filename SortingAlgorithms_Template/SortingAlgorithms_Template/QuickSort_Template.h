#pragma once
#include "Vector_Additionals.h"
/*
Used another list to store sorted data,
swapped with original list when every piece of sort ends.
*/


template<class T>
void QuickSortTemplateWithArea(std::vector<T>& list, int begin, int end)
{
	/*int count = end - begin;
	if (count <= 1)
		return;*/
	if (end <= begin + 1)
		return;

	int mid = (begin + end) / 2;
	T pivot = list[mid];

	std::vector<T> frontv, backv;
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
	Print_VectorList(std::cout, list);*/

	QuickSortTemplateWithArea(list, begin, mid);
	QuickSortTemplateWithArea(list, (mid + 1), end);
}


template<class T>
void QuickSort_VectorList(std::vector<T>& list)
{
	QuickSortTemplateWithArea(list, 0, list.size());
}

/*
[Example Code]

#include <iostream>
#include "MyQuickSort_Vector_Int.h"
using namespace std;



int main()
{
	vector<int> list;
	Generate_VectorList(list, 1, 10);
	Shuffle_VectorList(list, 3);
	Print_VectorList(cout, list);
	MyQuickSort(list, 0, list.size());
	Print_VectorList(cout, list);
	return 0;
}
*/