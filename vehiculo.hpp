#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "libs.hpp"

class vehiculo
{
private:
    char modelo[20];
    int placa;
    int fechaFabricacion;

public:
    vehiculo();
    vehiculo(const char *modelo, int placa, int fechaFabricacion);
    ~vehiculo();

    void setModelo(const char *modelo)
    {
        strcpy(this->modelo, modelo);
    }

    string getModelo()
    {
        return modelo;
    }

    void setApellido(const char *modelo)
    {
        strcpy(this->modelo, modelo);
    }

    int getPlaca()
    {
        return placa;
    }

    void setPlaca(int placa)
    {
        this->placa = placa;
    }

    int getFechaFabricacion()
    {
        return fechaFabricacion;
    }

    void setFechaFabricacion(int fechaFabricacion)
    {
        this->fechaFabricacion = fechaFabricacion;
    }
};

vehiculo::vehiculo()
{
}

vehiculo::vehiculo(const char *modelo, int placa, int fechaFabricacion)
{
    strcpy(this->modelo, modelo);

    this->placa = placa;
    this->fechaFabricacion = fechaFabricacion;
}

vehiculo::~vehiculo()
{
}

#endif // VEHICULO_HPP