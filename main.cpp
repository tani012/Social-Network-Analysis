#include "Graph.h"
#include <iostream>

int main() {
    Graph g;
    
    // Load Facebook data (assuming the file is named "facebook_combined.txt")
    g.loadFacebookData("facebook_combined.txt");
    
    g.displayGraph();

    // Example: Find the shortest path between two users (replace with actual IDs)
    int startNode = 1;  // Replace with an actual user ID
    int endNode = 10;   // Replace with an actual user ID

    std::vector<int> path = g.dijkstra(startNode, endNode);

    std::cout << "Shortest path: ";
    for (int node : path) {
        std::cout << g.getNodeName(node) << " ";
    }
    std::cout << std::endl;

    return 0;
}


