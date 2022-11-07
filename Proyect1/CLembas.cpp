#include "CLembas.h"

Lembas::~Lembas(){}

Lembas::Lembas(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = 3;
        this->cantidad = cant;
    } 