¡Llegó la hora de la comida en el **1er Concurso de Programación del Instituto Tecnológico de Pachuca**!

Para la comida los organizadores pidieron una caja llena de pastes de los siguientes sabores:

 - Papa con carne
 - Mole verde
 - Hawaiano
 - Zarzamora

Los organizadores habían ya preguntado a cada concursante cuántos pastes iban a querer de cada sabor; pero cuando fueron a comprarlos olvidaron la lista y para no regresar con las manos vacías compraron lo que se les ocurrió en el momento.

Tu tarea es decir si los organizadores compraron suficientes pastes para satisfacer lo que los concursantes pidieron originalmente.

# Input

 - Cuatro enteros indicando la cantidad de pastes de cada sabor que se compraron. El formato es `P M H Z` donde:
   - $P$ cantidad de pastes de papa con carne
   - $M$ cantidad de pastes de mole verde
   - $H$ cantidad de pastes hawaianos
   - $Z$ cantidad de pastes de zarzamora
 - Un entero, $N$, indicando el número de concursantes
 - $N$ renglones. Cada renglón seguirá el formato `p m h z` donde:
   - $p$ pastes de papa con carne que originalmente pidió el concursante
   - $m$ pastes de mole verde que originalmente pidió el concursante
   - $h$ pastes hawaianos que originalmente pidió el concursante
   - $z$ pastes de zarzamora que originalmente pidió el concursante

## Notas

 - $1 \le N \le 100$
 - $0 \le P, M, H, Z, p, m, h, z \le 100$

# Output

 - Imprime `#epicfail` si los organizadores no compraron suficientes pastes para satisfacer lo que los concursantes pidieron originalmente
 - Imprime `#win` si todos van a poder comer lo que pidieron originalmente (**no importa que sobren pastes**)

# Ejemplos

||input
3 3 3 3
2
0 2 1 0
0 1 0 2
||output
#win
||description
Se pidieron suficientes pastes de cada sabor para satisfacer a los concursantes
||input
3 3 3 3
2
0 0 2 1
1 0 2 0
||output
#epicfail
||description
Los organizadores no pidieron suficientes pastes hawaianos... #epicfail
||end
