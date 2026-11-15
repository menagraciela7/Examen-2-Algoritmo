#include <iostream>
#include <string>
#include <limits>
#include "GestorEmpresa.hpp"

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    GestorEmpresa empresa;
    int opcion = 0;

    do {
        std::cout << "\n======================================" << std::endl;
        std::cout << "       MENU DE GESTION EMPRESA        " << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "1) Agregar empleados." << std::endl;
        std::cout << "2) Agregar cliente." << std::endl;
        std::cout << "3) Agregar articulo." << std::endl;
        std::cout << "4) Agregar pedido." << std::endl;
        std::cout << "5) Mostrar lista de empleados." << std::endl;
        std::cout << "6) Mostrar lista de clientes." << std::endl;
        std::cout << "7) Mostrar lista de articulos." << std::endl;
        std::cout << "8) Mostrar lista de pedidos." << std::endl;
        std::cout << "9) SALIR." << std::endl;
        std::cout << "Seleccione una opcion: ";
        
        if (!(std::cin >> opcion)) {
            limpiarBuffer();
            std::cout << "[Error] Ingrese un numero valido." << std::endl;
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre, dni, legajo, puesto;
                std::cout << "\n--- NUEVO EMPLEADO ---" << std::endl;
                std::cout << "ID: "; std::cin >> id; limpiarBuffer();
                if (empresa.buscarEmpleadoPorId(id) != nullptr) {
                    std::cout << "[Error] Ya existe un empleado con ese ID." << std::endl;
                    break;
                }
                std::cout << "Nombre completo: "; std::getline(std::cin, nombre);
                std::cout << "DNI: "; std::getline(std::cin, dni);
                std::cout << "Legajo: "; std::getline(std::cin, legajo);
                std::cout << "Puesto: "; std::getline(std::cin, puesto);

                empresa.cargarEmpleado(id, nombre, dni, legajo, puesto);
                std::cout << "[OK] Empleado agregado correctamente." << std::endl;
                break;
            }
            case 2: {
                int id;
                std::string nombre, dni, tel;
                std::cout << "\n--- NUEVO CLIENTE ---" << std::endl;
                std::cout << "ID: "; std::cin >> id; limpiarBuffer();
                if (empresa.buscarClientePorId(id) != nullptr) {
                    std::cout << "[Error] Ya existe un cliente con ese ID." << std::endl;
                    break;
                }
                std::cout << "Nombre completo: "; std::getline(std::cin, nombre);
                std::cout << "DNI: "; std::getline(std::cin, dni);
                std::cout << "Telefono: "; std::getline(std::cin, tel);

                empresa.cargarCliente(id, nombre, dni, tel);
                std::cout << "[OK] Cliente agregado correctamente." << std::endl;
                break;
            }
                        case 3: {
                int tipo, id;
                std::string nombre;
                double precio;
                std::cout << "\n--- NUEVO ARTICULO ---" << std::endl;
                std::cout << "Tipo (1 = Garrafa, 2 = Accesorio): ";
                std::cin >> tipo; limpiarBuffer();

                if (tipo != 1 && tipo != 2) {
                    std::cout << "[Error] Tipo de articulo invalido." << std::endl;
                    break;
                }

                std::cout << "ID: "; std::cin >> id; limpiarBuffer();
                if (empresa.buscarArticuloPorId(id) != nullptr) {
                    std::cout << "[Error] Ya existe un articulo con ese ID." << std::endl;
                    break;
                }
                std::cout << "Nombre: "; std::getline(std::cin, nombre);
                std::cout << "Precio unitario: $"; std::cin >> precio; limpiarBuffer();

                if (tipo == 1) {
                    double capKg;
                    std::string tamano;
                    std::cout << "Capacidad (kg): "; std::cin >> capKg; limpiarBuffer();
                    std::cout << "Tamano (ej. Chica, Mediana, Grande): "; std::getline(std::cin, tamano);
                    empresa.cargarGarrafa(id, nombre, precio, capKg, tamano);
                } else {
                    std::string tipoAccesorio, material;
                    std::cout << "Tipo de accesorio (ej. Valvula, Manguera): "; std::getline(std::cin, tipoAccesorio);
                    std::cout << "Material: "; std::getline(std::cin, material);
                    empresa.cargarAccesorio(id, nombre, precio, tipoAccesorio, material);
                }
                std::cout << "[OK] Articulo agregado correctamente." << std::endl;
                break;
            }
            case 4: {
                int idPedido, idCliente, idEmpleado;
                std::cout << "\n--- NUEVO PEDIDO ---" << std::endl;
                std::cout << "ID del Pedido: "; std::cin >> idPedido; limpiarBuffer();
                std::cout << "ID del Cliente: "; std::cin >> idCliente; limpiarBuffer();
                std::cout << "ID del Empleado que atiende: "; std::cin >> idEmpleado; limpiarBuffer();

                Pedido* nuevoPedido = empresa.crearPedido(idPedido, idCliente, idEmpleado);
                if (nuevoPedido == nullptr) {
                    std::cout << "[Error] Cliente o Empleado no encontrado. Verifique los IDs." << std::endl;
                    break;
                }

                char continuar = 's';
                while (continuar == 's' || continuar == 'S') {
                    int idArt, cant;
                    std::cout << "ID del Articulo a agregar: "; std::cin >> idArt; limpiarBuffer();
                    Articulo* art = empresa.buscarArticuloPorId(idArt);

                    if (art != nullptr) {
                        std::cout << "Cantidad: "; std::cin >> cant; limpiarBuffer();
                        if (cant > 0) {
                            nuevoPedido->agregarArticulo(art, cant);
                            std::cout << "[OK] Articulo agregado al pedido." << std::endl;
                        } else {
                            std::cout << "[Error] La cantidad debe ser mayor a 0." << std::endl;
                        }
                    } else {
                        std::cout << "[Error] Articulo no encontrado." << std::endl;
                    }

                    std::cout << "Desea agregar otro articulo al pedido? (s/n): ";
                    std::cin >> continuar; limpiarBuffer();
                }
                std::cout << "[OK] Pedido #" << idPedido << " registrado con exito." << std::endl;
                break;
            }
            case 5:
                empresa.listarEmpleados();
                break;
            case 6:
                empresa.listarClientes();
                break;
            case 7:
                empresa.listarArticulos();
                break;
            case 8:
                empresa.mostrarTodosLosPedidos();
                break;
            case 9:
                std::cout << "Liberando memoria y saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "[Error] Opcion invalida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 9);

    return 0;
}
