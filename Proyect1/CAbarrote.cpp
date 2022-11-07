#include "CAbarrote.h"

Abarrote::~Abarrote(){}

Abarrote::Abarrote(int cant) : Alimento(puntos, cant)
    {   
        this->puntos = 2;
        this->cantidad = cant;
    } 