public class lista{
    private String Nome;
    private lista Prox;

    public lista(){

    }

    public String getNome(){
        return Nome;
    }
    public void setNome(String Nome){
        this.Nome = Nome;
    }

    public lista getProx(){
        return Prox;
    }
    public void setProx(Lista Prox){
        this.Prox = Prox;
    }
}