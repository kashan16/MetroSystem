// Dijkstra.cpp
#include "Dijkstra.h"

std::vector<int> Dijkstra::dijkstra(int V, std::vector<std::vector<std::pair<int, int>>> &adj, int S) {
    std::vector<int> dis(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        for (auto x : adj[temp.second]) {
            int dest = x.first;
            int val = x.second;
            if (dis[dest] > temp.first + val) {
                dis[dest] = temp.first + val;
                pq.push({dis[dest], dest});
            }
        }
    }
    return dis;
}
