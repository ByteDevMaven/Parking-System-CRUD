#ifndef PARQUEO_HPP
#define PARQUEO_HPP

#include "libs.hpp"
#include "cliente.hpp"

class parqueo
{
private:
    double tarifHora;
    double tarifDia;
    double tarifSemana;

    vector<cliente> vectClientes;

public:
    parqueo(double tarifHora, double tarifDia, double tarifSemana);
    ~parqueo();

    double getTarifHora()
    {
        return tarifHora;
    }

    void setTarifHora(double tarifHora)
    {
        this->tarifHora = tarifHora;
    }

    double getTarifDia()
    {
        return tarifDia;
    }

    void setTarifDia(double tarifDia)
    {
        this->tarifDia = tarifDia;
    }

    double getTarifSemana()
    {
        return tarifSemana;
    }

    void setTarifSemana(double tarifSemana)
    {
        this->tarifSemana = tarifSemana;
    }

    void registrarCliente(const char *nombre, const char *apellido, int dni, bool premium, const char *modelo, int placa, int fechaFabricacion, double tiempo, int tipoPago)
    {
        cliente temp(nombre, apellido, dni, premium, modelo, placa, fechaFabricacion);

        vectClientes.push_back(temp);

        ofstream ofsTXT("data/PAGOS.txt", ios::app);
        if (ofsTXT)
        {
            ofsTXT << dni << " " << premium << " " << placa << " " << tiempo << " " << tipoPago << endl;
        }
    }

    int guardarClientes()
    {
        ofstream ofsT(DATA_FILE, ios::trunc);

        if (!ofsT.is_open())
        {
            std::cerr << "TRUNC ERROR!" << endl;
            return 1;
        }

        ofsT.close();

        ofstream ofs(DATA_FILE, ios::out | ios::binary | ios::app);
        if (!ofs)
        {
            cerr << ofsERROR << endl;
            return -1;
        }

        for (const auto &client : vectClientes)
        {
            ofs.write(reinterpret_cast<const char *>(&client), sizeof(cliente));
        }
        ofs.close();

        return 0;
    }

    int cargarClientes()
    {
        cliente temp;

        ifstream ifs(DATA_FILE, ios::in | ios::binary);
        if (!ifs)
        {
            cerr << ifsERROR << endl;
            return -1;
        }

        try
        {
            vectClientes.clear();
            while (ifs.read(reinterpret_cast<char *>(&temp), sizeof(cliente)))
            {
                vectClientes.push_back(temp);
            }
            ifs.close();
        }
        catch (const exception &e)
        {
            vectClientes.clear();
            ifs.close();
            cerr << e.what() << '\n'
                 << ifsERRORcatch << '\n';
            return 1;
        }

        return 0;
    }

    int actualizarCliente(cliente cls)
    {
        int id = buscarCliente(cls.getDni());

        if (id == -1)
        {
            return -1;
        }

        if (id < vectClientes.size())
        {
            vectClientes.at(id) = cls;
            return 0;
        }
        else
        {
            return 2;
        }
    }

    int borrarCliente(int dni)
    {
        if (buscarCliente(dni) == -1)
        {
            return 1;
        }

        auto it = find_if(vectClientes.begin(), vectClientes.end(), [dni](const cliente &c)
                          { return c.getDni() == dni; });
        vectClientes.erase(it);
        return 0;
    }

    int buscarCliente(int dni)
    {
        for (int i = 0; i < vectClientes.size(); ++i)
        {
            if (vectClientes.at(i).getDni() == dni)
            {
                return i;
            }
        }

        return -1;
    }

    cliente getCliente(int dni)
    {
        int id = buscarCliente(dni);

        if (id == -1)
        {
            return cliente();
        }

        return vectClientes.at(id);
    }

    vector<cliente> getListaClientes()
    {
        return vectClientes;
    }
};

parqueo::parqueo(double tarifHora, double tarifDia, double tarifSemana)
{
    this->tarifHora = tarifHora;
    this->tarifDia = tarifDia;
    this->tarifSemana = tarifSemana;
    cargarClientes();
}

parqueo::~parqueo()
{
}

#endif // PARQUEO_HPP