#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Edge {
    int destination;
    int weight;
};

class Graph {
private:
    std::vector<std::vector<Edge>> adjacencyList;

public:
    Graph(int numberOfVertices);

    void addEdge(int from, int to, int weight);

    const std::vector<Edge>& getNeighbors(int vertex) const;

    int getVertexCount() const;
};

#endif