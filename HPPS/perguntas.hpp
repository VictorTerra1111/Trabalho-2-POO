#ifndef PERGUNTAS_HPP
#define PERGUNTAS_HPP

#include <string>
#include <list>
#include "Obras.hpp"

// declaracao das funcoes para cada pergunta sem implementacao

int acharMaisAntigo(list<Obras> lista);

string livroOuFilme(list<Obras> lista);

string Subgenero(list<Obras> lista);

string nemFilmesNemLivros(list<Obras> lista);

string acharMaisNovo(list<Obras> lista);

void tabelaDados(list<Obras> lista);

#endif
