 
#ifndef _Graph_H_
#define _Graph_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;

struct Edge{
	int FirstNode,SecondNode,weight;
};

class comp//  compare class for std:priority_queue<, ,compare>    
//since priority_queue_is MAXHEAP by default
{
public:
	bool operator()(const AdjNode & a,const AdjNode & b)const
	{
		return a.weight > b.weight;
	}
}

struct AdjNode{
	int index,weight;
};

class Graph{
	private:
		int NumVertex;
		vector< list<AdjNode> > AdjList;
	public:
		void AddNode(int& first, int& second, int& weight);
		void MST(vector<Edge>& Answer);
		Graph(int& NumVertex);// ctor
};

#endif
