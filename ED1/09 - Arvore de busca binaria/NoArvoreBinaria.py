class NoArvoreBinaria:
    def __init__(self, valor):
        self._valor = valor
        self._esquerda = None
        self._direita = None

    def _obter_valor(self):
        return self._valor

    def _definir_valor(self, valor):
        self._valor = valor

    def _obter_esquerda(self):
        return self._esquerda

    def _definir_esquerda(self, esquerda):
        self._esquerda = esquerda

    def _obter_direita(self):
        return self._direita

    def _definir_direita(self, direita):
        self._direita = direita

    valor = property(_obter_valor, _definir_valor)
    esquerda = property(_obter_esquerda, _definir_esquerda)
    direita = property(_obter_direita, _definir_direita)