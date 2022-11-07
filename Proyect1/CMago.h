
#include "CAbarrote.h"
#include "CLembas.h"
#include "CManzana.h"
#include "CMelon.h"
#include "CHoneyCake.h"
#include "CHongos.h"
#include "COtros.h"

using namespace std;


class Mago
{
private:
    int totest;
    string est_an;
    string name;
public:
    Mago();
    ~Mago();
    void setValues();
        
    void evaEst();

    void comer(Alimento* obj);
    int getpTotal();
    string getEst();
};









