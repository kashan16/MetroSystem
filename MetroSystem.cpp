#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <climits>
#include "headers/Dijkstra.h"
#include "headers/metro_func.h"
using namespace std;
int main() {
    std::vector<std::vector<std::pair<int, int>>> adj(9);
    std::map<std::string, int> stationIndices;
    int choice = MetroFunctions::getUserChoice();

    Dijkstra dijkstra;  // Create an instance of the Dijkstra class

    MetroFunctions::Prepare(adj, stationIndices);
    MetroFunctions::menu(adj, stationIndices, dijkstra, choice);

    return 0;
}
