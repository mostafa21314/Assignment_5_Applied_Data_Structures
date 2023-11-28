#include<iostream>
#include"Node.h"
#include"MinHeap.h"
#include"Edge.h"
#include<fstream>
#include<string>
using namespace std;

double FilterData(string unfiltered)
{
	double filtered;
	filtered = stod(unfiltered);
	return filtered;
}

void upHeap(Node* arr[], int current, string type)
{
	if (type == "min")
	{

		if ((current == 1) || (current == 0))
			return;
		if (arr[current / 2]->exchangeRate > arr[current]->exchangeRate)
		{
			Node* temp = arr[current];
			arr[current] = arr[current / 2];
			arr[current / 2] = temp;
			upHeap(arr, current / 2, type);

		}
	}
	else
	{


		if ((current == 1) || (current == 0))
			return;
		if (arr[current / 2]->exchangeRate < arr[current]->exchangeRate)
		{
			Node* temp = arr[current];
			arr[current] = arr[current / 2];
			arr[current / 2] = temp;
			upHeap(arr, current / 2, type);

		}
	}






}
void Build_Min_Heap(Node* arr[], int size, string fileName)   // builds a minimum heap from a text file
{
	ifstream  reading(fileName);
	/*if (!reading.is_open())
	{
		cout << "Big time error";
	}*/
	for (int i = 0; i < 16; i++)
	{
		string garbage;
		getline(reading, garbage);
	}
	//string test;
	//getline(reading, test);
	//cout << test;
	string date;
	string exchange;
	int counter = 1;
	while (reading >> date)
	{
		reading >> exchange;
		arr[counter]->date=date;
		arr[counter++]->exchangeRate=FilterData(exchange);
		//upHeap(arr, counter++,"min");


	}


}

void Build_Max_Heap(Node* arr[], int size, string fileName)   // builds a maximum heap from a text file
{



}
void insert(Node* arr[], int counter, int size, Node value)
{



}

void downHeap(Node* arr[])
{

}

int main()
{
	//Node test("99", 5);
	//MinHeap exchange(10000);
	//exchange.insert(test);
	const int SIZE = 7000;
	Node* heap[SIZE];
	string temp = "/Users/mosta/source/repos/Assignment_5_Applied_Data_Structures/Assignment_5_Applied_Data_Structures/euro-dollar.txt";
	Build_Min_Heap(heap, SIZE, temp);

}