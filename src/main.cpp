#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>
#include <chrono>
#include <ctime>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include "fuerzaBruta.h"
#include "progDinamica.h"

void printVector(std::vector<std::vector<int> > partes);

int main()
{
    std::vector <int> entrada;

    std::srand((unsigned)time(NULL));
   
    for(size_t i = 0; i < 100; i++)
    {
        entrada.push_back(1 + std::rand() % 1000);
    }
    
    // entrada = {10,15,5,10,5};
    int vDeseado = 1430;

    int i = entrada.size() - 1;

    //Contadores de recursion
    int countFB = 0;
    int countDin = 0;


    auto startFB = std::chrono::steady_clock::now();
    int resFB = solucionFB(vDeseado, entrada,countFB);
    auto endFB = std::chrono::steady_clock::now();
    auto diffFB = endFB - startFB;
    std::cout << "Tiempo utilizado por FB " <<std::chrono::duration <double, std::milli> (diffFB).count() << " ms" << std::endl;
    std:: cout << "Esperado fuerza Bruta " << std::pow(2,(entrada.size())) << " obtenido " << countFB << std::endl;

    auto startDin = std::chrono::steady_clock::now();
    int resDin = solucionDinamica(vDeseado, entrada, countDin);
    auto endDin = std::chrono::steady_clock::now();
    auto diffDin = endDin - startDin;
    std::cout << "Tiempo utilizado por Din " <<std::chrono::duration <double, std::milli> (diffDin).count() << " ms" << std::endl;
    std:: cout << "Esperado por Din " << (entrada.size())*vDeseado << " obtenido " << countDin<< std::endl;

    std::cout << countFB << " " <<countDin;
    return resFB;

}


void printVector(std::vector<std::vector<int> > partes)
{
    for (int i = 0; i < partes.size(); i++)
    {
        for (int j = 0; j < partes[i].size();j++)
        {
            std::cout << partes[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
