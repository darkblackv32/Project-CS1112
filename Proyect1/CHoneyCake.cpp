#include "CHoneyCake.h"

HoneyCake::~HoneyCake(){}

HoneyCake::HoneyCake(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = 5;
        this->cantidad = cant;
    } 