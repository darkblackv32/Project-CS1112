#include "CHongos.h"

Hongos::~Hongos(){}

Hongos::Hongos(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = -10;
        this->cantidad = cant;
    } 