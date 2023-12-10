// metro_functions.h
#ifndef METRO_FUNCTIONS_H
#define METRO_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <map>
#include "Dijkstra.h"  // Include the Dijkstra header file

class Dijkstra;  // Forward declaration

class MetroFunctions {
public:
    static void displayMetroMap();
    static void getTravelInformation(std::vector<std::vector<std::pair<int, int>>>& adj, std::map<std::string, int>& stationIndices, Dijkstra& dijkstra);
    static void addEdge(std::vector<std::vector<std::pair<int, int>>>& adj, std::map<std::string, int>& stationIndices,const std::string& src, const std::string& dest, int wt);
    static void Prepare(std::vector<std::vector<std::pair<int, int>>>& adj, std::map<std::string, int>& stationIndices);
    static int menu(std::vector<std::vector<std::pair<int, int>>>& adj, std::map<std::string, int>& stationIndices,Dijkstra& dijkstra);
};

#endif // METRO_FUNCTIONS_H
