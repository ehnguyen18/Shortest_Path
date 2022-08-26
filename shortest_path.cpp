#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

#include "graph.h"

int main(){

        graph g(20);

        g.addEdge("Neamt", "Iasi", 87);
        g.addEdge("Iasi","Vaslui", 92);
        g.addEdge("Vaslui","Urziceni", 142);
        g.addEdge("Urziceni","Hirsova", 98);
        g.addEdge("Hirsova","Eforie", 86);
        g.addEdge("Urziceni","Bucharest", 85);
        g.addEdge("Bucharest","Giurgiu", 90);
        g.addEdge("Bucharest","Fagaras", 211);
        g.addEdge("Bucharest","Pitesti", 101);
        g.addEdge("Pitesti","Craiova", 138);
        g.addEdge("Pitesti","Rimnicu Vilcea", 97);
        g.addEdge("Craiova","Rimnicu Vilcea", 146);
        g.addEdge("Rimnicu Vilcea","Sibiu", 80);
        g.addEdge("Sibiu","Fagaras", 99);
        g.addEdge("Sibiu","Oradea", 151);
        g.addEdge("Oradea","Zerind", 71);
        g.addEdge("Zerind","Arad", 75);
        g.addEdge("Arad","Timisoara", 118);
        g.addEdge("Timisoara","Lugoj",111);
        g.addEdge("Lugoj","Mehadia",70);
        g.addEdge("Mehadia","Dobreta",75);
        g.addEdge("Dobreta","Craiova",120);
        g.addEdge("Arad","Sibiu", 140);

        g.printGraph();

        string start, end;
        cout<<"Enter start city: ";
        cin>>start;
        start[0]=toupper(start[0]);
        
        cout<<"Enter end city: ";
        cin>>end;
        end[0]=toupper(end[0]);

        g.uniformCostSearch(start, end);
        system("pause");
        return 0;
}