#ifndef _FUERZABRUTA_
#define _FUERZABRUTA_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada,int i, int n,int& count);
int solucionFB (int vDeseado, std::vector<int>& entrada,int& count);

#endif