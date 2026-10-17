#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>

#include "client.hpp"

std::vector<Client> readClients(const std::string& filename);

#endif