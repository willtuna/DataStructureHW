
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Graph.h"
//#include "Graph.cpp"

using namespace std;

bool check(fstream& check, vector<Edge>& Answer);
Graph* parser(fstream& fin);
bool compare(Edge a, Edge b);

int main(int argc, const char * argv[]){
	
	fstream fin;
	fstream fcheck;
	string CheckFileName;

	fin.open(argv[1], ios::in);
	CheckFileName= argv[1];
	int NamePos=CheckFileName.find(".in");
	if(NamePos!=-1) CheckFileName.replace(NamePos+1,NamePos+3,"check");
	fcheck.open(CheckFileName.c_str(),ios::in);
	
	Graph* graph=parser(fin);
	
	vector<Edge> Answer;
	graph->MST(Answer);
	
	sort(Answer.begin(),Answer.end(),compare);

	
	if(!check(fcheck,Answer)) cout<<"Wrong Answer!"<<endl;
	else cout<<"Correct Answer!"<<endl;

	fin.close();
	fcheck.close();
	return 0;
}

Graph* parser(fstream& fin){
	char Line[4096];
	char* tok;
	int from, to, weight,NVertex;
	fin.getline(Line,4096);
	tok=strtok(Line,"=");
	tok=strtok(NULL,"\n");
	NVertex=atoi(tok);

	Graph* graph=new Graph(NVertex);
	
	while(fin.getline(Line,4096)){
		tok=strtok(Line," ");
		tok=strtok(NULL," ");
		from=atoi(tok);
		tok=strtok(NULL," ");
		tok=strtok(NULL," ");
		to=atoi(tok);
		tok=strtok(NULL," ");
		tok=strtok(NULL,"\n");
		weight=atoi(tok);
		
		graph->AddNode(from,to,weight);
	}
	return graph;
} 

bool check(fstream& check, vector<Edge>& Answer){
	int first,second,weight;
	bool correct=0;
	
	for(int i=0;i<Answer.size();i++){
		check >> first >> second >> weight;
		if(first==Answer[i].FirstNode && second==Answer[i].SecondNode && weight==Answer[i].weight) correct=1;
		else return 0;
	}
	return correct;
} 

bool compare(Edge a, Edge b){
	if(a.FirstNode<b.FirstNode) return 1;
	else if(a.FirstNode>b.FirstNode) return 0;
	else{
		if(a.SecondNode<b.SecondNode) return 1;
		else return 0; 
	}
}
