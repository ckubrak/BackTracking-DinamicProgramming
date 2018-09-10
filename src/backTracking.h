#ifndef _BACKTRACKING_
#define _BACKTRACKING_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

int resolverBackFact (int vDeseado, std::vector<int>& entrada,int i, int n, int& count);
int solucionBackFact (int vDeseado, std::vector<int>& entrada, int& count);

int resolverBackOpt (int vDeseado, std::vector<int>& entrada,int i, int n, int& count, int& minParcial, int cardinalParcial);
int solucionBackOpt (int vDeseado, std::vector<int>& entrada,int count);

#endif