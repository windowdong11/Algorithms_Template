#pragma once
#include "Vector_Additionals.h"

template<class T>
void BubbleSort_VectorList(std::vector<T>& list)
{
	int end = static_cast<int>(list.size()) - 1; // Reason of '- 1' : this code will compare list[N] and list[N+1], so we will compare list[last index - 1] and list[last index]
	for (int cycle = 0; cycle < end; ++cycle)
	{
		for (int idxin = 0; idxin < end - cycle; ++idxin)
		{
			if(list[idxin] > list[idxin + 1])
				std::swap(list[idxin], list[idxin + 1]);
		}
	}
}