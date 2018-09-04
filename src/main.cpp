#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

#include "fuerzaBruta.h"
#include "progDinamica.h"

void printVector(std::vector<std::vector<int> > partes);

int main()
{
    std::vector <int> entrada;
    entrada = {10,15,5,10,5};
    int vDeseado = 25;

    int i = entrada.size() - 1;
    int res = solucionFB(vDeseado, entrada);

    std::cout << res;
    return res;

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
