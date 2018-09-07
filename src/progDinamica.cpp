#include <algorithm>
#include "progDinamica.h"


typedef std::vector<std::vector<int> > matriz;
int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados)
{
    if (i == -1 && vDeseado != 0)
    {
        return n + 1;
    }
    else if (i == -1 && vDeseado == 0)
        return 0;
    else
    {
        int resiV = resultados[i][vDeseado];
        if (resultados[i][vDeseado] == -2)
        {
            int entradaI = entrada[i];
            if (entrada[i] > vDeseado)
            {
                resultados[i][vDeseado] = resolverDinamica(vDeseado, entrada, i - 1, n, resultados);
            }
            if (entrada[i] <= vDeseado)
            {
                int parcial1 = resolverDinamica(vDeseado, entrada, i - 1, n, resultados);
                int parcial2 = 1 + resolverDinamica(vDeseado - entrada[i], entrada, i - 1, n, resultados);

                resultados[i][vDeseado] = std::min(parcial1, parcial2);
            }
        }
        return resultados[i][vDeseado];
    }
}

int solucionDinamica (int vDeseado, std::vector<int>& entrada)
{
    int res;
    int n = entrada.size();
    int i = n-1;
    std::vector<int> filaConBasura(vDeseado + 1,-2);
    matriz resultados(n,filaConBasura);

    // for(int j = 0; j < vDeseado + 1; j++)
    // {
    //     resultados[0][j] = n+1;
    // }

    res = resolverDinamica(vDeseado, entrada, i-1,n,resultados);
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
}