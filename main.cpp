
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "fileio.hpp"
#include "graph.hpp"
#include "toposort.hpp"

int main()
{
    std::string filename;

    std::cout << "Enter the file to read data: ";
    std::cin >> filename;


    std::vector<Client> clients = readClients("data/" + filename);

    if (clients.empty()) {
        std::cout << "No client data was loaded.\n";
        return 1;
    }

    // Create the output file using the input filename.
    std::string outputFilename = "outputs/out" + filename;
    std::ofstream outputFile(outputFilename);

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not open output file "
                  << outputFilename << '\n';
        return 1;
    }

    // Print client count to the terminal and output file.
    std::string clientCount =
        "\nThere are " + std::to_string(clients.size()) +
        " clients in this file\n";

    std::cout << clientCount << '\n';
    outputFile << clientCount << '\n';

    Graph graph = buildRentalGraph(clients);

    int startVertex = 0;
    int endVertex = static_cast<int>(clients.size()) + 1;

    OptimalRental result = findOptimalRental(graph, startVertex, endVertex);

    // Print optimal revenue to both destinations.
    std::string revenueLine =
        "Optimal revenue earned is " +
        std::to_string(result.revenue);

    std::cout << revenueLine << '\n';
    outputFile << revenueLine << '\n';

    // Build the list of selected clients.
    std::string clientsLine =
        "Clients contributing to this optimal revenue: ";

    for (std::size_t i = 0; i < result.clients.size(); ++i)
    {
        if (i > 0)
        {
            clientsLine += ", ";
        }

        clientsLine += std::to_string(result.clients[i]);
    }

    std::cout << clientsLine << '\n';
    outputFile << clientsLine << '\n';

    outputFile.close();

    // Debuggin'
    //std::cout << "\nOutput saved to " << outputFilename << '\n';

    return 0;
}
