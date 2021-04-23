typedef struct no no_t;
typedef struct lista lista_t;
lista_t *cria();
void inserir(lista_t *p, int n,int j,int tempo);
void imprimir(lista_t *p);
void retirar(lista_t *p, int n);
void remove_elemento(lista_t *l, int n);