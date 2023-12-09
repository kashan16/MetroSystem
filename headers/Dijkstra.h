// Dijkstra.h
#pragma once

#include <vector>
#include <queue>
#include <climits>

class Dijkstra {
public:
    std::vector<int> dijkstra(int V, std::vector<std::vector<std::pair<int, int>>> &adj, int S);
};
