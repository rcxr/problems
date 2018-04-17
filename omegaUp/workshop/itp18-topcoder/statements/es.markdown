Has entrenado tanto para el **1er Concurso de Programación del Instituto Tecnológico de Pachuca** que al ver cualquier problema nuevo puedes estimar exáctamente los minutos que te tomará resolverlo.

El concurso empieza y:

 - Lees los problemas
 - Estimas el tiempo que te tomará resolver cada problema
 - Ves cuantos puntos vale cada problema

Con esta información y sabiendo que quedan **3 horas** de concurso escribe un programa que te diga la máxima cantidad de puntos que puedes obtener.

# Input

 - Un entero, $N$ ($1 \le N \le 100$), indicando la cantidad de problemas
 - $N$ renglones con datos sobre los problemas del concurso. Cada renglón seguirá el formato `M P` donde:
   - $M$ cantidad de minutos que te tomará resolver el problema
   - $P$ cantidad de puntos que obtienes por resolver el problema
 - $1 \le M, P \le 1000$

# Output

Imprime la máxima cantidad de puntos que puedes obtener si utilizas las 3 horas de forma óptima.

# Ejemplos

||input
4
180 250
60 100
60 100
60 100
||output
300
||description
Te conviene resolver los tres problemas de una hora a pesar de que den individualmente menos puntos (100 puntos cada uno) que resolver el problema que te toma 180 minutos que vale más (250 puntos)
||input
3
181 1000
182 1000
183 1000
||output
0
||description
No tienes tiempo suficiente para resolver ningún problema, tu puntaje quedará en 0
||end
