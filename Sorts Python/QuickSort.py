

def Particiona(V, inicio, fim):
    esquerda = inicio
    direita = fim
    Pivo = V[inicio]
    
    while(esquerda < direita):
        while(V[esquerda] <= Pivo and esquerda < fim):
            esquerda = esquerda + 1
        while(V[direita] >= Pivo and direita > inicio):
            direita = direita - 1
        if(esquerda < direita):
            V[esquerda], V[direita] = V[direita], V[esquerda]
            print(vetor)
    V[direita], V[inicio] = V[inicio], V[direita]
    print(vetor)
    return direita            
             
            
def QuickSort(V, inicio, fim):
    if(inicio < fim):
        pivo = Particiona(V, inicio, fim)
        QuickSort(V, inicio, pivo)
        QuickSort(V, pivo+1, fim)
    
vetor = [13, 31, 35, 96, -20, -94, 30, -8, -62, 33, -92, 49, 74, 93, -14]

print(vetor)

QuickSort(vetor, 0, len(vetor) - 1)

print(vetor)