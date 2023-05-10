public class listaDinamica{
    lista Primeiro;
    lista Ultimo;
    int tamanho = 0;

    public listaDinamica{
        Primeiro = null;
        Ultimo = Primeiro;
    }

    public void add(String Nome){
        if (Primeiro == null){
            Primeiro = new lista;
            Ultimo = Primeiro;
            lista Novo = new lista;
            Novo.setNome(Nome);
            Novo.setProx(null);
            Ultimo.setProx(Novo);
            tamanho++;
        }
        else{
            lista Novo = new lista;
            Novo.setNome(Nome);
            Novo.setProx(null);
            Ultimo.setProx(Novo);
            tamanho++; 
        }

    }

    public void printlista{
        lista percorre = getProx();
        while percorre != null{
            Sistem.out.println(percorre.getNome());
            percorre = percorre.getProx();

        }
    }

}