Supongamos que vivimos en un mundo paralelo en el que omegaUp no existe y el Coding Cup se lleva a cabo manualmente. Es decir:

- estudiantes mandan sus códigos por correo
- los profesores compilan los código y revisan si todo está bien

¡Para tu mala fortuna te ha tocado la tarea de determinar el equipo ganador!

Para ayudarte en tu tarea los profesores cada que acepten una solución de un equipo, te mandan un mensaje con el nombre del equipo y el número de problema aceptado.

La hora de la premiación se acerca y la presión recae completamente sobre ti.

Escribe un programa que dados los mensajes de los profesores listes a los equipos que quedaron en primer lugar en order alfabético separados por espacios.

Ejemplo, los profes te mandan estos mensajes:

- Pachuca 5
- Orizaba 4
- Orizaba 2
- Pachuca 2
- Celaya 1

Los equipos ganadores con 2 problemas resueltos serían: `Orizaba Pachuca`

# Input

 - Un entero, $N$, indicando la cantidad de mensajes de los profesores
 - $N$ renglones representando los mensajes. Cada mensaje sigue el formato `EQUIPO P` donde:
   - `EQUIPO` es el nombre del equipo
   - $P$ es el número del problema resuelto

## Notas

 - $1 \le N \le 500$
 - $1 \le P \le 100$
 - Los nombres de los equipos son de máximo 16 caracteres
 - Los nombres de los equipos sólo usan caracteres del abecedario inglés (e.g. orizaba, PACHUCA, iTSuR)
 - Los nombres de los equipos no tienen espacios

# Output

Imprime la lista de nombres de los equipos que empataron en primer lugar separados por un espacio y en orden alfabético.

# Ejemplos

||input
5
Pachuca 5
Orizaba 4
Orizaba 2
Pachuca 2
Celaya 1
||output
Orizaba Pachuca
||description
Orizaba y Pachuca empatan en primer lugar
||input
3
Orizaba 4
Orizaba 2
Orizaba 4
||output
Orizaba
||description
Orizaba ganó el concurso
||end
