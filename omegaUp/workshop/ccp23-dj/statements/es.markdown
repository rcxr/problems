# Descripción

Tu eres un DJ que trabaja con artistas en persona y vas a participar en un programa de premios en vivo. La directora del evento te pidió la lista de artistas en orden alfabético. Ordena los artistas en orden alfabético e imprímelos para la directora.

# Entrada

- Un entero $N$, indicando el número de líneas
  - $1 \le N \le 100$
- $N$ líneas. Cada línea tendrá el nombre de un artista
  - El nombre del artista puede contener espacios enmedio. Ejemplo `Bad Bunny`
  - El nombre no será mayor a 100 caracteres
  - Las minúsculas y mayúsculas tienen el mismo valor en orden alfabético
  - Sólo se usan letras sin acentos y espacios (`A-Z`, `a-z`, y el espacio)
  - No hay nombres repetidos

# Salida

- Imprime los nombres de los $N$ artistas en orden alfabético. Cada artista deberá estar en una línea diferente.

# Ejemplos

||input
13
Ricardo Arjona
Jenni Rivera
Shakira
Selena
Chayanne
Don Omar
Bad Bunny
Daddy Yankee
Gaby Moreno
J Balvin
Annuel
Ozuna
Karol G
||output
Annuel
Bad Bunny
Chayanne
Daddy Yankee
Don Omar
Gaby Moreno
J Balvin
Jenni Rivera
Karol G
Ozuna
Ricardo Arjona
Selena
Shakira
||description
`Annuel` es el artista con el nombre que comienza con `A`, entonces va al inicio. `Shakira` es la artista que iría al final.
||input
5
Ricardo Arjona
Ric Mendez
Ric Zarate
Ric
Ricardo
||output
Ric
Ric Mendez
Ric Zarate
Ricardo
Ricardo Arjona
||description
`Ric` le gana a `Ricardo` porque es más corto, y por lo mismo `Ricardo` le gana a `Ricardo Arjona`
||input
3
Ac
ab
Aa
||output
Aa
ab
Ac
||description
`A` y `a` tienen el mismo valor cuando se comparan alfabéticamente
||end
