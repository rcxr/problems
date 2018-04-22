¡Hoy es el gran día! Hoy se lleva a cabo el **1er Concurso de Programación del Instituto Tecnológico de Pachuca**; sin embargo de tan emocionadx que estás se te olvidó cómo llegar al Tec y vas a tener que pedir ayuda en la calle.

El mapa de tu casa al Tec es un rectángulo de $N$ casillas de alto por $M$ casillas de ancho. Tu casa está en la esquina superior izquierda y el Tec está en la esquina inferior derecha. Empiezas tu recorrido en tu casa (esquina superior izquierda) viendo hacia el Este.

Dado que no sabes cómo llegar en cada casilla (incluída la casilla inicial) pides ayuda a la persona en esa casilla. Esa persona te puede aconsejar:

- Sigue derecho
- Gira a la derecha
- Gira a la izquierda
- Date la vuelta

Después de recibir el consejo, lo sigues y **avanzas una casilla**. Al llegar a una nueva casilla vuelves a hacer el mismo proceso: preguntar, seguir consejo, avanzar una casilla. Así hasta que llegues al Tec (esquina inferior derecha) o te salgas del mapa (si te sales del mapa ya te **perdiste** y es un hecho que no llegarás al concurso).

Escribe un programa que dadas las respuestas de las personas en cada casilla del mapa determine si vas a llegar al Tec o te vas a perder.

# Input

 - Dos enteros indicando las dimensiones del mapa. El formato es `N M` donde:
   - $N$ alto del mapa
   - $M$ ancho del mapa
 - $N$ renglones conteniendo $M$ valores separados por espacios. Estos valores representan los consejos que vas a recibir en cada casilla. Los posibles valores son:
   - $0$ sigue derecho
   - $1$ gira a la derecha
   - $2$ gira a la izquierda
   - $3$ date la vuelta

# Output

 - Imprime `llegaste` si siguiendo las instrucciones llegas al Tec
 - Imprime `te perdiste` si te sales del mapa

# Ejemplos

||input
2 3
0 1 0
0 2 0
||output
llegaste
||description
 - Empiezas en tu casa viendo hacia el Este (renglón: 0, columna: 0).
 - Sigues derecho (renglón: 0, columna: 1).
 - Giras a la derecha (renglón: 1, columna: 1).
 - Giras a la izquierda (renglón: 1, columna: 2).
 - Estás en la esquina inferior derecha. ¡Llegaste!
||input
2 3
0 1 0
1 1 0
||output
te perdiste
||description
 - Empiezas en tu casa viendo hacia el Este (renglón: 0, columna: 0).
 - Sigues derecho (renglón: 0, columna: 1).
 - Giras a la derecha (renglón: 1, columna: 1).
 - Giras a la derecha (renglón: 1, columna: 0).
 - Giras a la derecha (renglón: 0, columna: 0).
 - Sigues derecho y te sales del mapa. ¡Te perdiste!
||input
1 2
3 0
||output
te perdiste
||description
 - Empiezas en tu casa viendo hacia el Este (renglón: 0, columna: 0).
 - Te das la vuelta y te sales del mapa. ¡Te perdiste!
||end
