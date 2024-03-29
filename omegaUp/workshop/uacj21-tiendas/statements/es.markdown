# Descripción

¡El centro comercial va a abrir sus puertas después de una larga cuarentena!

Si bien esta es una gran noticia para muchos que extrañan ir al cine con sus amigos, es muy importante que todos sigamos las nuevas normas de salud que dictan qué tantas personas pueden estar juntas en un mismo lugar.

Para saber si estas normas se siguen cada puerta en el centro comercial ha sido equipada con cámaras que reportan de forma muy precisa cuántas personas entran o salen de cada lugar. Estas cámaras generan una bitácora con entradas ordenadas de forma cronológica. Esta es una bitácora de ejemplo:

```
10 entrar centro-comercial
3 entrar deportes-martin
2 entrar otso-abarrotes
1 entrar la-autentica-michoacana
2 salir deportes-martin
1 salir otso-abarrotes
4 salir centro-comercial
```

Gracias a tus asombrosas habilidades de computación se te ha pedido que escribas un programa que liste las tiendas que no han seguido las normas de salud, o incluso si el mismo centro comercial ha dejado entrar a muchas personas al mismo tiempo. Para esto contarás con la siguiente información:

- La cantidad de personas permitidas en todo el centro comercial (incluyendo adentro de tiendas)
- La cantidad de personas permitidas en cada tienda
- La bitácora de entradas y salidas

# Entrada

- Un entero, $A$, indicando la cantidad de personas permitidas en todo el centro comercial (incluyendo adentro de tiendas)
- Un entero, $B$, indicando la cantidad de personas permitidas en cada tienda
- Un entero, $C$, indicando la cantidad de entradas en la bitácora
- $C$ renglones. Cada renglón representa una entrada en la bitácora con el formato `N ACCION LUGAR` donde:
  - $N$ es la cantidad de personas que entraron o salieron
  - $ACCION$ es ya sea `entrar` o `salir`
  - $LUGAR$ es el identificador del lugar al que se entra o sale. Sólo se usan letras minúsculas (`[a-z]`), números (`[0-9]`) y guiones (`-`). NO SE USAN ESPACIOS.

# Notas importantes

- $1 \le A, B, C, N \le 100$
- `centro-comercial` está reservado para referirse al centro comercial
- Al inicio de la bitácora no hay ninguna persona en el centro comercial ni en ninguna de sus tiendas
- No importa que al final de procesar la bitácora aún haya personas en las tiendas o en el centro comercial. Esto es válido y no genera un `ERROR`
- Para entrar a una tienda primero se tuvo que haber entrado al centro comercial
- Al entrar a una tienda se sigue considerando que estás en el centro comercial
- Al salir de una tienda se sigue considerando que estás en el centro comercial
- Para salir del centro comercial es necesario haber salido antes de cualquier tienda en la que te encuentres. Es decir, la siguiente bitácora es inválida y genera `ERROR` ya que la persona no puede salir del centro comercial sin antes haber salido de la tienda `la-gran-michoacana`:

```
1 entrar centro-comercial
1 entrar la-gran-michoacana
1 salir centro-comercial
```

# Salida

- Si la lista tiene algún error escribe `ERROR`
- Si todas las normas de salud se han cumplido tu programa deberá arrojar `OK`
- De otra forma escribe en orden alfabético los lugares que han roto las normas de salud separados por un espacio (` `)

# Ejemplos

||input
10
2
5
1 entrar deportes-martin
1 salir deportes-martin
1 entrar otso-abarrotes
1 salir otso-abarrotes
||output
ERROR
||description
Nadie había entrado al centro comercial cuando se registró la entrada a la tienda `deportes-martin`. Esto es inválido.
||input
10
10
3
1 entrar centro-comercial
1 entrar la-gran-michoacana
1 salir centro-comercial
||output
ERROR
||description
La única persona que entró al centro comercial estaba en `la-gran-michoacana` por lo que el registro de salida del `centro-comercial` es inválido.
||input
10
2
6
6 entrar centro-comercial
3 entrar la-mera-mera-michoacana
3 entrar ajedreces-pa-todos
5 entrar centro-comercial
2 entrar la-autentica-michoacana
3 entrar la-gran-michoacana
||output
ajedreces-pa-todos centro-comercial la-gran-michoacana la-mera-mera-michoacana
||description
El centro comercial y 3 tiendas rompieron las normas. La lista se muestra en orden alfabético.
||input
10
2
7
10 entrar centro-comercial
2 entrar deportes-martin
2 entrar otso-abarrotes
1 entrar la-autentica-michoacana
2 salir deportes-martin
1 salir otso-abarrotes
4 salir centro-comercial
||output
OK
||description
Las normas fueron respetadas esta vez. No importa que hayan quedado personas adentro de tiendas ni del centro comercial.
||end
