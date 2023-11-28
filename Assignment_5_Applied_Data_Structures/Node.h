#ifndef NODE_H
#define NODE_H
#include<iostream>
struct Node
{
	std::string date;
	double exchangeRate;
	Node(std::string s, double d)
	{
		date = s;
		exchangeRate = d;
	}
	Node()
	{
		date = "";
		exchangeRate = 0;
	}

};
#endif // !NODE.H
