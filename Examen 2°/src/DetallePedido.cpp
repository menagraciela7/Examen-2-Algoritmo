#include "DetallePedido.hpp"
#include <iostream>

DetallePedido::DetallePedido(Articulo* articulo, int cantidad)
    : articulo(articulo), cantidad(cantidad) {}

double DetallePedido::calcularSubtotal() const {
    return articulo->getPrecioUnitario() * cantidad;
}

void DetallePedido::mostrarDetalle() const {
    std::cout << "  - " << articulo->getNombre() << " x" << cantidad 
              << " ($" << articulo->getPrecioUnitario() << " c/u) = $" << calcularSubtotal() << std::endl;
}

Articulo* DetallePedido::getArticulo() const { return articulo; }
int DetallePedido::getCantidad() const { return cantidad; }
