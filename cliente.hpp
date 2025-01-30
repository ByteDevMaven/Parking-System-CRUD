#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "libs.hpp"
#include "vehiculo.hpp"

class cliente : public vehiculo
{
private:
    int dni;
    char nombre[20];
    char apellido[20];
    bool premium;

public:
    cliente();
    cliente(const char *nombre, const char *apellido, int dni, bool premium, const char *modelo, int placa, int fechaFabricacion);
    ~cliente();

    int getDni() const
    {
        return dni;
    }

    void setDni(int dni)
    {
        this->dni = dni;
    }

    bool getPremium()
    {
        return premium;
    }

    void setPremium(bool premium)
    {
        this->premium = premium;
    }

    const string getNombre()
    {
        return nombre;
    }

    void setNombre(const char *nombre)
    {
        strcpy(this->nombre, nombre);
    }

    const string getApellido()
    {
        return apellido;
    }

    void setApellido(const char *apellido)
    {
        strcpy(this->apellido, apellido);
    }
};

cliente::cliente()
{
    this->dni = -1;
}

cliente::cliente(const char *nombre, const char *apellido, int dni, bool premium, const char *modelo, int placa, int fechaFabricacion)
    : vehiculo(modelo, placa, fechaFabricacion)
{
    strcpy(this->nombre, nombre);
    strcpy(this->apellido, apellido);

    this->dni = dni;
    this->premium = premium;
}

cliente::~cliente()
{
}

#endif // CLIENTE_HPP