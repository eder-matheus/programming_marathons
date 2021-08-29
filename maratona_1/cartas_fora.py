
import sys

for entrada in sys.stdin:
    entrada = int(entrada)
    if (entrada == 0):
        exit()
    cartas = []
    discarded = []
    for c in range(entrada):
        cartas.append(str(c+1))
    while (len(cartas) >= 2):
        discarded.append(cartas.pop(0))
        cartas.append(cartas.pop(0))
    print("Discarded cards:", ', '.join(discarded))
    print("Remaining card:", cartas[0])
