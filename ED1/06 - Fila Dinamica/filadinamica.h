typedef int TipoItem;

class No
{
  public:
  TipoItem valor;
  No* proximo;
};

class filadinamica{ 

    private:
    No* primeiro; //front
    No* ultimo; //rear

    public:
    filadinamica();//construct
    ~filadinamica();  
    bool estavazio(); //isEmpty
    bool estacheio(); //isFull
    void push(TipoItem item);//insere item
    TipoItem pop();//remove item
    void print(); //imprime elementos
  
};
