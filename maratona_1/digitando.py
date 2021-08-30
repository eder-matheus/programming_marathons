import sys


class TrieNode():
    def __init__(self, letra):
        self.letra = letra
        self.children = {}
        self.chave = False

    def add(self, palavra):
        for char in palavra:
            if char not in self.children:
                self.children[char] = TrieNode(char)
            self = self.children[char]
        self.chave = True

    def find(self, palavra: str) -> int:
        custo = 0
        for char in palavra:
            self = self.children[char]
            if (len(self.children) > 1) or self.chave:
                custo += 1
        return custo


for n in sys.stdin:
    n = int(n)
    trie = TrieNode(None)
    palavras = []
    total = 0
    for p in range(0, n):
        palavras.append(input())
        trie.add(palavras[p])
    for p in palavras:
        total += trie.find(p)
    print(round(total/len(palavras), 2))
