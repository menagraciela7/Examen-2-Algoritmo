#ifndef DETALLEPEDIDO_HPP
#define DETALLEPEDIDO_HPP

#include "Articulo.hpp"

class DetallePedido {
private:
    Articulo* articulo;
    int cantidad;

public:
    DetallePedido(Articulo* articulo, int cantidad);

    double calcularSubtotal() const;
    void mostrarDetalle() const;
    Articulo* getArticulo() const;
    int getCantidad() const;
};

#endif
