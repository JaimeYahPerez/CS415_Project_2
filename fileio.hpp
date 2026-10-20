#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>
#include <vector>

#include "client.hpp"

std::vector<Client> readClients(const std::string& filename);

#endif