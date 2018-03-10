#include "Tren.h"
#include <iostream>
#include <string>
#include "Escenario.h"
using namespace std;

Tren::Tren(string nombre, int tipobomba) : Escenario(nombre, tipobomba)
{
    
}

Tren::~Tren()
{
    cout<<"tren destruido";
}