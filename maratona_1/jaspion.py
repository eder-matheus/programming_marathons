
instancias = int(input())
for i in range(instancias):
    dic = {}
    entrada = input().split()
    m = int(entrada[0])
    n = int(entrada[1])
    for j in range(m):
        jap = input()
        port = input()
        dic[jap] = port
    for k in range(n):
        frase = input().split()
        for p_i in range(len(frase)):
            trad = dic.get(frase[p_i], frase[p_i])
            if p_i == len(frase)-1:
                print(trad, end='')
            else:
                print(trad+" ", end='')
        print()
    print()
