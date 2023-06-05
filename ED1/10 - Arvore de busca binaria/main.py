from ArvoreBinariaBusca import ArvoreBinariaBusca

def main():
    arvore = ArvoreBinariaBusca()

    while True:
        print("\n==== Árvore de Busca Binária ====")
        print("1. Inserir valor")
        print("2. Buscar valor")
        print("3. Remover valor")
        print("4. Exibir em ordem")
        print("5. Sair")

        escolha = input("Escolha uma opção (1-5): ")

        if escolha == "1":
            valor = int(input("Digite o valor a ser inserido: "))
            arvore.insere(valor)
            print("Valor inserido com sucesso!")
        elif escolha == "2":
            valor = int(input("Digite o valor a ser buscado: "))
            resultado = arvore.busca(valor)
            if resultado:
                print("Valor encontrado!")
            else:
                print("Valor não encontrado.")
        elif escolha == "3":
            valor = int(input("Digite o valor a ser removido: "))
            arvore.remover(valor)
            print("Valor removido com sucesso!")
        elif escolha == "4":
            print("Arvore em ordem:")
            arvore.percorrer_em_ordem()
        elif escolha == "5":
            print("Encerrando o programa...")
            break
        else:
            print("Opção inválida. Por favor, escolha uma opção válida.")

if __name__ == "__main__":
    main()
    