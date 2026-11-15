#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>
#include <iostream>

class Empleado {
private:
    int id;
    std::string nombreCompleto;
    std::string dni;
    std::string legajo;
    std::string puesto;

public:
    Empleado(int id, std::string nombreCompleto, std::string dni, std::string legajo, std::string puesto);

    int getId() const;
    std::string getNombreCompleto() const;
    std::string getDni() const;
    std::string getLegajo() const;
    std::string getPuesto() const;
    void mostrarInfo() const;
};

#endif
