#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <iostream>

class Cliente {
private:
    int id;
    std::string nombreCompleto;
    std::string dni;
    std::string telefono;

public:
    Cliente(int id, std::string nombreCompleto, std::string dni, std::string telefono);

    int getId() const;
    std::string getNombreCompleto() const;
    std::string getDni() const;
    std::string getTelefono() const;
    void mostrarInfo() const;
};

#endif
