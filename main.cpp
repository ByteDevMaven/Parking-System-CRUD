/*
Estudiante: Carlos Andres Parada Sanchez
N. Cuenta:  #32221069
Caso: Parqueo privado en el que ingresan diferentes vehículos y pagan el servicio
por hora, día o semana.
*/
#include "libs.hpp"
#include "parqueo.hpp"
#include "cliente.hpp"

void impresion(cliente cls);

int main(int argc, char const *argv[])
{
    // Variables del main
    int opcion = 0;
    bool run = true;
    parqueo parqueoMall(5.99, 49.99, 99.99);

    // Variables para el construc
    string nombre, apellido, modelo;
    int dni, placa, fechaFabricaion;
    bool premium = false;
    char p;
    double tiempo;
    int tipoPago;

    cout << fixed << showpoint;
    while (run)
    {
        cout << " 1. Ingreso de Cliente \n";
        cout << " 2. Leer archivos Clientes \n";
        cout << " 3. Consulta de Cliente \n";
        cout << " 4. Actualizacion de Cliente \n";
        cout << " 5. Borrado de Cliente \n";
        cout << " 6. Salir \n";
        cout << " Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nombre);

            cout << "Ingrese el apellido: ";
            getline(cin, apellido);

            cout << "Digite el DNI: ";
            cin >> dni;

            cout << "El cliente es Premium? S/N: ";
            cin >> p;
            if (p == 'S' || p == 's')
            {
                premium = true;
            }
            else
            {
                premium = false;
            }

            cout << "Ingrese el modelo del automovil: ";
            cin.ignore();
            getline(cin, modelo);

            cout << "Digite el numero de Placa del auto: ";
            cin >> placa;

            cout << "Digite la fecha de fabricacion: ";
            cin >> fechaFabricaion;

            cout << "Digite el tiempo que el cliente estara: ";
            cin >> tiempo;

            cout << "Digite el tipo de pago 1: Hora, 2: Dia, 3: Semana: ";
            cin >> tipoPago;

            if (parqueoMall.buscarCliente(dni) == -1)
            {
                parqueoMall.registrarCliente(nombre.c_str(), apellido.c_str(), dni, premium, modelo.c_str(), placa, fechaFabricaion, tiempo, tipoPago);
                parqueoMall.guardarClientes();
                cout << "\a\nEl cliente se ha agregado!\n"
                     << endl;
            }
            else
            {
                cout << "\a\nEl cliente " << dni << " ya existe!\n"
                     << endl;
            }
        }
        break;

        case 2:
        {
            cout << setw(10) << left << "DNI"
                 << setw(20) << left << "Nombre"
                 << setw(20) << left << "Apellido"
                 << setw(6) << right << "Placa"
                 << setw(20) << right << "Modelo"
                 << setw(4) << right << "VIP" << endl;
            for (int i = 0; i < parqueoMall.getListaClientes().size(); i++)
            {
                impresion(parqueoMall.getListaClientes().at(i));
            }
        }
        break;

        case 3:
        {
            cout << "Digite el DNI del cliente a consultar: ";
            cin >> dni;

            cliente temp = parqueoMall.getCliente(dni);
            if (temp.getDni() != -1)
            {
                cout << "Cliente " << dni << ":" << endl;
                impresion(temp);
            }
            else
            {
                cout << "El cliente no existe!" << endl;
            }
        }
        break;

        case 4:
        {
            cout << "Digite el DNI del cliente que desea actualizar: ";
            cin >> dni;
            cliente temp = parqueoMall.getCliente(dni);
            if (temp.getDni() != -1)
            {
                cout << "Cliente " << dni << ":" << endl;
                impresion(temp);
                cout << "\n";
                cout << " 1. Actualizar Nombre " << endl;
                cout << " 2. Actualizar Apellido " << endl;
                cout << " 3. Actualizar Membresia " << endl;
                cout << " 4. Actualizar Modelo del Carro " << endl;
                cout << " 5. Actualizar Placa " << endl;
                cout << " 6. Actualizar Fecha de Fabricacion " << endl;
                cout << " Ingrese su opcion: " << endl;
                cin >> opcion;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (opcion)
                {
                case 1:
                {
                    cout << "Ingrese el nombre: ";
                    getline(cin, nombre);
                    temp.setNombre(nombre.c_str());
                }
                break;
                case 2:
                {
                    cout << "Ingrese el apellido: ";
                    getline(cin, apellido);
                    temp.setApellido(apellido.c_str());
                }
                break;
                case 3:
                {
                    cout << "El cliente es Premium? S/N: ";
                    cin >> p;
                    if (p == 'S' || p == 's')
                    {
                        premium = true;
                    }
                    else
                    {
                        premium = false;
                    }
                    temp.setPremium(premium);
                }
                break;
                case 4:
                {
                    cout << "Ingrese el modelo del automovil: ";
                    getline(cin, modelo);
                    temp.setModelo(modelo.c_str());
                }
                break;
                case 5:
                {
                    cout << "Digite el numero de Placa del auto: ";
                    cin >> placa;
                    temp.setPlaca(placa);
                }
                break;
                case 6:
                {
                    cout << "Digite la fecha de fabricacion: ";
                    cin >> fechaFabricaion;
                    temp.setFechaFabricacion(fechaFabricaion);
                }
                break;

                default:
                    cout << "\nOpcion incorrecta." << endl;
                    break;
                }
                if (parqueoMall.actualizarCliente(temp) == 0)
                    cout << "Se actualizo el cliente correctamente!" << endl;
                    parqueoMall.guardarClientes();
            }
            else
            {
                cout << "El cliente no existe!" << endl;
            }
        }
        break;

        case 5:
        {
            cout << "Digite el DNI del cliente que desea borrar: ";
            cin >> dni;

            if (parqueoMall.borrarCliente(dni) == 1)
            {
                cout << "No se borro el cliente o no existe!" << endl;
            }
            else
            {
                cout << "El cliente ha sido borrado exitosamente!" << endl;
                parqueoMall.guardarClientes();
            }
        }
        break;

        case 6:
        {
            cout << "Programa terminado." << endl;
            run = false;
        }
        break;

        default:
            cout << "ERROR! Opcion invalida.\n"
                 << endl;
            break;
        }
    }

    return 0;
}

void impresion(cliente cls)
{
    cout << setw(10) << left << cls.getDni()
         << setw(20) << left << cls.getNombre()
         << setw(20) << left << cls.getApellido()
         << setw(6) << right << cls.getPlaca()
         << setw(20) << right << cls.getModelo()
         << setw(4) << right << (cls.getPremium() ? "SI" : "NO") << endl;
}