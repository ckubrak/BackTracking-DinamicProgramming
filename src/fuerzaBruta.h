#ifndef _FUERZABRUTA_
#define _FUERZABRUTA_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

typedef unsigned long long contador;

int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada,int i, int n,contador& count);
int solucionFB (int vDeseado, std::vector<int>& entrada,contador& count);

#endif