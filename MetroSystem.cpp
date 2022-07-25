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
        vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
        {
            vector<int>dis(V,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dis[S]=0;
            pq.push({0,S});
            while(!pq.empty())
                {
                    auto temp =pq.top();
                    pq.pop();
                    for(auto x : adj[temp.second])
                        {
                            int src=x[0];
                            int val=x[1];
                            if(dis[src]>temp.first+val)
                                {
                                    dis[src]=temp.first+val;
                                    pq.push({dis[src],src});
                                }
                        }
                    }
            return dis;
        }

};
// To add an station and distance
void addEdge(vector<vector<int>> adj[], int u,
                                     int v, int wt)
{
    vector<int> t1;
    t1.push_back(v);
    t1.push_back(wt);
    adj[u].push_back(t1);

}

// Print adjacency list representation of graph
void Prepare(vector<vector<int>> adj[])
{
    addEdge(adj,0,1,10);
    addEdge(adj,1,0,10);
    addEdge(adj,0,7,20);
    addEdge(adj,7,0,20);
    addEdge(adj,1,2,40);
    addEdge(adj,2,1,40);
    addEdge(adj,2,3,70);
    addEdge(adj,3,2,70);
    addEdge(adj,3,4,110);
    addEdge(adj,4,3,110);
    addEdge(adj,4,5,78);
    addEdge(adj,5,4,78);
    addEdge(adj,5,6,36);
    addEdge(adj,6,5,36);
    addEdge(adj,6,7,70);
    addEdge(adj,7,6,70);
    addEdge(adj,7,1,50);
    addEdge(adj,1,7,50);
    addEdge(adj,7,8,42);
    addEdge(adj,8,7,42);
    addEdge(adj,6,8,20);
    addEdge(adj,8,6,20);
    addEdge(adj,2,8,80);
    addEdge(adj,8,2,80);
    addEdge(adj,2,5,90);
    addEdge(adj,5,2,90);
    addEdge(adj,3,5,40);
    addEdge(adj,5,3,40);
}
// Driver code
int main()
{
    int V = 9;
    vector<vector<int>> adj[V];
    vector<bool> visited(V,false);
    Prepare(adj);
    int i;
    cout<<"------ WELCOME TO METRO MANAGEMENT ------"<<endl;
    cout<<"For MAP Press 1"<<endl;
    cout<<"For Travel INFO between 2 station Press 2"<<endl;
    cin>>i;
    Dijkstra d;
    if(i == 1)
    {
        system("cls");
        for(int i = 0 ; i < 9 ; i++)
            {
                vector<int> res = d.dijkstra(9,adj,i);
                for(int j = 0 ; j < 9 ; j++)
                {
                    if(i != j)
                        {
                            cout<<i<<" -> "<<j<<" Distance : "<<res[j]<<endl;
                        }
                }
            }
    }
    if(i == 2)
    {
        Dijkstra d;
        system("cls");
        int src,dest;
        cout<<"Enter your station number : ";
        cin>>src;
        cout<<"Enter destination station number : ";
        cin>>dest;
        vector<int> res = d.dijkstra(9,adj,src);
    	for(int i=0; i<9; i++)
    	{
    	    if(dest == i)
            {
                cout<<"Distance B/W "<<src<<" and "<<dest<<" is : "<<res[i];
            }
    	}
    	cout<<endl;
    }
    return 0;
}
