#ifndef FILE_MANAGE_HPP
#define FILE_MANAGE_HPP

#include "Obras.hpp"
#include <list>
// HPP sem a implementacao da funcao que le as informacoes do banco de dados 
// e retorna uma lista do tipo Obras

list<Obras> ReadInfo();

#endif