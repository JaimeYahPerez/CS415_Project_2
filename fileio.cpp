#include "fileio.hpp"

#include <fstream>
#include <iostream>

std::vector<Client> readClients(const std::string& filename) {
    std::vector<Client> clients;

    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error: could not open " << filename << '\n';
        return clients;
    }

    int start;
    int end;
    int revenue;
    int id = 1;

    while (inputFile >> start >> end >> revenue) {
        Client client;

        client.id = id;
        client.start = start;
        client.end = end;
        client.revenue = revenue;

        clients.push_back(client);

        id++;
    }

    inputFile.close();

    return clients;
}