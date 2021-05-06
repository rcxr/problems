# Descripción

¡El centro comercial va a abrir sus puertas después de una larga cuarentena!

Si bien esta es una gran noticia para muchos que extrañan ir al cine con sus amigos, es muy importante que todos sigamos las nuevas normas de salud que dictan qué tantas personas pueden estar juntas en un mismo lugar.

Para saber si estas normas se siguen cada puerta en el centro comercial ha sido equipada con cámaras que reportan de forma muy precisa cuántas personas entran o salen de cada lugar. Estas cámaras generan una bitácora con entradas ordenadas de forma cronológica. Esta es una bitácora de ejemplo:

```
10 entrar CENTRO-COMERCIAL
3 entrar Deportes-Martin
2 entrar Otso-Abarrotes
1 entrar La-Autentica-Michoacana
2 salir Deportes-Martin
1 salir Otso-Abarrotes
4 salir CENTRO-COMERCIAL
```

Gracias a tus asombrosas habilidades de computación se te ha pedido que escribas un programa que liste las tiendas que no han seguido las normas de salud, o incluso si el mismo centro comercial ha dejado entrar a muchas personas al mismo tiempo. Para esto contarás con la siguiente información:

- La cantidad de personas permitidas en el centro comercial
- La cantidad de personas permitidas en cada tienda
- La bitácora de entradas y salidas

# Entrada

- Un entero, $A$, indicando la cantidad de personas permitidas en el centro comercial
- Un entero, $B$, indicando la cantidad de personas permitidas en cada tienda
- Un entero, $C$, indicando la cantidad de entradas en la bitácora
- $C$ renglones. Cada renglón representa una entrada en la bitácora con el formato `N ACCION LUGAR` donde:
  - $N$ es la cantidad de personas que entraron o salieron
  - $ACCION$ es ya sea `entrar` o `salir`
  - $LUGAR$ es el identificador del lugar al que se entra o sale. Sólo se usan letras, números y guiones (`-`). NO SE USAN ESPACIOS.

## Notas

- $1 \le A, B, C \le 100$
- $1 \le C \le 1000$
- El lugar `CENTRO-COMERCIAL` está reservado para referirse al centro comercial
- Para salir del centro comercial es necesario haber salido antes de cualquier tienda en la que te encuentres. Es decir, la siguiente bitácora es inválida:

```
1 entrar CENTRO-COMERCIAL
1 entrar La-Gran-Michoacana
1 salir CENTRO-COMERCIAL
```

# Salida

Tu programa deberá generar las siguientes salidas:
- Si la lista tiene algún error escribe `ERROR`
- Si todas las normas de salud se han cumplido tu programa deberá arrojar `OK`
- De otra forma escribe en orden alfabético los lugares que han roto las normas de salud separados por un espacio (` `)

# Ejemplos

||input
```
10
10
3
1 entrar CENTRO-COMERCIAL
1 entrar La-Gran-Michoacana
1 salir CENTRO-COMERCIAL
```
||output
`ERROR`
||description
La única persona que entró al centro comercial estaba en `La-Gran-Michoacana` por lo que el registro de salida del `CENTRO-COMERCIAL` es inconsistente.
||input
```
10
2
5
11 entrar CENTRO-COMERCIAL
3 entrar La-Mera-Mera-Michoacana
3 entrar Ajedreces-Pa-Todos
2 entrar La-Autentica-Michoacana
3 entrar La-Gran-Michoacana
```
||output
`Ajedreces-Pa-Todos CENTRO-COMERCIAL La-Gran-Michoacana La-Mera-Mera-Michoacana`
||description
El centro comercial y 3 tiendas rompieron las normas. La lista se muestra en orden alfabético.
||input
```
10
2
7
10 entrar CENTRO-COMERCIAL
2 entrar Deportes-Martin
2 entrar Otso-Abarrotes
1 entrar La-Autentica-Michoacana
2 salir Deportes-Martin
1 salir Otso-Abarrotes
4 salir CENTRO-COMERCIAL
```
||output
`OK`
||description
Las normas fueron respetadas esta vez.
||end
