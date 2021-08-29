
import sys
from queue import Queue, LifoQueue, PriorityQueue

pilha: LifoQueue = LifoQueue()
fila: Queue = Queue()
prioridade: PriorityQueue = PriorityQueue()

while(True):
    try:
        n = int(input())
        is_pilha = True
        is_fila = True
        is_prioridade = True
        for i in range(0, n):
            case = input().split()
            action = case[0]
            item = int(case[1])
            if action == "1":  # insere
                pilha.put(item)
                fila.put(item)
                prioridade.put(-item)
            else:  # remove
                if (item != pilha.get()):
                    is_pilha = False
                if (item != fila.get()):
                    is_fila = False
                if (item != -prioridade.get()):
                    is_prioridade = False

                # print("expected", item, "pilha", pilha.get(), "fila", fila.get(),
                #       "prioridade", -prioridade.get())
        is_count = 0
        if is_pilha:
            result = "stack"
            is_count += 1
        if is_prioridade:
            result = "priority queue"
            is_count += 1
        if is_fila:
            result = "queue"
            is_count += 1

        if (is_count == 1):
            print(result)
        elif (is_count > 1):
            print("not sure")
        else:
            print("impossible")
    except EOFError:
        break
