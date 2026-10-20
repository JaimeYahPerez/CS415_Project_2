
#include "toposort.hpp"

#include <queue>
#include <stdexcept>
#include <limits>

// Topological Sorting time.
std::vector<int> topologicalSort(const Graph& graph)
{
    int n = graph.getVertexCount();
    std::vector<int> inDegree(n, 0);

    for (int u = 0; u < n; ++u) {
        for (const Edge& edge : graph.getNeighbors(u)) {
            inDegree[edge.destination]++;
        }
    }

    std::queue<int> q;

    for (int v = 0; v < n; ++v) {
        if (inDegree[v] == 0) {
            q.push(v);
        }
    }

    std::vector<int> order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for (const Edge& edge : graph.getNeighbors(u)) {
            int v = edge.destination;

            inDegree[v]--;

            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (static_cast<int>(order.size()) != n) {
        throw std::runtime_error("Graph is not a DAG.");
    }

    return order;
}

// Finds the maximum revenue and as well as the optimal route to doing so.
OptimalRental findOptimalRental(
    const Graph& graph,
    int startVertex,
    int endVertex)
{
    int n = graph.getVertexCount();
    std::vector<int> order = topologicalSort(graph);

    const long long UNREACHABLE =
        std::numeric_limits<long long>::lowest();

    std::vector<long long> revenue(n, UNREACHABLE);
    std::vector<int> nextVertex(n, -1);

    // Base case: END has no additional revenue.
    revenue[endVertex] = 0;

    // Process vertices in reverse topological order.
    for (int i = static_cast<int>(order.size()) - 1;
         i >= 0; --i) {

        int u = order[i];

        if (u == endVertex) {
            continue;
        }

        for (const Edge& edge : graph.getNeighbors(u)) {
            int v = edge.destination;

            if (revenue[v] == UNREACHABLE) {
                continue;
            }

            long long candidate =
                static_cast<long long>(edge.weight) + revenue[v];

            if (candidate > revenue[u]) {
                revenue[u] = candidate;
                nextVertex[u] = v;
            }
        }
    }

    if (revenue[startVertex] == UNREACHABLE) {
        throw std::runtime_error("No path from START to END.");
    }

    // Reconstruct the optimal path.
    std::vector<int> selectedClients;
    int current = startVertex;

    while (current != endVertex) {
        current = nextVertex[current];

        if (current == -1) {
            throw std::runtime_error(
                "Could not reconstruct optimal path."
            );
        }

        // Making sure that the Start and End are not clients. 
        if (current != endVertex) {
            selectedClients.push_back(current);
        }
    }

    return {revenue[startVertex], selectedClients};
}
