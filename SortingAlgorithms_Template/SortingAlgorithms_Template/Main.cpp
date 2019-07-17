#include <iostream>
#include <vector>
#include <chrono>
#include "QuickSort_Template.h"
#include "SelectionSort_Template.h"
#include "InsertionSort_Template.h"
#include "MergeSort_Template.h"
#include "BubbleSort_Template.h"
#include "Name.h"
using namespace std;


void ElaspedTime(chrono::time_point<chrono::system_clock> start);

int main()
{
	bool enable_quicksort = true;
	bool enable_selectionsort = false;
	bool enable_insertionsort = false;
	bool enable_mergesort = false;
	bool enable_bubblesort = false;

	bool enable_PrintList = true;

	/*
		This is original vector to store data list.
		This sorting program will test with same data list.
	*/
	/*vector<int> origin;
	Generate_VectorList(origin, 0, 100000);
	Shuffle_VectorList(origin, 20);

	vector<int> list;*/
	vector<Name> origin;
	Generate_VectorList(origin, Name("abc"), Name("acc"));
	Shuffle_VectorList(origin, 20);

	vector<Name> list;

	chrono::time_point<chrono::system_clock> start;

	if (enable_quicksort)
	{
		list = origin;
		cout << "<Test Quicksort>" << endl;
		if(enable_PrintList)
			Print_VectorList(cout, list, "[Shuffled data]");

		start = chrono::system_clock::now();
		QuickSort_VectorList(list);
		ElaspedTime(start);

		if (enable_PrintList)
			Print_VectorList(cout, list, "[Quicksort result]");
		cout << "Sorted? " << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}


	if (enable_selectionsort)
	{
		list = origin;
		cout << "<Test Selectionsort>" << endl;
		if (enable_PrintList)
			Print_VectorList(cout, list, "[Shuffled data]");

		start = chrono::system_clock::now();
		SelectionSort_VectorList(list);
		ElaspedTime(start);

		if (enable_PrintList)
			Print_VectorList(cout, list, "[Selectionsort result]");
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_insertionsort)
	{
		list = origin;
		cout << "<Test Insertionsort>" << endl;
		if (enable_PrintList)
			Print_VectorList(cout, list, "[Shuffled data]");
		
		start = chrono::system_clock::now();
		InsertionSort_VectorList(list);
		ElaspedTime(start);

		if (enable_PrintList)
			Print_VectorList(cout, list, "[Insertionsort result]");
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_mergesort)
	{
		list = origin;
		cout << "<Test Mergesort>" << endl;
		if (enable_PrintList)
			Print_VectorList(cout, list, "[Shuffled data]");

		start = chrono::system_clock::now();
		MergeSort_VectorList(list);
		ElaspedTime(start);

		if (enable_PrintList)
			Print_VectorList(cout, list, "[Mergesort result]");
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	if (enable_bubblesort)
	{
		list = origin;
		cout << "<Test Bubblesort>" << endl;
		if (enable_PrintList)
			Print_VectorList(cout, list, "[Shuffled data]");

		start = chrono::system_clock::now();
		BubbleSort_VectorList(list);
		ElaspedTime(start);

		if (enable_PrintList)
			Print_VectorList(cout, list, "[Bubblesort result]");
		cout << (isSorted(list) ? "True" : "False") << endl;
		cout << endl;
	}

	return 0;
}

// this code is from : https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
void ElaspedTime(chrono::time_point<chrono::system_clock> start)
{
	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);

	cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}