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
    // std::cout << argc;
    int tamano,vDeseado, item;
    std::cin  >> tamano >> vDeseado;
    std::vector <int> entrada;
    for (int i = 0; i < tamano; i++)
    {
        std::cin >> item;
        entrada.push_back(item);
    }



    
    // int vDeseado = 1 + std::rand() % 30;

    int i = entrada.size() - 1;
    int n = entrada.size();

    std::cout <<n <<" " <<vDeseado << " ";


    //Contadores de recursion
    int countFB = 0;
    int countDin = 0;
    int countBackFact = 0;
    int countBackOpt = 0;

    int metodo = atoi(argv[1]);
    if (metodo == 1)
    {
    auto startFB = std::chrono::steady_clock::now();
    int resFB = solucionFB(vDeseado, entrada,countFB);
    auto endFB = std::chrono::steady_clock::now();
    auto diffFB = endFB - startFB;
    std::cout << std::chrono::duration <double, std::milli> (diffFB).count() << " ";
    std::cout << countFB << std::endl;


        return resFB;
    }

    else if (metodo == 2)
    {
    auto startDin = std::chrono::steady_clock::now();
    int resDin = solucionDinamica(vDeseado, entrada, countDin);
    auto endDin = std::chrono::steady_clock::now();
    auto diffDin = endDin - startDin;
    std::cout <<std::chrono::duration <double, std::milli> (diffDin).count() << " ";
    std:: cout << countDin<< std::endl;


        return resDin;
    }

    else if (metodo == 3)
    {
    auto startBackFact = std::chrono::steady_clock::now();
    int resBackFact = solucionBackFact(vDeseado,entrada,countBackFact);
    auto endBackFact = std::chrono::steady_clock::now();
    auto diffBackFact = endBackFact - startBackFact;
    std::cout << std::chrono::duration <double, std::milli> (diffBackFact).count() << " ";
    std:: cout << countBackFact<< std::endl;

        return resBackFact;
    }



}