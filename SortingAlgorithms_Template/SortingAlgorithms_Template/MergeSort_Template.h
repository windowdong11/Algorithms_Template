#pragma once
#include "Vector_Additionals.h"



template<class T>
void Merge(std::vector<T>& list, int start, int end)
{
	if (end <= start + 1)
		return;

	int mid = (start + end) / 2;
	Merge(list, start, mid);
	Merge(list, mid, end);

	std::vector<T> tmp(list);
	int curidx = start;

	int frontidx = start;
	int backidx = mid;
	for (; frontidx < mid && backidx < end;)
	{
		tmp[curidx++] = (list[frontidx] < list[backidx] ? list[frontidx++] : list[backidx++]);
	}
	if (frontidx == mid)
	{
		for (; backidx < end;)
		{
			tmp[curidx++] = list[backidx++];
		}
	}
	else
	{
		for (; frontidx < mid;)
		{
			tmp[curidx++] = list[frontidx++];
		}
	}
	//Print_VectorList(std::cout, tmp);
	std::swap(list, tmp);

}

template<class T>
void MergeSort_VectorList(std::vector<T>& list)
{
	Merge(list, 0, list.size());
}