https://pt.stackoverflow.com/questions/102983/qual-a-diferen%c3%a7a-entre-lista-simplesmente-encadeada-e-duplamente-encadeada

#include <stdlib.h>

struct NO
{
    int info;
    struct NO *proxima;
    struct NO *anterior;
};

void inserir(int);
void remover(int);
void imprime(void);
void inicializar(void);

struct NO *p, *auxiliar;

int cont;




int main(void)
{
    int opcao, valor;

    inicializar();

    do
    {
        printf("\n1 - Inserir");
        printf("\n2 - Remover");
        printf("\n3 - Imprimir");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        __fpurge(stdin);

        switch(opcao)
        {
            case 1:
                //Inserir
                printf("\nValor: ");
                scanf("%d", &valor);
                __fpurge(stdin);
                inserir(valor);

                break;
            case 2:
                //Remover.
                printf("\nValor: ");
                scanf("%d", &valor);
                __fpurge(stdin);

                remover(valor);
                break;
            case 3:
                //Imprimir.
                imprime();
                break;
        }
    }
    while ((opcao >= 1) && (opcao <= 3));

    free(p);

    return 0;
}

void inicializar()
{
    p = NULL;
    auxiliar = NULL;
    cont = 0;
}

// adicionar
void inserir(int valor)
{
    if (cont == 0) /*Primeiro NÓ*/
    {
        /*Aloca o primeiro NÓ*/
        p = (struct NO *) malloc( sizeof(struct NO));
        auxiliar = p;
        p->info = valor;
        p->proxima = NULL;
        p->anterior = NULL;

        cont++;
    }
    else
    {
        auxiliar->proxima = (struct NO *) malloc(sizeof(struct NO));
        auxiliar->proxima->anterior = auxiliar;
        auxiliar = auxiliar->proxima;
        auxiliar->info = valor;
        auxiliar->proxima = NULL;

        cont++;
    }
}

void imprime()
{
    struct NO * imp;
    imp = p;

    if (cont == 0)
    {
        printf("\nLista vazia!");
    }
    else
    {
        while (imp != NULL)
        {
            printf("%d ", imp->info);
            imp = imp->proxima;
        }

        printf("\nQuantidade de elementos: %d", cont);
    }
}

void remover(int valor)
{
    struct NO * navega;
    navega = p;

    if (cont == 0)
    {
        printf("\nLista vazia!");
    }
    else
    {
        while (navega != NULL)
        {
            if (navega->info == valor)
            {
                if ((navega->anterior == NULL) && (navega->proxima == NULL))
                {
                    free(navega);
                    auxiliar = navega = p = NULL;

                    cont--;

                    break;
                }
                if ((navega->anterior == NULL) && (navega->proxima != NULL))
                {
                    p = p->proxima;
                    free(navega);
                    p->anterior = NULL;
                    navega = p;

                    cont--;

                    break;
                }
                if ((navega->anterior != NULL) && (navega->proxima != NULL))
                {
                    navega->anterior->proxima = navega->proxima;
                    navega->proxima->anterior = navega->anterior;
                    free(navega);
                    navega = p;

                    cont--;

                    break;
                }
                if ((navega->anterior != NULL) && (navega->proxima == NULL))
                {
                    auxiliar = auxiliar->anterior;
                    free(navega);
                    auxiliar->proxima = NULL;
                    navega = p;

                    cont--;

                    break;
                }
            }
            else
            {
                navega = navega->proxima;
            }
        }

        printf("\nQuantidade de elementos: %d", cont);
    }
}
