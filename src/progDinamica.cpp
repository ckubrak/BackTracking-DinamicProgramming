// #include <algorithm>
// #include "progDinamica.h"


// int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados, contador& count)
// {
//     count++;
//     // if (vDeseado == 0)
//     //     return 0;
//     if (i == -1 )
//     {
//         return n + 1;
//     }
//     else
//     {
//         int resiV = resultados[i][vDeseado];
//         if (resultados[i][vDeseado] == -2)
//         {
//             int entradaI = entrada[i];
//             int parcial1 = resolverDinamica(vDeseado, entrada, i - 1, n, resultados, count);
//             int parcial2 = 1 + resolverDinamica(vDeseado - entrada[i], entrada, i - 1, n, resultados, count);

//             resultados[i][vDeseado] = std::min(parcial1, parcial2);
//         }
//         return resultados[i][vDeseado];
//     }
// }

// int solucionDinamica (int vDeseado, std::vector<int>& entrada, contador& count)
// {
//     int res;
//     int n = entrada.size();
//     int i = n-1;
//     std::vector<int> filaConBasura(vDeseado + 1,-2);
//     matriz resultados(n,filaConBasura);

//     for (int j = 0; j < resultados.size(); j++)
//     {
//         resultados[j][0] = 0;
//     }

//     res = resolverDinamica(vDeseado, entrada, i,n,resultados,count);
//     if (res > entrada.size())
//     {
//         return -1;
//     }
    
//     else
//     {
//         return res;
//     }
// }

// #include <algorithm>
// #include "progDinamica.h"


// int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados, contador& count)
// {
//     // std::cout << vDeseado << " ";
//     count++;
//     if (i == -1 )
//     {
//         // std::cout << "i = -1" << std::endl;
//         return n + 100;
//     }
//     if (vDeseado == 0)
//     {
//         // std::cout << "V == 0";
//         return 0;
//     }
//     if (vDeseado < entrada[i])
//         resultados[i][vDeseado] = resolverDinamica(vDeseado, entrada, i - 1, n, resultados, count);
//         // return n+1;
//     else
//     {
//         int resiV = resultados[i][vDeseado];
//         // std::cout << " resIV " << resiV << std::endl;
//         if (resultados[i][vDeseado] == -2)
//         {
//             int entradaI = entrada[i];
//             int parcial1 = resolverDinamica(vDeseado, entrada, i - 1, n, resultados, count);
//             std::cout << "Parcial 1 " << parcial1 << std::endl;
//             int parcial2 = 1 + resolverDinamica(vDeseado - entrada[i], entrada, i - 1, n, resultados, count);
//             std::cout << "Parcial 2 " << parcial2 << std::endl;
//             std::cout << "resultados 2 2 " << resultados[2][2] << std::endl;
//             std::cout << "parametros = " << (vDeseado - entrada[i]) << " " << (i-1) << std::endl;

//             resultados[i][vDeseado] = std::min(parcial1, parcial2);
//         }
//         return resultados[i][vDeseado];
//     }
// }

// int solucionDinamica (int vDeseado, std::vector<int>& entrada, contador& count)
// {
//     int res;
//     int n = entrada.size();
//     int i = n-1;
//     std::vector<int> filaConBasura(vDeseado + 1,-2);
//     matriz resultados(n,filaConBasura);

//     res = resolverDinamica(vDeseado, entrada, i,n,resultados,count);
//     if (res > entrada.size())
//     {
//         return -1;
//     }
    
//     else
//     {
//         return res;
//     }
// }
#include <algorithm>
#include "progDinamica.h"


int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados, contador& count)
{
    count++;
    if (vDeseado < 0)
        return n+1;
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
                int parcial1 = resolverDinamica(vDeseado, entrada, i - 1, n, resultados,count);
                int parcial2 = 1 + resolverDinamica(vDeseado - entrada[i], entrada, i - 1, n, resultados,count);

                resultados[i][vDeseado] = std::min(parcial1, parcial2);
        }
        return resultados[i][vDeseado];
    }
}

int solucionDinamica (int vDeseado, std::vector<int>& entrada, contador& count)
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
