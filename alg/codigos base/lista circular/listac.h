typedef int elem;
typedef struct lista lista_t;

lista_t *criar();
void liberar(lista_t *l);
void inserir(lista_t *l, elem x);
int tamanho(lista_t *l);
void imprimir(lista_t *l);
