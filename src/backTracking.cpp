#include "backTracking.h"

typedef std::vector<std::vector<int> > matriz;

int resolverBackFact (int vDeseado, std::vector<int>& entrada,int i, int n, int& count)
{
    count++;
    if (vDeseado == 0)
    {
        return 0;
    }
    if (i == -1) {
        return n+1;
    }
    int entradaI = entrada[i];
    if (entrada[i] > vDeseado)
    {
        return resolverBackFact(vDeseado, entrada, i-1,n,count);
    }
    if (entrada[i] <= vDeseado)
    {
        int parcial1 = resolverBackFact(vDeseado, entrada, i-1,n,count);
        int vRestado = vDeseado - entrada[i];
        int parcial2 = 1 + resolverBackFact(vDeseado - entrada[i], entrada, i-1,n,count);

        return std::min(parcial1, parcial2);
    }
}
int solucionBackFact (int vDeseado, std::vector<int>& entrada, int& count)
{
    int n = entrada.size();


    int i = entrada.size() - 1;
    int res = resolverBackFact(vDeseado,entrada,i,entrada.size(),count);
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
}