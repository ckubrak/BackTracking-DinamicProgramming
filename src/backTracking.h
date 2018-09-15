#ifndef _BACKTRACKING_
#define _BACKTRACKING_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

typedef unsigned long long contador;

int resolverBackOpt (int vDeseado, std::vector<int>& entrada,int i, int n, contador& count, int& minParcial, int cardinalParcial);
int solucionBackOpt (int vDeseado, std::vector<int>& entrada, contador& count);

#endif