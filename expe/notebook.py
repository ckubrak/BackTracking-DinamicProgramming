
#%%
import random
import os
import glob
import subprocess


#%%
# TEST RANDOM
for vDeseado in [x**2 for x in range(1,100)]:
    for n in range (1,25):
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/randomV" + str(vDeseado) + "n" + str(n) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(n)+" "+str(vDeseado)+ "\n")
        for n in range (0,n):
            numero = random.randint(1,vDeseado + (vDeseado//10))
            f.write(str(numero)+ "\n")
        f.close() 
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 1 >> resultados/FBRandom.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> resultados/DinRandom.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> resultados/BackFactRandom.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 4 >> resultados/BackOptRandom.csv")

        os.remove(nombreArchivo)


#%%
# TEST todos unos con vDeseado = n
for n in range(1,25):
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/unos_n" + str(n) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(n)+" "+str(n)+ "\n")
        for i in range (0,n):
            numero = 1
            f.write(str(numero)+ "\n")
        f.close() 
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 1 >> resultados/FBunos.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> resultados/Dinunos.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> resultados/BackFactunos.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 4 >> resultados/BackOptunos.csv")

        os.remove(nombreArchivo)

#%%
# TEST todos unos y no llega a vDeseado

for vDeseado in [x**2 for x in range(1,100)]:
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/unosNoLlega" + str(vDeseado) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(n)+" "+str(vDeseado)+ "\n")
        for n in range (0,25):
            numero = 1
            f.write(str(numero)+ "\n")
        f.close() 
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 1 >> resultados/FBnoLlega.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> resultados/DinnoLlega.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> resultados/BackFactnoLlega.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 4 >> resultados/BackOptnoLlega.csv")

        os.remove(nombreArchivo)


#%%
# TEST RANDOM EXIGENTE
for vDeseado in [x**2 for x in range(1,100)]:
    for n in range (1,150,3):
        nombreArchivo = "/home/cristian/Facu/AlgoritmosIII/Tps/TP1/expe/randomV" + str(vDeseado) + "n" + str(n) +".txt"
        f = open(nombreArchivo, "a+")
        f.write(str(n)+" "+str(vDeseado)+ "\n")
        for n in range (0,n):
            numero = random.randint(1,vDeseado + (vDeseado//10))
            f.write(str(numero)+ "\n")
        f.close() 
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 2 >> resultados/DinExigenteRandom.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 3 >> resultados/BackExigenteFactRandom.csv")
        os.system("cat " + str(nombreArchivo) + " | ../build/tp 4 >> resultados/BackOptExigenteRandom.csv")

        os.remove(nombreArchivo)