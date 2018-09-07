#ifndef _PROGDINAMICA_
#define _PROGDINAMICA_

#include <vector>
#include <iostream>
#include <math.h>       /* pow */
#include <stdio.h>

typedef std::vector<std::vector<int> > matriz;

int resolverDinamica(int vDeseado, std::vector<int> &entrada, int i, int n, matriz &resultados, int& count);
int solucionDinamica (int vDeseado, std::vector<int>& entrada, int& count);

#endif