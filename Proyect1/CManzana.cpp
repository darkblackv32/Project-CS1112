#include "CManzana.h"

Manzana::~Manzana(){}

Manzana::Manzana(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = 1;
        this->cantidad = cant;
    } 