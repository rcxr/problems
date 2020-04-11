# https://omegaup.com/arena/problem/A-contar-lapices

# La primer línea de entrada tiene dos valores:
# - Cantidad de lapices que se cayeron (n)
# - Número de lápiz deseado (lapizDeseado)
tokens = input().split()
n = int(tokens[0])
lapizDeseado = int(tokens[1])

# Empecemos a contar en cero la cantidad de lápices que son del número de lápiz deseado.
respuesta = int()

# Leer n lápices que se cayeron y ver cuántos son del número deseado.
for i in range(n):
  lapiz = int(input())
  if lapiz == lapizDeseado:
    # Si el lápiz es del número deseado, subir el contador que guarda la respuesta final.
    respuesta += 1

# Simplemente imprimir la respuesta.
print(respuesta)
