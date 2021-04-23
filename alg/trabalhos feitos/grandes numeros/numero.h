
typedef int elem;
typedef struct lista lista_t;

lista_t *criar();
void liberar(lista_t *l);
void inserir(lista_t *l, elem x);
int tamanho(lista_t *l);
void imprimir(lista_t *l);
//certo^^

int sml(lista_t *a,lista_t *b,int n1,int n2);
int eql(lista_t *a,lista_t *b,int n1,int n2);
int big(lista_t *a,lista_t *b,int n1,int n2);
void* sum(lista_t *a,lista_t *b,int n1,int n2);
lista_t* limpar(lista_t *a);
