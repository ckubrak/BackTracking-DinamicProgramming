#include "backTracking.h"

typedef std::vector<std::vector<int> > matriz;

int resolverBackFact (int vDeseado, std::vector<int>& entrada,int i, int n, int& count)
{
    count++;
    int entradaI = entrada[i];
    if (i == -1) {
        return n+1;
    }
    if (vDeseado == 0)
    {
        return 0;
    }
    if (entrada[i] > vDeseado)
    {
        return resolverBackFact(vDeseado, entrada, i-1,n,count);
    }
    if (entrada[i] <= vDeseado)
    {
        int parcial1 = resolverBackFact(vDeseado, entrada, i-1,n,count);
        int parcial2 = 1 + resolverBackFact(vDeseado - entrada[i], entrada, i-1,n,count);

        return std::min(parcial1, parcial2);
    }
}
int solucionBackFact (int vDeseado, std::vector<int>& entrada, int& count)
{
    int n = entrada.size();
    std::vector<int> filaConCeros(n,0);
    matriz resultados(vDeseado,filaConCeros);

    for(int i = 0; i < vDeseado; i++)
    {
        resultados[0][i] = n+1;
    }
}