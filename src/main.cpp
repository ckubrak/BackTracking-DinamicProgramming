#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>


int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada);
void partesVector (std::vector<int>& entrada, std::vector<std::vector<int> > &partes);
void printVector(std::vector<std::vector<int> > partes);

int main()
{
    std::vector <int> entrada;

    for (int x = 0; x < 25; x++)
    {
        entrada.push_back(x);
    }
    // entrada = {10,15,5,10,5};
    int vDeseado = 28;

    int res = resolverFuerzaBruta(vDeseado,entrada);

    return res;

}

int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada)
{
    // IDEA:
    // 1) Partes de entrada => 2^n
    // 2) Sumar cada subconjunto de P(entrada) -> n (Se hace 2^n veces) => 2^n * n
    // 3) Ir guardando el menor cardinal que da vDeseado

    int resParcial,cardinalResultado,cardinalParcial;
    size_t cardinalEntrada,cardinalPartes;
    std::vector<int> vectorVacio = {};

    cardinalEntrada = entrada.size();
    cardinalPartes = pow(2, entrada.size());


    std::vector<std::vector<int> > partes(cardinalPartes,vectorVacio);

    partesVector(entrada,partes);
    
    cardinalResultado = -1;
    for (int i = 0; i < cardinalPartes; i++)
    {
        resParcial = 0;
        cardinalParcial = 0;
        for (int j = 0; j < partes[i].size(); j++)
        {
            resParcial += partes[i][j];
            cardinalParcial += 1;
        }
        if (resParcial == vDeseado && (cardinalResultado == -1 || cardinalParcial < cardinalResultado))
            cardinalResultado = cardinalParcial;
    }

    // printVector(partes);
    std::cout << cardinalResultado;
    return cardinalResultado;
}

void partesVector (std::vector<int>& entrada, std::vector<std::vector<int> > &partes)
{

    size_t cardinalEntrada = entrada.size();
    size_t cardinalPartes = pow(2, entrada.size());

    for(int counter = 0; counter < cardinalPartes; counter++) {
        for(int j = 0; j < cardinalEntrada; j++) {
            // Check if jth bit in the counter is set, if so print the corresponding char
            if(counter & (1<<j))
            {
                partes[counter].push_back(entrada[j]);
            }
        }
    }
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
