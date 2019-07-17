#pragma once
#include "Vector_Additionals.h"

template<class T>
void InsertionSort_VectorList(std::vector<T>& list)
{
	//long long runcount = 0;
	int end = static_cast<int>(list.size());
	for (int idxout = 1; idxout < end; ++idxout)
	{
		int minidx = idxout;
		for (int idxin = idxout - 1; 0 <= idxin; --idxin)
		{
			//++runcount;
			if (list[idxin] < list[idxout])
				break;
			else if (list[idxin] > list[idxout])
				minidx = idxin;
		}
		list.insert(list.begin() + minidx, list[idxout]);
		list.erase(list.begin() + idxout + 1);
		//Print_VectorList(std::cout, list);
	}
	//std::cout << "Run count : " << runcount << std::endl;
}