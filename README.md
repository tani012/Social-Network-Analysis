# Social Network Analysis

## Project Overview
This project performs social network analysis on a graph-based representation of Facebook data from the SNAP dataset. It includes functionality for finding shortest paths between users, calculating centrality measures, and visualizing the network.

## Features
- Dijkstra's algorithm for shortest path calculation
- Centrality measures: Degree, Betweenness, Closeness
- Network visualization using `matplotlib-cpp`

## Dataset
- **Facebook Dataset**: The dataset is taken from the [SNAP Facebook Dataset](https://snap.stanford.edu/data/egonets-Facebook.html). It contains anonymized Facebook user connections.

## Installation and Setup

### Prerequisites
- C++ compiler (e.g., g++)
- Python with `matplotlib` installed

### Steps to Run
1. Clone the repository:
    ```bash
    git clone <repository-url>
    cd graph_project
    ```

2. Compile the project:
    ```bash
    g++ main.cpp graph.cpp -o graph_project -std=c++11
    ```

3. Run the program:
    ```bash
    ./graph_project
    ```

## Example Usage
The program loads the Facebook data, displays the graph, calculates centrality measures, and finds the shortest path between two users. Example output:
```bash
Shortest path: User1 -> User2 -> User10
Degree Centrality of User1: 0.25
