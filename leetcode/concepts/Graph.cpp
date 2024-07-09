#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;
template <typename T>


class Graph {
public:
    unordered_map<T, list<T>> adj;
    
    void addEdge(T u, T v, bool direction){
        // direction 0  => undirected
        // direction 1 => directed
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto i:adj){
            cout<< i.first <<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph<int> graph;

    int n ;
    cout<< "enter the number of nodes in graph"<<endl;
    cin >> n;

    int m;
    cout << "enter the number of edges in graph"<<endl;
    cin >> m;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        // create graph
        graph.addEdge(u,v,0);
    }

    graph.printAdjacencyList();


    // Write your main logic here

    return 0;
}