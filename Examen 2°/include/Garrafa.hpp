#ifndef GARRAFA_HPP
#define GARRAFA_HPP

#include "Articulo.hpp"

class Garrafa : public Articulo {
private:
    double capacidadKg;
    std::string tamano;

public:
    Garrafa(int id, std::string nombre, double precioUnitario, double capacidadKg, std::string tamano);
    
    double getCapacidadKg() const;
    std::string getTamano() const;

    std::string obtenerDetalleTecnico() const override;
    void mostrarInfo() const override;
};

#endif

