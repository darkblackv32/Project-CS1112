#include <bits/stdc++.h>
#pragma once

class Alimento
{
protected:
    int puntos;
    int cantidad;
public:
    Alimento();
    Alimento(int pun ,int can);
    virtual ~Alimento();

    int getPuntos();
    virtual int getCantidad();
};