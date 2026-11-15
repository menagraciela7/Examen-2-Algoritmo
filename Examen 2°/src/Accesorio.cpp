#include "Accesorio.hpp"

Accesorio::Accesorio(int id, std::string nombre, double precioUnitario, std::string tipoAccesorio, std::string material)
    : Articulo(id, nombre, "Accesorio", precioUnitario), tipoAccesorio(tipoAccesorio), material(material) {}

std::string Accesorio::getTipoAccesorio() const { return tipoAccesorio; }
std::string Accesorio::getMaterial() const { return material; }

std::string Accesorio::obtenerDetalleTecnico() const {
    return "Tipo: " + tipoAccesorio + " | Material: " + material;
}

void Accesorio::mostrarInfo() const {
    std::cout << "ID: " << id << " | " << nombre << " (" << categoria << ") - $" << precioUnitario
              << " | " << obtenerDetalleTecnico() << std::endl;
}
