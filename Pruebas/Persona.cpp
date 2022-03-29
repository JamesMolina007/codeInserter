#include "Persona.hpp"

Persona::Persona(){
}

void Persona::setEdad(int edad){
    this->edad = edad;
}


int Persona::getEdad(){
    return edad;
}


void Persona::setNombre(string nombre){
    this->nombre = nombre;
}


string Persona::getNombre(){
    return nombre;
}


void Persona::setApellido(string apellido){
    this->apellido = apellido;
}


string Persona::getApellido(){
    return apellido;
}


void Persona::setTelefono(int telefono){
    this->telefono = telefono;
}


int Persona::getTelefono(){
    return telefono;
}


