#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "fuerzaBruta.h"
#include "progDinamica.h"
#include "backTracking.h"


int main(int argc, char* argv[]) 
{
    // Lee input
    int tamano,vDeseado, item;
    std::cin  >> tamano >> vDeseado;
    std::vector <int> entrada;
    for (int i = 0; i < tamano; i++)
    {
        std::cin >> item;
        entrada.push_back(item);
    }

    int i = entrada.size() - 1;
    int n = entrada.size();


    //Contadores de recursion
    contador countFB = 0;
    contador countDin = 0;
    contador countBackFact = 0;
    contador countBackOpt = 0;

    int metodo = atoi(argv[1]);
    if (metodo == 1)
    {
        int resFB = solucionFB(vDeseado, entrada, countFB);
        std::cout << resFB;
        return resFB;
    }

    else if (metodo == 2)
    {
        int resDin = solucionDinamica(vDeseado, entrada, countDin);
        std::cout << resDin;
        return resDin;
    }
    else if (metodo == 3)
    {
        int resBackOpt = solucionBackOpt (vDeseado, entrada, countBackOpt);
        std::cout << resBackOpt;
        return resBackOpt;
    }
}
