/* METRO MANAGEMENT
A c++ program that uses different algorithms like Dijkstra(to print minimum distance)
,breadth-first search, depth-first search, etc,the shortest path between the source station
and the destination station is determined, and accordingly,the fare is being calculated on
the basis of the total distance between the two stations.A graph is used to store the station(vertex) and distance(weight of edges)
Finally, the metro route between the two stations and the total fare(minimum distance * fare{predetermined}) is displayed.*/

#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
using namespace std;
class Dijkstra
{
    public:

};
int minDistance(vector<int> dist , vector<bool> sptSet)
{
	int min = INT_MAX , min_index;
	for(int v = 0 ; v < 9 ; v++)
	{
		if(sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v] , min_index = v;
		}
	}
	return min_index;
}
// To add an station and distance
void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > adj[], int V , vector<bool> &visited)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout<<"Station "<<u<<" to "<<endl;
        visited[u] = true;
        for (auto it : adj[u])
        {
            v = it.first;
            w = it.second;
            cout<<"Station "<<v<<" with distance = "<<w<<endl;
        }
        cout<<endl;
    }
}
void Prepare(vector<pair<int,int> > adj[])
{
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 7, 20);
    addEdge(adj, 1, 0, 30);
    addEdge(adj, 1, 2, 40);
    addEdge(adj, 1, 7, 50);
    addEdge(adj, 2, 1, 60);
    addEdge(adj, 2, 3, 70);
    addEdge(adj, 2, 5, 90);
    addEdge(adj, 2, 8, 80);
    addEdge(adj, 3, 2, 60);
    addEdge(adj, 3, 4, 30);
    addEdge(adj, 3, 5, 10);
    addEdge(adj, 4, 3, 110);
    addEdge(adj, 4, 5, 78);
    addEdge(adj, 5, 2, 80);
    addEdge(adj, 5, 3, 40);
    addEdge(adj, 5, 4, 20);
    addEdge(adj, 5, 6, 36);
    addEdge(adj, 6, 5, 47);
    addEdge(adj, 6, 7, 70);
    addEdge(adj, 6, 8, 20);
    addEdge(adj, 7, 0, 40);
    addEdge(adj, 7, 1, 11);
    addEdge(adj, 7, 6, 29);
    addEdge(adj, 7, 8, 42);
    addEdge(adj, 8, 2, 47);
    addEdge(adj, 8, 6, 52);
    addEdge(adj, 8, 7, 57);
}
// Driver code
int main()
{
    int V = 9;
    vector<pair<int, int> > adj[V];
    vector<bool> visited(V,false);
    Prepare(adj);
    int i;
    cout<<"------ WELCOME TO METRO MANAGEMENT ------"<<endl;
    cout<<"For MAP Press 1"<<endl;
    cout<<"For Travel INFO between 2 station Press 2"<<endl;
    cin>>i;
    if(i == 1)
    {
        system("cls");
        printGraph(adj, V , visited);
    }
    if(i == 2)
    {
        Dijkstra d;
    }
    return 0;
}
