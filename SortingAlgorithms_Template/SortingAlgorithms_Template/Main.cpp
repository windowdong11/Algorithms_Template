#include <iostream>
#include <vector>
#include <chrono>
#include "QuickSort_Template.h"
#include "SelectionSort_Template.h"
#include "InsertionSort_Template.h"
#include "MergeSort_Template.h"
#include "BubbleSort_Template.h"
using namespace std;

// this code is from : https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
void ElaspedTime(chrono::time_point<chrono::system_clock> start)
{
	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);

	cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}


int main()
{
	bool enable_quicksort = true;
	bool enable_selectionsort = true;
	bool enable_insertionsort = true;
	bool enable_mergesort = true;
	bool enable_bubblesort = false;

	/*
		This is original vector to store data list.
		This sorting program will test with same data list.
	*/
	vector<int> origin;
	Generate_VectorList(origin, 0, 100000);
	Shuffle_VectorList(origin, 20);

	vector<int> list;

	chrono::time_point<chrono::system_clock> start;

	if (enable_quicksort)
	{
		list = origin;
		cout << "<Test Quicksort>" << endl;
		start = chrono::system_clock::now();
		//Print_VectorList(cout, list, "[Shuffled data]");
		QuickSort_VectorList(list);
		//Print_VectorList(cout, list, "[Quicksort result]");
		ElaspedTime(start);
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}


	if (enable_selectionsort)
	{
		list = origin;
		cout << "<Test Selectionsort>" << endl;
		start = chrono::system_clock::now();
		//Print_VectorList(cout, list, "[Shuffled data]");
		SelectionSort_VectorList(list);
		//Print_VectorList(cout, list, "[Selectionsort result]");
		ElaspedTime(start);
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_insertionsort)
	{
		list = origin;
		cout << "<Test Insertionsort>" << endl;
		start = chrono::system_clock::now();
		//Print_VectorList(cout, list, "[Shuffled data]");
		InsertionSort_VectorList(list);
		//Print_VectorList(cout, list, "[Insertionsort result]");
		ElaspedTime(start);
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_mergesort)
	{
		list = origin;
		start = chrono::system_clock::now();
		cout << "<Test Mergesort>" << endl;
		//Print_VectorList(cout, list, "[Shuffled data]");
		MergeSort_VectorList(list);
		//Print_VectorList(cout, list, "[Mergesort result]");
		ElaspedTime(start);
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_bubblesort)
	{
		list = origin;
		cout << "<Test Bubblesort>" << endl;
		start = chrono::system_clock::now();
		//Print_VectorList(cout, list, "[Shuffled data]");
		BubbleSort_VectorList(list);
		//Print_VectorList(cout, list, "[Bubblesort result]");
		ElaspedTime(start);
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	return 0;
}