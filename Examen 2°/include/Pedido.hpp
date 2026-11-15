#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <vector>
#include "Cliente.hpp"
#include "Empleado.hpp"
#include "DetallePedido.hpp"

class Pedido {
private:
    int idPedido;
    Cliente* cliente;
    Empleado* empleado;
    std::vector<DetallePedido*> items; // Memoria dinámica

public:
    Pedido(int idPedido, Cliente* cliente, Empleado* empleado);
    ~Pedido(); // Libera los DetallePedido creados con new

    void agregarArticulo(Articulo* art, int cant);
    double calcularTotal() const;
    int getIdPedido() const;
    Cliente* getCliente() const;
    Empleado* getEmpleado() const;
    void mostrarPedido() const;
};

#endif
