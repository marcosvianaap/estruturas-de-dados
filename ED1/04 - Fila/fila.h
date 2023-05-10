typedef int TipoItem;
const int tam = 85;

class FilaVet{
    private:
    int ini, n;
    TipoItem* vet;

    public:
    FilaVet(); // construtor
    ~FilaVet(); // destrutor
    bool isEmpty();
    bool isFull();
    void enqueue(TipoItem item);
    TipoItem dequeue();
    void reset();
    FilaVet concatena(FilaVet f2);
    FilaVet merge(FilaVet f3);
    void print();
};
