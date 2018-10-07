#Funciona como jupyter notebook dentro de VSCode

#%%
import random
import os 
import glob
import subprocess
import numpy as np


#%%
# TEST RANDOM
for x in range(0,3):
    for vDeseado in [20,10000]:
    # for vDeseado in [x**2 for x in range(6,200,3)]:
        for n in range (1,1000,10):
            nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/randomVV" + str(vDeseado) + "n" + str(n) +".txt"
            f = open(nombreArchivo, "a+")
            f.write(str(n)+" "+str(vDeseado)+ "\n")

            for n in range (0,n):
                numero = random.randint(1,vDeseado - (vDeseado//10))
                f.write(str(numero)+ "\n")


            f.close() 
            # os.system("cat " + str(nombreArchivo) + " | ../build/tp 1 >> nGrande/FBRandom.csv")
            os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> nGrande/DinRandomFinal.csv")
            os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> nGrande/BackRandom.csv")

            os.remove(nombreArchivo)
    # os.system("echo >> nGrande/FBRandom.csv")
    os.system("echo >> nGrande/DinRandomFinal.csv")
    os.system("echo >> nGrande/BackRandom.csv")
    print("Termino " + str(x))

print("Terimno Random")
#%%
# TEST todos unos y no llega a vDeseado

for vDeseado in range(3,30):
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/unosNoLlega" + str(vDeseado) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(vDeseado-2)+" "+str(vDeseado)+ "\n")
        for n in range (0,vDeseado - 2):
            numero = 1
            f.write(str(numero)+ "\n")
        f.close() 
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 1 >> resultados/FBnoLlega.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> resultados/DinnoLlega.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> resultados/BacknoLlega.csv")

        os.remove(nombreArchivo)

print("No llega")
