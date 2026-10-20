
#ifndef TOPOSORT_HPP
#define TOPOSORT_HPP

#include "graph.hpp"
#include <vector>

struct OptimalRental {
    long long revenue;
    std::vector<int> clients;
};

std::vector<int> topologicalSort(const Graph& graph);

OptimalRental findOptimalRental(
    const Graph& graph,
    int startVertex,
    int endVertex
);

#endif
