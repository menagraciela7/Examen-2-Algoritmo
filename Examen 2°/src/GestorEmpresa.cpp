#include "GestorEmpresa.hpp"
#include <iostream>

GestorEmpresa::GestorEmpresa() {}

GestorEmpresa::~GestorEmpresa() {
    for (Articulo* art : articulos) delete art;
    for (Cliente* cli : clientes) delete cli;
    for (Empleado* emp : empleados) delete emp;
    for (Pedido* ped : pedidos) delete ped;

    articulos.clear();
    clientes.clear();
    empleados.clear();
    pedidos.clear();
}

void GestorEmpresa::cargarGarrafa(int id, std::string nombre, double precio, double capKg, std::string tamano) {
    articulos.push_back(new Garrafa(id, nombre, precio, capKg, tamano));
}

void GestorEmpresa::cargarAccesorio(int id, std::string nombre, double precio, std::string tipoAccesorio, std::string material) {
    articulos.push_back(new Accesorio(id, nombre, precio, tipoAccesorio, material));
}

void GestorEmpresa::cargarCliente(int id, std::string nombre, std::string dni, std::string tel) {
    clientes.push_back(new Cliente(id, nombre, dni, tel));
}

void GestorEmpresa::cargarEmpleado(int id, std::string nombre, std::string dni, std::string legajo, std::string puesto) {
    empleados.push_back(new Empleado(id, nombre, dni, legajo, puesto));
}

Articulo* GestorEmpresa::buscarArticuloPorId(int id) {
    for (Articulo* art : articulos) {
        if (art->getId() == id) return art;
    }
    return nullptr;
}

Cliente* GestorEmpresa::buscarClientePorId(int id) {
    for (Cliente* cli : clientes) {
        if (cli->getId() == id) return cli;
    }
    return nullptr;
}

Empleado* GestorEmpresa::buscarEmpleadoPorId(int id) {
    for (Empleado* emp : empleados) {
        if (emp->getId() == id) return emp;
    }
    return nullptr;
}

Pedido* GestorEmpresa::crearPedido(int idPedido, int idCliente, int idEmpleado) {
    Cliente* cli = buscarClientePorId(idCliente);
    Empleado* emp = buscarEmpleadoPorId(idEmpleado);
    if (cli != nullptr && emp != nullptr) {
        Pedido* nuevoPedido = new Pedido(idPedido, cli, emp);
        pedidos.push_back(nuevoPedido);
        return nuevoPedido;
    }
    return nullptr;
}

void GestorEmpresa::listarArticulos() const {
    std::cout << "\n--- LISTA DE ARTICULOS ---" << std::endl;
    if (articulos.empty()) {
        std::cout << "No hay articulos registrados." << std::endl;
        return;
    }
    for (const Articulo* art : articulos) {
        art->mostrarInfo();
    }
}

void GestorEmpresa::listarClientes() const {
    std::cout << "\n--- LISTA DE CLIENTES ---" << std::endl;
    if (clientes.empty()) {
        std::cout << "No hay clientes registrados." << std::endl;
        return;
    }
    for (const Cliente* cli : clientes) {
        cli->mostrarInfo();
    }
}

void GestorEmpresa::listarEmpleados() const {
    std::cout << "\n--- LISTA DE EMPLEADOS ---" << std::endl;
    if (empleados.empty()) {
        std::cout << "No hay empleados registrados." << std::endl;
        return;
    }
    for (const Empleado* emp : empleados) {
        emp->mostrarInfo();
    }
}

void GestorEmpresa::mostrarTodosLosPedidos() const {
    std::cout << "\n--- LISTA DE PEDIDOS ---" << std::endl;
    if (pedidos.empty()) {
        std::cout << "No hay pedidos registrados." << std::endl;
        return;
    }
    for (const Pedido* ped : pedidos) {
        ped->mostrarPedido();
    }
}
