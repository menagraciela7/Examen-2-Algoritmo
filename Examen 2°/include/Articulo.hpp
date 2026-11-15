#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include <string>
#include <iostream>

// Clase Abstracta
class Articulo {
protected:
    int id;
    std::string nombre;
    std::string categoria;
    double precioUnitario;

public:
    Articulo(int id, std::string nombre, std::string categoria, double precioUnitario);
    virtual ~Articulo();

    int getId() const;
    std::string getNombre() const;
    std::string getCategoria() const;
    double getPrecioUnitario() const;

    // Métodos virtuales puros: convierten a Articulo en clase abstracta
    virtual std::string obtenerDetalleTecnico() const = 0;
    virtual void mostrarInfo() const = 0;
};

#endif
