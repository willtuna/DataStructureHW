#include <list>
#include "Graph.h"
#include <climit>
#include <queue>

// built heap by yourself


Graph::Graph(int& NVertex){
	NumVertex=NVertex;
	
	for(int i=0;i<NVertex;i++){
		list<AdjNode> NodeList;
		AdjList.push_back(NodeList);
	}
}

void Graph::AddNode(int& first, int& second, int& weight){

	AdjNode NewNode;
	NewNode.index=second;
	NewNode.weight=weight;
	AdjList[first].push_back(NewNode);
	
	NewNode.index=first;
	NewNode.weight=weight;
	AdjList[second].push_back(NewNode);
	

}

void Graph::MST(vector<Edge>& Answer){
// 並沒有規定一定要用Heap
	
	vector<int> key(NumVertex,INT_MAX);// initialize int_max
	vector<bool> notused(NumVertex, 1);

	AdjNode current_Node;

	// build up the vector of not_used vector for heapify
	vector<AdjNode> for_heap(NumVertex,AdjNode());
	for(int i=0;i<NumVertex;++i)
	{
		for_heap[i].index =i;
		for_heap[i].weight = INT_MAX;
	}

	for_heap[0].weight = 0; // root
	


	//  build up heap
	priority_queue<AdjNode,vector<AdjNode>,comp>  Not_In_Tree_Vertex(for_heap); 
	// min_heap based on 

	while(!Not_In_Tree_Vertex.empty()) 
	{
		current_Node = Not_In_Tree_Vertex.top();
		Not_In_Tree_Vertex.pop();
		
		
		list<AdjNode>::iterator iter = AdjList[current_Node.index].begin();
		list<AdjNode>::iterator iter_end = AdjList[current_Node.index].end();
		for(;iter!= iter_end;iter++)
		{
			AdjNode v = AdjList[iter];
			if(notused[current_Node.index]  && v.weight < key[v.index])
			{
				key[v.index] = v.weight;
			}
		}
	}
}
