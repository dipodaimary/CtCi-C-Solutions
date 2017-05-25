#include <iostream>
#include <list>
using namespace std;
class Graph{
	list<int> *adj;
	bool *visited;
public:
	Graph(int);
	void addEdge(int,int);
	bool isReachable(int,int);
};
Graph::Graph(int V){
	adj = new list<int>[V];
	visited = new bool[V]{false};
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
bool Graph::isReachable(int v, int w){
	if(v==w){
		return true;
	}
	int s = v;
	visited[s] = true;
	list<int> queue;
	queue.push_back(s);
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		for(auto it=adj[s].begin();it!=adj[s].end();it++){
			if(!visited[*it]){
				visited[*it]=true;
				if(*it==w){
					return true;
				}
				queue.push_back(*it);
			}
		}
	}
	return false;
}
int main(){
	// Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "There is a path from " << u << " to " << v<<endl;
    else
        cout<< "There is no path from " << u << " to " << v<<endl;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "There is a path from " << u << " to " << v<<endl;
    else
        cout<< "There is no path from " << u << " to " << v<<endl;
 
    return 0;
}