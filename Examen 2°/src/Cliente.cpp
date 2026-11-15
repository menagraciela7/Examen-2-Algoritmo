#include "Cliente.hpp"

Cliente::Cliente(int id, std::string nombreCompleto, std::string dni, std::string telefono)
    : id(id), nombreCompleto(nombreCompleto), dni(dni), telefono(telefono) {}

int Cliente::getId() const { return id; }
std::string Cliente::getNombreCompleto() const { return nombreCompleto; }
std::string Cliente::getDni() const { return dni; }
std::string Cliente::getTelefono() const { return telefono; }

void Cliente::mostrarInfo() const {
    std::cout << "ID: " << id << " | Nombre: " << nombreCompleto << " | DNI: " << dni << " | Tel: " << telefono << std::endl;
}
