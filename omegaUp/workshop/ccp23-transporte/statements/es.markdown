# Description

En muchas ciudades en Centroamérica el transporte público impacta la vida de millones. Optimizar el transporte público para reducir el tráfico y mejorar los tiempos de translado puede mejorar la calidad de vida de las personas y reducir sus costos asociados, así como prevenir que se desperdicien recursos.

Como parte de este proceso de optimización, el gobierno de la ciudad en la que vives decidió planear la construcción de diversas rutas de transporte conectando distintos distritos en tu ciudad.

Para identificar la ruta que la población pide más, el gobierno realizó una encuesta en la población y recolectó los resultados en el formato `ORG->DES` donde `ORG` representa las tres letras del punto de inicio de la ruta y `DES` representa las tres letras del punto de fin de la ruta.

- `ORG` = tres letras del punto de inicio de la ruta
- `DES` = tres letras del punto de fin de la ruta

Como buena científica o científico en computación tu tarea es desarrollar un algoritmo que lea los resultados de la encuesta ciudadana e identifique la ruta más popular. La salida de tu algoritmo dede ser la ruta más popula seguida del número de personas que la eligieron. Si dos rutas empatan tu algoritmo deberá listarlas a todas en orden alfabético.

# Entrada

- Una cadena de caracteres. La cadena puede tener hasta 1152 caracteres.
  - `ABC->XYZ` es una ruta diferente a `XYZ->ABC`
  - Los puntos de inicio y fin sólo usan letras en mayúsculas y números (`A-Z` y `0-9`)

# Salida

- La ruta más popular seguida del número de personas que la eligieron. Estos valores deberán estar separados por un espacio
  - En caso de empate, lista cada ruta ganadora en una línea diferente. Lista las rutas en orden alfabético

# Ejemplo

||input
RFM->CDVRFM->CDVJCT->GRDJCT->GRDJCT->GRDCDV->RFMCDV->RFM
||output
JCT->GRD 3
||description
Hay 3 entradas para la ruta JCT-GRD
||input
DI1->DI3DI1->DI1DI2->DI1
||output
DI1->DI2 1
DI1->DI3 1
DI2->DI1 1
||description
Empate de tres rutas. Las tres rutas aparecen en orden alfabético.
||end
