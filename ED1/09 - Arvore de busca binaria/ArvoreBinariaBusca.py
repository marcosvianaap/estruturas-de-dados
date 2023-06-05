from NoArvoreBinaria import NoArvoreBinaria

class ArvoreBinariaBusca:
    # Construtor vazio
    def __init__(self):
        self.raiz = None

    def insere(self, valor):
        # Insere um valor na árvore binária de busca
        if self.raiz is None:
            self.raiz = NoArvoreBinaria(valor)
        else:
            self._insere_recursivo(self.raiz, valor)

    def _insere_recursivo(self, no, valor):
        # Método privado recursivo para inserir um valor na árvore binária de busca
        if valor < no.valor:
            if no.esquerda is None:
                no.esquerda = NoArvoreBinaria(valor)
            else:
                self._insere_recursivo(no.esquerda, valor)
        else:
            if no.direita is None:
                no.direita = NoArvoreBinaria(valor)
            else:
                self._insere_recursivo(no.direita, valor)

    def busca(self, valor):
        # Realiza uma busca por um valor na árvore binária de busca
        return self._busca_recursivo(self.raiz, valor)

    def _busca_recursivo(self, no, valor):
        # Método privado recursivo para realizar a busca por um valor na árvore binária de busca
        if no is None or no.valor == valor:
            return no
        if valor < no.valor:
            return self._busca_recursivo(no.esquerda, valor)
        else:
            return self._busca_recursivo(no.direita, valor)

    def remover(self, valor):
        # Remove um valor da árvore binária de busca
        self.raiz = self._remover_recursivo(self.raiz, valor)

    def _remover_recursivo(self, no, valor):
        # Método privado recursivo para remover um valor da árvore binária de busca
        if no is None:
            return no
        if valor < no.valor:
            no.esquerda = self._remover_recursivo(no.esquerda, valor)
        elif valor > no.valor:
            no.direita = self._remover_recursivo(no.direita, valor)
        else:
            if no.esquerda is None:
                return no.direita
            elif no.direita is None:
                return no.esquerda
            no_min = self._encontrar_no_minimo(no.direita)
            no.valor = no_min.valor
            no.direita = self._remover_recursivo(no.direita, no_min.valor)
        return no

    def _encontrar_no_minimo(self, no):
        # Encontra o nó mínimo na árvore binária de busca a partir de um nó dado
        atual = no
        while atual.esquerda is not None:
            atual = atual.esquerda
        return atual

    def percorrer_em_ordem(self):
        # Percorre a árvore binária de busca em ordem e imprime os valores
        self._percorrer_em_ordem_recursivo(self.raiz)

    def _percorrer_em_ordem_recursivo(self, no):
        # Método privado recursivo para percorrer a árvore binária de busca em ordem
        if no is not None:
            self._percorrer_em_ordem_recursivo(no.esquerda)
            print(no.valor, end=" ")
            self._percorrer_em_ordem_recursivo(no.direita)
