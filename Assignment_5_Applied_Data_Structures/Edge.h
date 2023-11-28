// File: Edge.h
// Definition of Edge class
/* _______________________________________________________________
An edge (u,v,w) existing between nodes (u) and (v) with weight (w)
is modeled as a class (Edge).
__________________________________________________________________
*/
// some editing to this class so it 
#ifndef EDGE_H
#define EDGE_H

typedef int weightType;		// weights are positive integers

class Edge
{
public:
	int u;
	int v;
	weightType w;
	bool operator < (const Edge& e)
	{
		return (w < e.w);
	}
	bool operator <= (const Edge& e)
	{
		return (w <= e.w);
	}

}; // end of class Edge declaration
#endif // EDGE_H

