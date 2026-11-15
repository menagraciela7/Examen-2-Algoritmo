#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "Articulo.hpp"

class Accesorio : public Articulo {
private:
    std::string tipoAccesorio;
    std::string material;

public:
    Accesorio(int id, std::string nombre, double precioUnitario, std::string tipoAccesorio, std::string material);

    std::string getTipoAccesorio() const;
    std::string getMaterial() const;

    std::string obtenerDetalleTecnico() const override;
    void mostrarInfo() const override;
};

#endif

