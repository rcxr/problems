En el Tecnológico Nacional de México los profesores interesados por optimizar recursos para hacer más y mejores concursos de programación han creado una red de mensajería interna para intercambiar material, libros y equipo tecnológico durante los viajes que hacen entre diferentes ciudades por conferencias y talleres.

En esta red cada profesor se registra listando las ciudades por las cuales viaja frecuentemente. Posteriormente cualquier profesor puede pedirle a miembros de la red que lleven un paquete en su siguiente viaje a otra ciudad en la que el paquete es entregado ya sea a su destinatario final o a otro profesor de la red.

Los paquetes que se envían en esta red no son urgentes. Lo único que importa es que lleguen a su destino independientemente del tiempo que tome.

Ejemplo, si en la red se hubieran registrado tres profesores que viajan entre las siguientes ciudades:

- Profesor 1: Orizaba, Pachuca
- Profesor 2: Pachuca, Celaya, Acapulco
- Profesor 3: Campeche, Chetumal

Sería posible mandar un paquete de Orizaba a Acapulco a través de este sistema:

- Remitente le da el paquete a Profesor 1 en Orizaba
- Profesor 1 lleva el paquete a Pachuca en su siguiente conferencia y se lo entrega a Profesor 2
- Profesor 2 lleva el paquete a Acapulco en su siguiente taller y se lo entrega al destinatario

Sin embargo no es posible usar la red para enviar un paquete de Orizaba a Chetumal. Lamentablemente se tiene que usar la mensajería normal y usar dinero del presupuesto.

Eres el encargado de escribir un programa que determine si es posible que un paquete llegue de un origen a un destino usando esta red.

Se te da una lista representando a los profesores registrados en la red con las ciudades que frecuentan.

Se te da una ciudad origen y una ciudad destino y en dado caso de ser posible usar la red para enviar el paquete imprime "posible", de otra forma escribe "imposible".

# Input

 - Un entero, $N$, indicando la cantidad de profesores registrados
 - $N$ renglones representando a los profesores registrados en la red. Cada renglón seguirá el formato `M CIUDAD_1 CIUDAD_2 ... CIUDAD_M` donde:
   - $M$ es la cantidad de ciudades que el profesor frecuenta separadas por un espacio
   - `CIUDAD_1 CIUDAD_2 ... CIUDAD_M` son los nombres de las $M$ ciudades
 - Una cadena $ORIGEN$ que representa el nombre de la ciudad origen
 - Una cadena $DESTINO$ que representa el nombre de la ciudad destino

## Notas

 - $1 \le N \le 100$
 - $1 \le M \le 100$
 - Los nombres de las ciudades son de máximo 16 caracteres
 - Los nombres de las ciudades sólo usan caracteres de palabra ASCII (es decir sin acentos, sin ñ y pueden incluir números)
 - Los nombres de las ciudades no tienen espacios (son una sola palabra)

# Output

Imprime `posible` si se puede utilizar la red para enviar el paquete, de otra forma imprime `imposible`.

# Ejemplos

||input
3
2 orizaba pachuca
3 pachuca celaya acapulco
2 campeche chetumal
orizaba
acapulco
||output
posible
||description
Es posible enviar el paquete usando al primer y segundo profesor
||input
3
2 orizaba pachuca
3 pachuca celaya acapulco
2 campeche chetumal
orizaba
chetumal
||output
imposible
||description
No hay forma en la que el paquete llegue de Orizaba a Chetumal usando la red de profesores
||end
