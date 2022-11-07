#include "CMago.h"

Mago::~Mago(){}

Mago::Mago(){};

void Mago::setValues(){
        int x;
        cout<<"Ingresa la cantidad de puntos de Gandalf: ";
        cin>>x;
        this->totest = x;}

void Mago::evaEst(){
        int x = totest;
        if(x > 15){
            this->est_an = "ReFeliz";
        }
        else if(x >= 1 and x <= 15){
            this->est_an = "Feliz";
        }
        else if(x >= -5 and x <= 0){
            this->est_an = "Triste";
        }
        else if(x < -5){
            this->est_an = "Enojado";
        }
        cout<<"Su estado de animo actual es: "<<est_an<<endl;
    }

void Mago::comer(Alimento* obj){
        int y = obj->getCantidad();
        int x = obj->getPuntos()*y;
        totest = totest + x;
    }

int Mago::getpTotal(){return totest;}

string Mago::getEst(){return est_an;}