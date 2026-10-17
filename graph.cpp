#include "graph.hpp"

Graph::Graph(int numberOfVertices) {
    adjacencyList.resize(numberOfVertices);
}

void Graph::addEdge(int from, int to, int weight) {
    Edge edge{ to, weight };
    adjacencyList[from].push_back(edge);
}

const std::vector<Edge>& Graph::getNeighbors(int vertex) const {
    return adjacencyList[vertex];
}

int Graph::getVertexCount() const {
    return static_cast<int>(adjacencyList.size());
}


Graph buildRentalGraph(const std::vector<Client>& clients)
{
    int n = static_cast<int>(clients.size());

    int startVertex = 0;
    int endVertex = n + 1;

    Graph graph(n + 2);

    std::vector<bool> hasIncoming(n + 1, false);
    std::vector<bool> hasOutgoing(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (clients[i].end <= clients[j].start)
            {
                int fromVertex = clients[i].id;
                int toVertex = clients[j].id;

                graph.addEdge(
                    fromVertex,
                    toVertex,
                    clients[i].revenue
                );

                hasOutgoing[fromVertex] = true;
                hasIncoming[toVertex] = true;
            }
        }
    }

    // Add START edges
    for (int i = 1; i <= n; i++)
    {
        if (!hasIncoming[i])
        {
            graph.addEdge(startVertex, i, 0);
        }
    }

    // Add END edges
    for (int i = 1; i <= n; i++)
    {
        if (!hasOutgoing[i])
        {
            graph.addEdge(
                i,
                endVertex,
                clients[i - 1].revenue
            );
        }
    }

    return graph;
}
