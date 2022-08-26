#ifndef GRAPH_H_
#define GRAPH_H_
/*
* The following class was adapted from:
* https://www.softwaretestinghelp.com/graph-implementation-cpp/
* https://stackoverflow.com/questions/42780071/map-reprsentation-of-graph
* https://youtu.be/drpdVQq5-mk (Graph Adjaceny List Representation | Using Hash-map | Coding Blocks)
*/
#include <iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

class graph{

    unordered_map<string, map<string,int>> adjList;
    int V=0;
    int E=0;
    
    public:
        graph(int V);
        void addEdge(string, string, int);
        void printGraph();
        void BFS(int s);
};

void graph::addEdge(string start, string end, int weight){
    map<string,int> path;
    path[end] = weight;
    adjList[start]=path;
    path[start] = weight;
    adjList[end]=path;
    E+=2;
}

void graph::printGraph(){
    for(auto i=adjList.begin();i!=adjList.end();i++){
        cout<<i->first<<" -> ";
        for(auto j=i->second.begin();j!=i->second.end();j++){
            cout<<"("<<i->first<<","<<j->first<<","<<j->second<<") ";
        }
        cout<<endl;
    }
}

void graph::BFS(int s){
}
#endif /* GRAPH_H_ */