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
void downHeap(Node* arr[], int current, string type,int size)
{
	if ((current * 2 >= size) || ((current * 2 + 1) >= size))
		return;
	if ((arr[current * 2]->date == "") && (arr[current * 2 + 1]->date == ""))
	{
		return;
	}
	if (type == "min")
	{
		if ((arr[current * 2]->exchangeRate < arr[current]->exchangeRate) || (arr[current * 2 + 1]->exchangeRate < arr[current]->exchangeRate))
		{
			if ((arr[current * 2]->exchangeRate) < (arr[current * 2 + 1]->exchangeRate))
			{
				Node temp = *arr[current];
				*arr[current] = *arr[current * 2];
				*arr[current * 2] = temp;
				downHeap(arr, current * 2, type,size);
			}
			else
			{
				Node* temp = arr[current];
				arr[current] = arr[current * 2 + 1];
				arr[current * 2 + 1] = temp;
				downHeap(arr, current * 2 + 1, type,size);
			}
		}

	}
	else
	{
		if ((arr[current * 2]->exchangeRate > arr[current]->exchangeRate) || (arr[current * 2 + 1]->exchangeRate > arr[current]->exchangeRate))
		{
			if (arr[current * 2]->exchangeRate > arr[current * 2 + 1]->exchangeRate)
			{
				Node* temp = arr[current];
				arr[current] = arr[current * 2];
				arr[current * 2] = temp;
				downHeap(arr, current * 2, type,size);
			}
			else
			{
				Node* temp = arr[current];
				arr[current] = arr[current * 2 + 1];
				arr[current * 2 + 1] = temp;
				downHeap(arr, current * 2 + 1, type,size);
			}
		}
	}
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
	double average = 0;
   while(reading>>date)
   {
		reading >> exchange;
		arr[counter] = new Node();
		arr[counter]->date=date;
		arr[counter]->exchangeRate=FilterData(exchange);
		average += arr[counter]->exchangeRate;
		upHeap(arr, counter++,"min");
   }
   average = average / (counter-1);
   cout << "The average is " << average <<endl;
   for (int i = 1; i < size ; i++)
   {
	   arr[i]->exchangeRate -= average;
   }
  /*for (int i = 1; i < size-1; i++)
   {
	   cout << arr[i]->exchangeRate << endl;
   }*/
 
}

void Build_Max_Heap(Node* arr[], int size, string fileName)   // builds a maximum heap from a text file
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
	double average = 0;
	while (reading >> date)
	{
		reading >> exchange;
		arr[counter] = new Node();
		arr[counter]->date = date;
		arr[counter]->exchangeRate = FilterData(exchange);
		average += arr[counter]->exchangeRate;
		upHeap(arr, counter++, "max");
	}
	average = average / (counter - 1);
	cout << "The average is " << average << endl;
	for (int i = 1; i < size; i++)
	{
		arr[i]->exchangeRate -= average;
	}
	/* for (int i = 1; i < size-1; i++)
	 {
		 cout << arr[i]->exchangeRate << endl;
	 }*/

	/* for (int i = 1; i < size-1; i++)
 {
	 cout << arr[i]->exchangeRate << endl;
 }*/
}
void insert(Node* arr[], int counter, int size, Node value)
{



}

Node deleteNode(Node* arr[], int &current, string type,int size)
{
	Node temp = *arr[1];
	*arr[1] = *arr[current];
	arr[current]->date = ""; arr[current--]->exchangeRate = 0;
downHeap(arr, 1, type,size);
	return temp;


}

void arrangedValues(Node* arr[],int size, int cursor, int k, string type)
{
	if (type == "min")
		cout << "The minimum values are : " << endl;
	else
		cout << "The maximum values are : " << endl;
	for (int i = 0; i < k; i++)
	{
		Node tempor = deleteNode(arr, cursor, type, size);
		cout << tempor.date << "  " << tempor.exchangeRate << endl;
	}
}

int main()
{
	//Node test("99", 5);
	//MinHeap exchange(10000);
	//exchange.insert(test);
	const int SIZE = 6669;
	Node* minheap[SIZE];
	Node* maxheap[SIZE];
	string temp = "/Users/mosta/source/repos/Assignment_5_Applied_Data_Structures/Assignment_5_Applied_Data_Structures/euro-dollar.txt";
	Build_Min_Heap(minheap, SIZE, temp);
	Build_Max_Heap(maxheap, SIZE, temp);
	int cursorMax = SIZE-1;
	int cursorMin = SIZE - 1;
	//for(int i=1;i<SIZE;i++)
	//{
	//	Node tempor = deleteNode(minheap, cursor, "min", SIZE);
	//	cout << tempor.date << "  " << tempor.exchangeRate << endl;
	//}
	arrangedValues(maxheap, SIZE, cursorMax, 10, "max");
	arrangedValues(minheap, SIZE, cursorMin, 10, "min");
	// deleteNode(minheap, cursor, "min")->exchangeRate;
	//eleteNode(minheap, cursor, "min")->exchangeRate;



}