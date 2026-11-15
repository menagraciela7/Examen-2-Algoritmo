#include "Garrafa.hpp"

Garrafa::Garrafa(int id, std::string nombre, double precioUnitario, double capacidadKg, std::string tamano)
    : Articulo(id, nombre, "Garrafa", precioUnitario), capacidadKg(capacidadKg), tamano(tamano) {}

double Garrafa::getCapacidadKg() const { return capacidadKg; }
std::string Garrafa::getTamano() const { return tamano; }

std::string Garrafa::obtenerDetalleTecnico() const {
    return "Capacidad: " + std::to_string((int)capacidadKg) + " kg | Tamano: " + tamano;
}

void Garrafa::mostrarInfo() const {
    std::cout << "ID: " << id << " | " << nombre << " (" << categoria << ") - $" << precioUnitario
              << " | " << obtenerDetalleTecnico() << std::endl;
}
