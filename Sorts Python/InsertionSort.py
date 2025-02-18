#1. InsertionSort (V, TAM)
#2. Para cada posição I entre 1 e N-1, (I = I+1) faça:
#3. auxiliar = valor na posição I
#4. J = I -1
#5. Enquanto (J >= 0) && (auxiliar < V[J]):
#6. V[J+1] = V[J]
#7. J = J -1
#8. V[J+1] = auxiliar

def InsertionSort(V, TAM):
    for N in range(0, TAM):
        aux = V[N]
        J = N-1
        while(J >= 0 and aux < V[J]):
            V[J+1] = V[J]
            J = J-1
            print(str(V))
        V[J+1] = aux
        
    return V

vetor = [13, 31, 35, 96, -20, -94, 30, -8, -62, 33, -92, 49, 74, 93, -14]

InsertionSort(vetor, len(vetor))
print(vetor)
