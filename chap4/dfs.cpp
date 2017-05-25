#include <iostream>
#include <list>
using namespace std;
class Graph{
	list<int> *adj;
	bool *visited;
	void dfsUtil(int v, bool visited[]);
public:
	Graph(int);
	void addEdge(int, int);
	void dfs(int);
};
Graph::Graph(int V){
	adj = new list<int>[V];
	visited = new bool[V]{false};
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
void Graph::dfsUtil(int s, bool visited[]){
	visited[s]=true;
	cout<<s<<" ";
	for(auto it=adj[s].begin();it!=adj[s].end();it++){
		if(!visited[*it])
			dfsUtil(*it, visited);
	}
}
void Graph::dfs(int s){
	dfsUtil(s,visited);
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
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs(2);
    cout<<endl;
    return 0;
}