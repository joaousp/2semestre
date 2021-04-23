//biblioteca
#define TamFila 100

typedef int elem;
typedef struct fila fila_t;
fila_t *criar();
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int inserir(fila_t *f, elem x,elem idade, char nome[20]);
int remover(fila_t *f, elem *x,elem *idade, char nome[20]);
void destruir(fila_t *f);