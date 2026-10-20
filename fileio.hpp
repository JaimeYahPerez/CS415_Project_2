#ifndef fileio
#define fileio

#include <string>
#include <vector>

#include "client.hpp"

std::vector<Client> readClients(const std::string& filename);

#endif