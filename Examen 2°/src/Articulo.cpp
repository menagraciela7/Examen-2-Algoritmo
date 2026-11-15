#include "Articulo.hpp"

Articulo::Articulo(int id, std::string nombre, std::string categoria, double precioUnitario)
    : id(id), nombre(nombre), categoria(categoria), precioUnitario(precioUnitario) {}

Articulo::~Articulo() {}

int Articulo::getId() const { return id; }
std::string Articulo::getNombre() const { return nombre; }
std::string Articulo::getCategoria() const { return categoria; }
double Articulo::getPrecioUnitario() const { return precioUnitario; }
