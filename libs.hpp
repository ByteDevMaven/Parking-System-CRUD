#ifndef LIBS_HPP
#define LIBS_HPP

#define DATA_FILE "data/clientes.bin"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::getline;

using std::string;

using std::ifstream; // Open a binary file for reading
using std::ios;      // Type of file to open binary or text
using std::ofstream; // Open a binary file for writing

using std::vector;
using std::find_if;

using std::numeric_limits;
using std::streamsize;

using std::fixed;
using std::left;
using std::right;
using std::showpoint;

using std::setprecision;
using std::setw;

#define ofsERROR "No se puede abrir el archivo para escritura!"
#define ifsERROR "No se puede abrir el archivo para lectura!"
#define ifsERRORcatch "Error al asignar los valores del archivo al vector!"

#endif // LIBS_HPP