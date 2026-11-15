#ifndef GESTOREMPRESA_HPP
#define GESTOREMPRESA_HPP

#include <vector>
#include "Garrafa.hpp"
#include "Accesorio.hpp"
#include "Cliente.hpp"
#include "Empleado.hpp"
#include "Pedido.hpp"

class GestorEmpresa {
private:
    std::vector<Articulo*> articulos;
    std::vector<Cliente*> clientes;
    std::vector<Empleado*> empleados;
    std::vector<Pedido*> pedidos;

public:
    GestorEmpresa();
    ~GestorEmpresa();

    void cargarGarrafa(int id, std::string nombre, double precio, double capKg, std::string tamano);
    void cargarAccesorio(int id, std::string nombre, double precio, std::string tipoAccesorio, std::string material);
    void cargarCliente(int id, std::string nombre, std::string dni, std::string tel);
    void cargarEmpleado(int id, std::string nombre, std::string dni, std::string legajo, std::string puesto);

    Articulo* buscarArticuloPorId(int id);
    Cliente* buscarClientePorId(int id);
    Empleado* buscarEmpleadoPorId(int id);

    Pedido* crearPedido(int idPedido, int idCliente, int idEmpleado);

    void listarArticulos() const;
    void listarClientes() const;
    void listarEmpleados() const;
    void mostrarTodosLosPedidos() const;
};

#endif
