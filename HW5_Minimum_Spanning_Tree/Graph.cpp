#include <list>
#include "Graph.h"
#include <queue>


using namespace std;

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

	vector<bool> notused(NumVertex, 1);// all number of NumVertex is not used yet

	int current_Node;

	current_Node = 0;// initialize the starting point
	notused[current_Node]=0;
	//  build up heap
	priority_queue<heapedge,vector<heapedge>,comp>  candidate_heap;
	// min_heap based on heapedge
	int num_of_answer = 0;



	 // when the number of edge is NumVertex -1  , stop          or   no candidate_heap element
	while(num_of_answer<NumVertex-1 )
	{
		heapedge current_best_edge;
		// iterator is a pointer-like point to the node in the list


		for(list<AdjNode>::iterator iter = AdjList[current_Node].begin()  ; iter!=AdjList[current_Node].end();iter++)
		{
		    if(notused[iter->index]){
			 candidate_heap.push( heapedge(current_Node, iter->index , iter->weight) );
		    }

		}


		current_best_edge = candidate_heap.top();
		candidate_heap.pop();
		if(  notused[current_best_edge.to] )// if not visit before
		{
			int small,large;
			if(current_best_edge.from < current_best_edge.to)
			{
				small = current_best_edge.from;
				large = current_best_edge.to;
			}
			else
			{
				small = current_best_edge.to;
				large = current_best_edge.from;// actually i can use swap;
			}


			Answer.push_back(Edge(small,large,current_best_edge.weight));
			num_of_answer++;

			notused[current_best_edge.to]=0;//  mark used
			current_Node = current_best_edge.to;
		}

        if(candidate_heap.empty())
		{
			cout<<"No MST for this Graph !!!"<<endl;

			return;
		}


	}

	if(num_of_answer == NumVertex-1)
		{
			return;
		}

}
