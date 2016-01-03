
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
	Edge(int f=0, int t=0, int w=0):FirstNode(f),SecondNode(t),weight(w)// ctor
	{}
};

struct heapedge{
	int from, to, weight;

	heapedge(int f=0, int t=0, int w=0):from(f),to(t),weight(w)// ctor
	{}

};


//  preprocessing has order    we need to declare heapedge first
class comp//  compare class for std:priority_queue<, ,compare>
//since priority_queue_is MAXHEAP by default
{
public:
	bool operator()(const heapedge & a,const heapedge & b)const
	{
		return a.weight > b.weight;
	}
};



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
