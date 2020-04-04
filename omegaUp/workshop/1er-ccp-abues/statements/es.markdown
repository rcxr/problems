Durante la última fiesta familiar te llamó mucho la atención ver que tus abues también son abues de más niñas y niños. Esto te dio tanta curiosidad que empezaste a ver qué tantos nietos tuvieron los abuelos de tus papás y los abuelos de tus abuelos. Así se te ocurrió una genial pregunta qué contestar: "¿Quién ha dejado el legado de nietos más grande en la historia de la familia?"

Después de escuchar tantas historias que te contaron tus papás, tíos, abuelos y viejos amigos de la familia por fin conseguiste la información necesaria para resolver esta pregunta.

Sólo queda la parte más divertida de este gran enigma: escribe un programa que procese toda la información y determine quién ha tenido más nietos en la historia de la familia.

# Input

 - Un entero, $N$, indicando el número de renglones
 - $N$ renglones. Cada renglón representa una relación de un hijo o hija con un padre o madre, y seguirá el formato `A B` donde:
   - $A$ es el nombre del hijo o hija (una sola palabra)
   - $B$ es el nombre del padre o madre (una sola palabra)

## Notas

 - $1 \le N \le 1000$
 - No hay familiares con nombres repetidos
 - Se garantiza que todos los familiares están conectados de alguna forma

# Output

El nombre del familiar con más nietos en la familia.
En dado caso de empate listar los familiares en orden alfabético separados por un espacio.

# Ejemplos

||input
5
YoMerengues MamaLinda
MamaLinda AbuelaLina
MamaLinda AbueloTito
TiaTere AbueloTito
PrimaVera TiaTere
||output
AbueloTito
||description
En tanto a nietos AbueloTito tiene 2 (PrimaVera y YoMerengues), AbuelaLina tiene 1 (YoMerengues), y todos los demás tenemos 0. Así AbueloTito es quién ha tenido más nietos en la historia de la familia.
||input
6
YoMerengues MamaLinda
MamaLinda AbuelaLina
MamaLinda AbueloTito
TiaTere AbueloTito
PrimaVera TiaTere
AbueloTito BisabuelaTita
||output
AbueloTito
||description
La respuesta es la misma que en el caso pasado porque a pesar de que BisabuelaTita tiene más descendencia, sólo tiene una nieta (MamaLinda)
||end
