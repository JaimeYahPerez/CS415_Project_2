#include "graph.h"

Graph::Graph(int numberOfVertices) {
    adjacencyList.resize(numberOfVertices);
}

void Graph::addEdge(int from, int to, int weight) {
    Edge edge;

    edge.destination = to;
    edge.weight = weight;

    adjacencyList[from].push_back(edge);
}

const std::vector<Edge>& Graph::getNeighbors(int vertex) const {
    return adjacencyList[vertex];
}

int Graph::getVertexCount() const {
    return static_cast<int>(adjacencyList.size());
}