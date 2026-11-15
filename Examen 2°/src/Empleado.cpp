#include "Empleado.hpp"

Empleado::Empleado(int id, std::string nombreCompleto, std::string dni, std::string legajo, std::string puesto)
    : id(id), nombreCompleto(nombreCompleto), dni(dni), legajo(legajo), puesto(puesto) {}

int Empleado::getId() const { return id; }
std::string Empleado::getNombreCompleto() const { return nombreCompleto; }
std::string Empleado::getDni() const { return dni; }
std::string Empleado::getLegajo() const { return legajo; }
std::string Empleado::getPuesto() const { return puesto; }

void Empleado::mostrarInfo() const {
    std::cout << "ID: " << id << " | Nombre: " << nombreCompleto << " | DNI: " << dni 
              << " | Legajo: " << legajo << " | Puesto: " << puesto << std::endl;
}
