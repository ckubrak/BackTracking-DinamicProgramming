#ifndef _FUERZABRUTA_
#define _FUERZABRUTA_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

int resolverFuerzaBruta (int vDeseado, std::vector<int>& entrada,int i, int n);
int solucionFB (int vDeseado, std::vector<int>& entrada);
void partesVector (std::vector<int>& entrada, std::vector<std::vector<int> > &partes);

#endif