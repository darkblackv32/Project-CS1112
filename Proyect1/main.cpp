
#include "CMago.h"


int main(){

    Mago* Gandalf = new Mago();

    (*Gandalf).setValues();
    Gandalf->evaEst();

    Abarrote* abarrote = new Abarrote(3);
    Lembas* lembas = new Lembas(2);
    Manzana* manzana = new Manzana(1);
    Melon* melon = new Melon(5);
    HoneyCake* honeycake = new HoneyCake(2);
    Hongos* hongos = new Hongos(5);
    Otros* otros = new Otros(2);

    Gandalf->comer(abarrote);
    Gandalf->comer(lembas);
    Gandalf->comer(manzana);
    Gandalf->comer(melon);
    Gandalf->comer(honeycake);
    Gandalf->comer(hongos);
    Gandalf->comer(otros);

    cout<<"Los puntos de Gandalf despues de comer son: "<<(*Gandalf).getpTotal()<<endl;
    Gandalf->evaEst();
    
    return 0;
}