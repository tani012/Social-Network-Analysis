#include "Graph.h"
#include <iostream>
#include <algorithm> // For std::reverse

void Graph::addNode(int id, std::string name) {
    nodes[id] = Node(id, name);
}

void Graph::addEdge(int src, int dest, double weight) {
    adjList[src].push_back(Edge(src, dest, weight));
    adjList[dest].push_back(Edge(dest, src, weight));  // Add the reverse direction
}


void Graph::displayGraph() {
    for (const auto& node : nodes) {
        std::cout << "Node " << node.second.name << " (" << node.first << "): ";
        for (const auto& edge : adjList[node.first]) {
            std::cout << " -> " << nodes[edge.dest].name << " (weight: " << edge.weight << ")";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Graph::dijkstra(int startNode, int endNode) {
    std::unordered_map<int, double> distances;
    std::unordered_map<int, int> previous;
    auto cmp = [&distances](int left, int right) { return distances[left] > distances[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

    for (const auto& node : nodes) {
        distances[node.first] = std::numeric_limits<double>::infinity();
        previous[node.first] = -1;
    }

    distances[startNode] = 0;
    pq.push(startNode);

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();

        if (current == endNode) break;

        for (const auto& edge : adjList[current]) {
            double alt = distances[current] + edge.weight;
            if (alt < distances[edge.dest]) {
                distances[edge.dest] = alt;
                previous[edge.dest] = current;
                pq.push(edge.dest);
            }
        }
    }

    std::vector<int> path;
    for (int at = endNode; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    if (path.size() == 1 && path[0] != startNode) {
        path.clear(); // No path found
    }

    return path;
}

std::string Graph::getNodeName(int id) {
    return nodes[id].name;
}

#include <fstream>
#include <sstream>


void Graph::loadFacebookData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int src, dest;
        if (!(iss >> src >> dest)) { break; }  // Error in reading line

        // Add nodes if they don't exist
        if (nodes.find(src) == nodes.end()) {
            addNode(src, "User" + std::to_string(src));
        }
        if (nodes.find(dest) == nodes.end()) {
            addNode(dest, "User" + std::to_string(dest));
        }

        // Add the undirected edge
        addEdge(src, dest);
    }
}

