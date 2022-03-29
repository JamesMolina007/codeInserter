#pragma once

using namespace std;

class animal{
    private:
        string familia;
        string genero;
        int edad;
    public:
        animal();
        void setFamilia(string familia);
        string getFamilia();
        void setGenero(string genero);
        string getGenero();
        void setEdad(int edad);
        int getEdad();
};