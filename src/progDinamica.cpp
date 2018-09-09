#include <algorithm>
#include "progDinamica.h"


int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados, int& count)
{
    count++;
    if (vDeseado == 0)
        return 0;
    if (i == -1 )
    {
        return n + 1;
    }
    else
    {
        int resiV = resultados[i][vDeseado];
        if (resultados[i][vDeseado] == -2)
        {
            int entradaI = entrada[i];
            if (entrada[i] > vDeseado)
            {
                resultados[i][vDeseado] = resolverDinamica(vDeseado, entrada, i - 1, n, resultados,count);
            }
            if (entrada[i] <= vDeseado)
            {
                int parcial1 = resolverDinamica(vDeseado, entrada, i - 1, n, resultados,count);
                int parcial2 = 1 + resolverDinamica(vDeseado - entrada[i], entrada, i - 1, n, resultados,count);

                resultados[i][vDeseado] = std::min(parcial1, parcial2);
            }
        }
        return resultados[i][vDeseado];
    }
}

int solucionDinamica (int vDeseado, std::vector<int>& entrada, int& count)
{
    int res;
    int n = entrada.size();
    int i = n-1;
    std::vector<int> filaConBasura(vDeseado + 1,-2);
    matriz resultados(n,filaConBasura);

    res = resolverDinamica(vDeseado, entrada, i,n,resultados,count);
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
}