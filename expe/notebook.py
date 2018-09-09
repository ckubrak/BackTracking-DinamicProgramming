#%%
import random
import os
import glob
import subprocess


#%%
for vDeseado in range(30,51,20):
    for n in range (13,15):
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/randomV" + str(vDeseado) + "n" + str(n) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(n)+" "+str(vDeseado)+ "\n")
        for n in range (0,n):
            numero = random.randint(1,vDeseado + (vDeseado//10))
            f.write(str(numero)+ "\n")
        f.close() 


#%%
os.chdir("/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/")
for file in glob.glob("*.txt"):
    os.system("cat " + str(file) + " | ../build/tp 1 >> resultados/FBRandom.csv")
    os.system("cat " + str(file) + " | ../build/tp 2 >> resultados/DinRandom.csv")
    os.system("cat " + str(file) + " | ../build/tp 3 >> resultados/BackFactRandom.csv")