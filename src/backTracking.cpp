#include "backTracking.h"

typedef std::vector<std::vector<int> > matriz; 

int resolverBackOpt (int vDeseado, std::vector<int>& entrada,int i, int n, contador& count, int& minParcial, int cardinalParcial)
{
    if (cardinalParcial > minParcial)
        return n+1;
    count++;
    if (vDeseado == 0)
    {
        minParcial = cardinalParcial;
        return 0;
    }
    if (i == -1) {
        return n+1;
    }
    int entradaI = entrada[i];
    if (entrada[i] > vDeseado)
    {
        return resolverBackOpt(vDeseado, entrada, i-1,n,count,minParcial,cardinalParcial);
    }
    if (entrada[i] <= vDeseado)
    {
        int parcial1 = resolverBackOpt(vDeseado, entrada, i-1,n,count,minParcial, cardinalParcial);
        int vRestado = vDeseado - entrada[i];
        int parcial2 = 1 + resolverBackOpt(vDeseado - entrada[i], entrada, i-1,n,count,minParcial, cardinalParcial + 1);

        return std::min(parcial1, parcial2);
    }
}
int solucionBackOpt (int vDeseado, std::vector<int>& entrada, contador& count)
{
    int n = entrada.size();
    int minParcial = n+1;
    int cardinalParcial = 0;

    int i = entrada.size() - 1;
    int res = resolverBackOpt(vDeseado,entrada,i,entrada.size(),count,minParcial, cardinalParcial);
    if (res > entrada.size())
    {
        return -1;
    }
    
    else
    {
        return res;
    }
}