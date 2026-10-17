#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "client.hpp"

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

Graph buildRentalGraph(const std::vector<Client>& clients);
#endif