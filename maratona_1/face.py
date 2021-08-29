wins = 0
n = int(input())
painel = ['F', 'A', 'C', 'E']
for i in range(n):
    letras = input().split()
    if len(painel) == 0:
        painel.extend(['F', 'A', 'C', 'E'])
    if (painel[-4:][::-1] == letras):
        wins += 1
        painel = painel[:-4]
    else:
        painel.extend(letras)
print(wins)
