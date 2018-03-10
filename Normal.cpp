#include "Normal.h"
#include <iostream>
#include <string>
//#include "Bombas.h"
using namespace std;

Normal::Normal()
{
}

Normal::Normal(int alcance, int contador) : Bombas(contador)
{
    this->alcance = alcance;
}

int Normal::getAlcance()
{
    return alcance;
}

void Normal::setAlcance(int alcance)
{
    this->alcance = alcance;
}

Normal::~Normal()
{
}

/*string Normal::toString(){
    return simbolo;
}*/
