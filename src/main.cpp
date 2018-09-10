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

    // TODO Borrar antes de entregar
    // Se usa para correr experimentos
    std::cout <<n <<" " <<vDeseado << " ";


    //Contadores de recursion
    contador countFB = 0;
    contador countDin = 0;
    contador countBackFact = 0;
    contador countBackOpt = 0;

    int metodo = atoi(argv[1]);
    if (metodo == 1)
    {
        auto startFB = std::chrono::steady_clock::now();
        int resFB = solucionFB(vDeseado, entrada, countFB);
        auto endFB = std::chrono::steady_clock::now();
        auto diffFB = endFB - startFB;
        // TODO Borrar antes de entregar
        // Se usa para experimentacion
        std::cout << std::chrono::duration<double, std::milli>(diffFB).count() << " ";
        std::cout << countFB << std::endl;

        // TODO Descomentar para entregar
        // std::cout << resFB;
        return resFB;
    }

    else if (metodo == 2)
    {
        auto startDin = std::chrono::steady_clock::now();
        int resDin = solucionDinamica(vDeseado, entrada, countDin);
        auto endDin = std::chrono::steady_clock::now();
        auto diffDin = endDin - startDin;
        // TODO Borrar antes de entregar
        // Se usa para experimentacion
        std::cout << std::chrono::duration<double, std::milli>(diffDin).count() << " ";
        std::cout << countDin << std::endl;

        // TODO Descomentar para entregar
        // std::cout << resDin;
        return resDin;
    }

    else if (metodo == 3)
    {
        auto startBackFact = std::chrono::steady_clock::now();
        int resBackFact = solucionBackFact(vDeseado, entrada, countBackFact);
        auto endBackFact = std::chrono::steady_clock::now();
        auto diffBackFact = endBackFact - startBackFact;
        // TODO Borrar antes de entregar
        // Se usa para experimentacion
        std::cout << std::chrono::duration<double, std::milli>(diffBackFact).count() << " ";
        std::cout << countBackFact << std::endl;

        // TODO Descomentar para entregar
        // std::cout << resBackFact;
        return resBackFact;
    }
    else if (metodo == 4)
    {
        auto startBackOpt = std::chrono::steady_clock::now();
        int resBackOpt = solucionBackFact(vDeseado, entrada, countBackOpt);
        auto endBackOpt = std::chrono::steady_clock::now();
        auto diffBackOpt = endBackOpt - startBackOpt;
        // TODO Borrar antes de entregar
        // Se usa para experimentacion
        std::cout << std::chrono::duration<double, std::milli>(diffBackOpt).count() << " ";
        std::cout << countBackOpt << std::endl;

        // TODO Descomentar para entregar
        // std::cout << resBackOpt;
        return resBackOpt;
    }
}