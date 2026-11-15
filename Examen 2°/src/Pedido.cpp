#include "Pedido.hpp"
#include <iostream>

Pedido::Pedido(int idPedido, Cliente* cliente, Empleado* empleado)
    : idPedido(idPedido), cliente(cliente), empleado(empleado) {}

Pedido::~Pedido() {
    for (DetallePedido* item : items) {
        delete item;
    }
    items.clear();
}

void Pedido::agregarArticulo(Articulo* art, int cant) {
    items.push_back(new DetallePedido(art, cant));
}

double Pedido::calcularTotal() const {
    double total = 0.0;
    for (const DetallePedido* item : items) {
        total += item->calcularSubtotal();
    }
    return total;
}

int Pedido::getIdPedido() const { return idPedido; }
Cliente* Pedido::getCliente() const { return cliente; }
Empleado* Pedido::getEmpleado() const { return empleado; }

void Pedido::mostrarPedido() const {
    std::cout << "\n=== PEDIDO #" << idPedido << " ===" << std::endl;
    std::cout << "Cliente: " << cliente->getNombreCompleto() << " (ID: " << cliente->getId() << ")" << std::endl;
    std::cout << "Atendido por: " << empleado->getNombreCompleto() << " (Leg. " << empleado->getLegajo() << ")" << std::endl;
    std::cout << "Items:" << std::endl;
    for (const DetallePedido* item : items) {
        item->mostrarDetalle();
    }
    std::cout << "TOTAL A PAGAR: $" << calcularTotal() << std::endl;
}
