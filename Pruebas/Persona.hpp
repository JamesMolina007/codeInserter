#pragma once

using namespace std;

class Persona{
    private:
        int edad;
        string nombre;
        string apellido;
        int telefono;
    public:
        Persona();
        void setEdad(int edad);
        int getEdad();
        void setNombre(string nombre);
        string getNombre();
        void setApellido(string apellido);
        string getApellido();
        void setTelefono(int telefono);
        int getTelefono();
};