
def Merge(V, inicio, meio, fim):
    N = 0
    p1 = inicio
    p2 = meio + 1
    vetorAux = [0] * (fim - inicio + 1)
    while(p1 <= meio and p2 <= fim):
         if(V[p1] < V[p2]):
             vetorAux[N] = V[p1]
             p1 = p1 + 1
         else:
             vetorAux[N] = V[p2]
             p2 = p2 + 1
         N = N + 1
         print(vetorAux)

    while(p2 <= fim):
            vetorAux[N] = V[p2]
            p2 = p2 + 1
            N = N + 1
            print(vetorAux)
    while(p1 <= meio):
            vetorAux[N] = V[p1]
            p1 = p1 + 1
            N = N + 1
            print(vetorAux)
    
    for i in range(0, len(vetorAux)):
        V[inicio + i] = vetorAux[i]
    return V
    
def MergeSort(V, inicio, fim):
    if(inicio < fim):
        meio = (inicio + fim) // 2 
        MergeSort(V, inicio, meio)
        MergeSort(V, meio + 1, fim)
        Merge(V, inicio, meio, fim)
    return V

vetor = [3, 2, 5, 9, 6]

MergeSort(vetor, 0, len(vetor) - 1)
print(vetor)    
