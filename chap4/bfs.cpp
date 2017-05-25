#include <iostream>
#include <list>
using namespace std;
class Graph{
	list<int> *adj;
	bool *visted;
public:
	Graph(int);
	void addEdge(int, int);
	void BFS(int);
};
Graph::Graph(int V){
	adj = new list<int>[V];
	visted = new bool[V]{false};
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
void Graph::BFS(int s){
	list<int> queue;
	visted[s]=true;
	queue.push_back(s);
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		cout<<s<<" ";
		for(auto it=adj[s].begin();it!=adj[s].end();++it){
			if(!visted[*it]){
				visted[*it]=true;
				queue.push_back(*it);
			}
		}
	}
};
int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout<<endl;
    return 0;
}