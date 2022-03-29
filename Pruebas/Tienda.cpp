#include "Tienda.hpp"

Tienda::Tienda(){
}

void Tienda::setPersonas(Vector<Persona> personas){
    this->personas = personas;
}


Vector<Persona> Tienda::getPersonas(){
    return personas;
}


void Tienda::setNumero(int numero){
    this->numero = numero;
}


int Tienda::getNumero(){
    return numero;
}


void Tienda::setDireccion(string direccion){
    this->direccion = direccion;
}


string Tienda::getDireccion(){
    return direccion;
}


