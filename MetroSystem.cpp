#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <climits>
#include "headers/Dijkstra.h"
using namespace std;

void displayMetroMap() {
    // Print a visual representation of the metro map
    // You can use station names and connections to make it user-friendly
    cout << "------ METRO MAP ------" << endl;
    cout << "Station1 --- Station2 --- Station3 --- Station4" << endl;
    cout << " |           |           |           |" << endl;
    cout << "Station5 --- Station6 --- Station7 --- Station8" << endl;
    cout << "             |           |" << endl;
    cout << "          Station9" << endl;
    cout << "-----------------------" << endl;
}

void getTravelInformation(vector<vector<pair<int, int>>> &adj, map<string, int> &stationIndices) {
    Dijkstra d;
    // Ask the user for source and destination stations
    string source, destination;
    cout << "Enter your source station: ";
    cin >> source;
    cout << "Enter your destination station: ";
    cin >> destination;

    auto sourceIter = stationIndices.find(source);
    auto destIter = stationIndices.find(destination);

    if(sourceIter == stationIndices.end() || destIter == stationIndices.end()) {
        cout << "Error : One or both of the entered station are not valid" << endl;
        return;
    }
    int srcIndex = sourceIter->second;
    int destIndex = destIter->second;
    int fareRate = 12;
    // Use Dijkstra's algorithm to get the shortest path and distance
    vector<int> distances = d.dijkstra(9, adj, srcIndex);
    int distance = distances[destIndex];

    // Display travel information
    cout << "Shortest distance between " << source << " and " << destination << " is: " << distance << " units" << endl;
    cout << "Fare: " << distance * fareRate << " units" << endl;
}


// To add a station and distance
void addEdge(vector<vector<pair<int, int>>> &adj, map<string, int> &stationIndices, const string &src, const string &dest, int wt) {
    if (stationIndices.find(src) == stationIndices.end()) {
        int newIndex = stationIndices.size();
        stationIndices[src] = newIndex;
    }
    if (stationIndices.find(dest) == stationIndices.end()) {
        int newIndex = stationIndices.size();
        stationIndices[dest] = newIndex;
    }

    int u = stationIndices[src];
    int v = stationIndices[dest];

    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt}); // Assuming the graph is undirected
}

// Print adjacency list representation of the graph
void Prepare(vector<vector<pair<int, int>>> &adj, map<string, int> &stationIndices) {
    addEdge(adj, stationIndices, "Station1", "Station2", 10);
    addEdge(adj, stationIndices, "Station2", "Station3", 20);
    addEdge(adj, stationIndices, "Station3", "Station4", 15);
    addEdge(adj, stationIndices, "Station4", "Station5", 25);
    addEdge(adj, stationIndices, "Station5", "Station6", 18);
    addEdge(adj, stationIndices, "Station6", "Station7", 12);
    addEdge(adj, stationIndices, "Station7", "Station8", 30);
    addEdge(adj, stationIndices, "Station8", "Station9", 22);
}
int getUserChoice() {
    int choice;
    while (true) {
        cout << "------ WELCOME TO METRO MANAGEMENT ------" << endl;
        cout << "1. View Metro Map" << endl;
        cout << "2. Get Travel Information between Stations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 3) {
            cout << "Invalid choice. Please enter a valid option." << endl;

            // Clear the error flag and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break; //Break out of the loop if the input is invalid
        }
    }
    return choice;
}
int menu(vector<vector<pair<int, int>>> &adj, map<string, int> &stationIndices , int &choice) {
    do {
        switch (choice) {
            case 1:
                // Call a function to display the metro map
                displayMetroMap();
                break;
            case 2:
                // Call a function to get travel information
                getTravelInformation(adj,stationIndices);
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0; // or exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << "Do you want to return to the main menu? (1 for Yes, 0 for No): ";
        cin >> choice;

    } while (choice == 1);

    return 0;
}


int main() {

    vector<vector<pair<int, int>>> adj(9);
    map<string, int> stationIndices;
    int choice = getUserChoice();
    Prepare(adj, stationIndices);
    menu(adj, stationIndices , choice);

    return 0;
}
