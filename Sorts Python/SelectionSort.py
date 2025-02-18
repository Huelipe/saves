def selectionSort(V, tam):
    
    comparacoes = 0
    for N in range(0, tam):
        print(V)
        menor = V[N]
        indice = N
        for i in range(N, tam):
            if V[i] < menor:
                menor = V[i]
                indice = i
            comparacoes = comparacoes + 1
        if menor != V[N]:
            aux = V[N]
            V[N] = V[indice]
            V[indice] = aux
    print(comparacoes)
    return V

vetor = [13, 31, 35, 96, -20, -94, 30, -8, -62, 33, -92, 49, 74, 93, -14]

selectionSort(vetor, len(vetor))



