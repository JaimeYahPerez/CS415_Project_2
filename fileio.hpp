#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>

#include "client.h"

std::vector<Client> readClients(const std::string& filename);

#endif