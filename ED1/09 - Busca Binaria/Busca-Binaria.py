import random
import time

def buscaLinear(vet: int, elem: int):
    n = len(vet)
    i = 0
    while i <= n - 1:
        if elem == vet[i]:
            return i
        i +=1
    return -1



def buscaBinaria(vet: int, elem: int):
    n = len(vet)
    ini = 0
    fim = n - 1
    while ini <= fim:
        meio = int((ini + fim)/2)
        if elem < vet[meio]:
            fim = meio - 1
        else:
            if elem > vet[meio]:
                ini = meio + 1
            else:
                return meio
    return -1


def main():
  

    tamanhos = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
    for tamanho in tamanhos:
        print(f"Vetor de tamanho {tamanho}:")   
        posicao = random.randint(0, tamanho-1)   

        # busca linear   
        vb = list(range(tamanho))
        random.shuffle(vb)
        inicio = time.time()
        indice = buscaLinear(vb, posicao)
        fim = time.time()
        print(f"Tempo de execução Busca linear: {fim - inicio} segundos, posicao {indice}")

        # busca binaria
        vb = list(range(tamanho))
        inicio = time.time()
        indice = buscaBinaria(vb, posicao)
        fim = time.time()
        print(f"Tempo de execução BUsca Binaria: {fim - inicio} segundos, posicao {indice}")


if __name__ == "__main__":
    main()