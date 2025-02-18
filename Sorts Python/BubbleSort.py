

vetor = [13, 31, 35, 96, -20, -94, 30, -8, -62,	33,	-92, 49, 74, 93, -14]

print("\nAntes: " + str(vetor) + "\n")

# ----------------------------------------------------------
def bubblesort(array, type = 'c'):
    tamanho = len(vetor)
    trocou = True
    while(trocou):
        print(array)
        trocou = False
        for i in range(0, tamanho - 1):
            if(type == 'c'):
                if(array[i] > array[i+1]):
                    array[i], array[i+1] = array[i+1], array[i]
                    trocou = True
            else:
                if(array[i] < array[i+1]):
                    array[i], array[i+1] = array[i+1], array[i]
                    trocou = True
# ----------------------------------------------------------

bubblesort(vetor, 'c')

print("\nDepois: " +  str(vetor) + "\n")
