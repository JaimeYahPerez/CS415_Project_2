#include <iostream>
#include <string>
#include <vector>

#include "client.h"
#include "fileio.h"
#include "graph.h"

int main()
{
    std::string filename;

    std::cout << "Enter the file to read data: ";
    std::cin >> filename;

    std::vector<Client> clients = readClients(filename);

    if (clients.empty())
    {
        std::cout << "No client data was loaded.\n";
        return 1;
    }

    std::cout << "\nThere are "
        << clients.size()
        << " clients in this file\n\n";

    Graph graph = buildRentalGraph(clients);



    return 0;
}