#include "COtros.h"

Otros::~Otros(){}

Otros::Otros(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = -1;
        this->cantidad = cant;
    } 