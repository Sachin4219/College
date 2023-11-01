#include <iostream> 
#include <vector> 
#include <limits.h> 
using namespace std; 

int minDistance(int dist[], bool sptSet[], int V) { 
	int min = INT_MAX, min_index; 
	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 
	return min_index; 
} 
void printSolution(int dist[], int V) { 
	cout <<"Node \t Cost from selected NODE" << endl; 
	for (int i = 0; i < V; i++) 
		cout << i << " \t\t"<<dist[i]<< endl; 
} 
void dijkstra(vector <vector <int> > graph, int src, int V) { 
	int dist[V];  
	bool sptSet[V];  
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0; 
	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet, V); 
		sptSet[u] = true; 
		for (int v = 0; v < V; v++) 
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 
	printSolution(dist, V); 
} 
int main() { 
	cout << "Enter the number of nodes: "; 
	int V; 
	cin >> V; 
	vector <vector <int> > graph (V, vector <int> (V, 0)); 
	cout << "Enter the cost matrix :" << endl;
	for(int i=0; i<V; i++){ 
		for (int j=0; j<V; j++){ 
		cin >> graph[i][j]; 
		} 
	} 
	cout << "Enter the selected node: "; 
	int node; 
	cin >> node; 
	dijkstra(graph, node, V); 
	return 0; 
}
