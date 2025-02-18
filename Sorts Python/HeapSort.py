import math

def MAXHEAPIFY(V, i, tamanhoHeap):
    L = 2 * i + 1
    R = 2 * i + 2
    MAIOR = i

    if L < tamanhoHeap and V[L] > V[i]:
        MAIOR = L 
    if R < tamanhoHeap and V[R] > V[MAIOR]:
        MAIOR = R
    if MAIOR != i:
        V[i], V[MAIOR] = V[MAIOR], V[i]
        MAXHEAPIFY(V, MAIOR, tamanhoHeap)
        
def BUILDMAXHEAP(V):
    tamanhoHeap = len(V)
    for i in range(tamanhoHeap // 2 - 1, -1, -1):
        MAXHEAPIFY(V, i, tamanhoHeap)
        
def HEAPSORT(V):
    tamanhoHeap = len(V)
    BUILDMAXHEAP(V)
    for i in range(tamanhoHeap - 1, 0, -1):
        V[0], V[i] = V[i], V[0]
        MAXHEAPIFY(V, 0, i)

vetor = [-3, 1, -2, 5, -6, 7]
print(vetor)

HEAPSORT(vetor)

print(vetor)
