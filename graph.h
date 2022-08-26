#ifndef GRAPH_H_
#define GRAPH_H_
/*
* The following class was adapted from:
* https://www.softwaretestinghelp.com/graph-implementation-cpp/
* https://stackoverflow.com/frontieruestions/42780071/map-reprsentation-of-graph
* https://youtu.be/drpdVfrontierfrontier5-mk (Graph Adjaceny List Representation | Using Hash-map | Coding Blocks)
*/
#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

class graph{

    unordered_map<string, list<pair<string,int>>> adjList;
    int V=0;
    int E=0;
    
    public:
        graph(int V)
        {
            this->V=V;
        };
        void addEdge(string, string, int);
        void uniformCostSearch(string, string);
        void printGraph();
};

void graph::addEdge(string start, string end, int weight){
    adjList[start].push_back(make_pair(end,weight));
    adjList[end].push_back(make_pair(start,weight));
    E++;
}

void graph::printGraph(){
    cout<<"Number of Vertex: "<<V<<endl;
    cout<<"Number of Edges: "<<E<<endl<<endl;
    for(auto i=adjList.begin();i!=adjList.end();i++){
        cout<<i->first<<" -> ";
        for(auto j=i->second.begin();j!=i->second.end();j++){
            cout<<"("<<j->first<<","<<j->second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void graph::uniformCostSearch(string start, string end){
    unordered_map<string, bool> explored;
    unordered_map<string, int> distance;
    unordered_map<string, string> parent;
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> frontier;
    stack<string> child;        //To reverse the path
    
    frontier.push(make_pair(start, 0));
    explored[start]=true;
    distance[start]=0;
    parent[start]="";
    while(!frontier.empty()){
        string u=frontier.top().first;
        frontier.pop();
        if(u==end){ //Found goal
            cout<<"Shortest path from "<<start<<" to "<<end<<" is: "<<distance[end]<<endl;
            cout<<"Path: ";
            while(parent[u]!=""){
                u=parent[u];
                child.push(u);  //reverse the path
            }
            while(!child.empty()){
                cout<<child.top()<<" -> ";
                child.pop();
            }
            cout<<end<<endl;
            return;
        }

        for(auto i=adjList[u].begin();i!=adjList[u].end();i++){
            if(!explored[i->first]){
                explored[i->first]=true;
                distance[i->first]=distance[u]+i->second;
                parent[i->first]=u;
                frontier.push(make_pair(i->first, distance[i->first]));
            }
            else if(distance[i->first]>distance[u]+i->second){ //If the distance is greater than the current distance, 
                distance[i->first]=distance[u]+i->second;     //update the distance and parent
                parent[i->first]=u;
                frontier.push(make_pair(i->first, distance[i->first]));
            }
        }
    }
    cout<<"No path found"<<endl;
}

#endif /* GRAPH_H_ */