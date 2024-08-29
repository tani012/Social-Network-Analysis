#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
#include <queue>

struct Edge {
    int src;
    int dest;
    double weight;

    Edge(int src, int dest, double weight = 1.0) : src(src), dest(dest), weight(weight) {}
};

struct Node {
    int id;
    std::string name;

    Node() : id(-1), name("undefined") {}
    Node(int id, std::string name) : id(id), name(name) {}
};

// class Graph {
// private:
//     std::unordered_map<int, Node> nodes;
//     std::unordered_map<int, std::vector<Edge>> adjList;

// public:
//     void addNode(int id, std::string name);
//     void addEdge(int src, int dest, double weight = 1.0);
//     void displayGraph();
//     std::vector<int> dijkstra(int startNode, int endNode);
//     std::string getNodeName(int id);  // Add this line
// };
// // graph.h
class Graph {
private:
    std::unordered_map<int, Node> nodes;
    std::unordered_map<int, std::vector<Edge>> adjList;

public:
    void addNode(int id, std::string name);
    void addEdge(int src, int dest, double weight = 1.0);
    void displayGraph();
    std::vector<int> dijkstra(int startNode, int endNode);
    std::string getNodeName(int id);
    
    // Add this line:
    void loadFacebookData(const std::string& filename);
};
