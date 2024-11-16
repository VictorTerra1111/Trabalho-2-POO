#ifndef OBRAS_HPP
#define OBRAS_HPP

#include <string>

using namespace std;
// classe Obras sem implementacao
class Obras {
private:
    string titulo;
    string autor;
    string midia;
    string subGenero;
    int anoPublicacao;
public:
    Obras(string vtitulo = "null", string vautor = "null", string vsubGenero = "null", string vmidia = "null", int vanoPublicacao = 0);

    string getTitulo() const;
    string getAutor() const;
    string getsubGenero() const;
    string getMidia() const;
    int getAnoPublicacao() const;
};

#endif
