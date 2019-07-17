#pragma once
#include "Vector_Additionals.h"

template<class T>
void SelectionSort_VectorList(std::vector<T>& list)
{
	//long long runcount = 0;
	int end = static_cast<int>(list.size());
	for (int idxout = 0; idxout < end; ++idxout)
	{
		int minidx = idxout;
		for (int idxin = idxout; idxin < end; ++idxin)
		{
			//++runcount;
			if (list[minidx] > list[idxin])
			{
				minidx = idxin;
			}
		}
		std::swap(list[minidx], list[idxout]);
	}
	//std::cout << "Run count : " << runcount << std::endl;
}