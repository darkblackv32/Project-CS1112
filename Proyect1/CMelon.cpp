#include "CMelon.h"

Melon::~Melon(){}

Melon::Melon(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = 1;
        this->cantidad = cant;
    } 