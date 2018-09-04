#include "fuerzaBruta.h"
#include <algorithm>
#include <stdlib.h>  
int solucionFB (int vDeseado, std::vector<int>& entrada)
{
    int i = entrada.size() - 1;
    int res = resolverFuerzaBruta(vDeseado,entrada,i,entrada.size());
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
    
}
int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada, int i, int n)
{
    int entradaI = entrada[i];
    std::cout << entradaI << " " << vDeseado << " " << i<<std::endl;
    if (i == -1) {
        return n+1;
    }
    if (vDeseado == 0)
    {
        std::cout << "v = 0 con " << i<<std::endl;
        return 0;
    }
    if (entrada[i] > vDeseado)
    {
        return resolverFuerzaBruta(vDeseado, entrada, i-1,n+1);
    }
    if (entrada[i] <= vDeseado)
    {
        int parcial1 = resolverFuerzaBruta(vDeseado, entrada, i-1,n+1);
        int parcial2 = 1 + resolverFuerzaBruta(vDeseado - entrada[i], entrada, i-1,n+1);

    
        return std::min(parcial1, parcial2);
    }
}