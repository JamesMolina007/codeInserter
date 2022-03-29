#pragma once

using namespace std;

class Tienda{
    private:
        Vector<Persona> personas;
        int numero;
        string direccion;
    public:
        Tienda();
        void setPersonas(Vector<Persona> personas);
        Vector<Persona> getPersonas();
        void setNumero(int numero);
        int getNumero();
        void setDireccion(string direccion);
        string getDireccion();
};