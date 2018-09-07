#include "fuerzaBruta.h"
#include <algorithm>
#include <stdlib.h>  
int solucionFB (int vDeseado, std::vector<int>& entrada, int& count)
{
    int i = entrada.size() - 1;
    int res = resolverFuerzaBruta(vDeseado,entrada,i,entrada.size(),count);
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
    
}
int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada, int i, int n, int& count)
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
        return resolverFuerzaBruta(vDeseado, entrada, i-1,n,count);
    }
    if (entrada[i] <= vDeseado)
    {
        int parcial1 = resolverFuerzaBruta(vDeseado, entrada, i-1,n,count);
        int parcial2 = 1 + resolverFuerzaBruta(vDeseado - entrada[i], entrada, i-1,n,count);

        return std::min(parcial1, parcial2);
    }
}