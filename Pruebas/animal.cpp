#include "animal.hpp"

animal::animal(){
}

void animal::setFamilia(string familia){
    this->familia = familia;
}


string animal::getFamilia(){
    return familia;
}


void animal::setGenero(string genero){
    this->genero = genero;
}


string animal::getGenero(){
    return genero;
}


void animal::setEdad(int edad){
    this->edad = edad;
}


int animal::getEdad(){
    return edad;
}


