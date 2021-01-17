/*

    AV 20210115

    Desafio muxi:
 

> 4. Considere a existência de um tipo abstrato cuja 
interface é definida da seguinte forma:

    typedef struct stack Stack;
    Stack *stackNew (void);
    void stackFree (Stack *p);
    void stackPush (Stack *p, int elem);
    int stackPop (Stack *p);
    int stackEmpty (Stack *p);

    Escreva uma função que receba uma pilha e retire todos os 
    elementos pares desta pilha. A função deve obedecer ao se-
    guinte protótipo:
    
    void stackRemoveEven (Stack *p);


    pwd:  *** alterar no fim ***
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/poc/desafio4

    compilacao: *** alterar no fim ***
    gcc pocNew1.c -o pocNew1

    Execucao: 
    ./pocNew1 

*/

// Referencias
// https://www.embarcados.com.br/objetos-em-linguagem-c/
// https://pt.stackoverflow.com/questions/127279/como-fazer-uma-interface-em-c
// http://linguagemc.com.br/redefinicao-de-tipos-com-typedef/
// https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap11.pdf

#include <stdio.h>
#include <stdlib.h>
#include </Volumes/Macintosch/Users/asvarga/App/C/muxi/poc/desafio4/include/stack.h>


#define Tamanho 40

struct stack
{
    int numero;
    int vetor [Tamanho];
};



// prototipos
Stack * stackNew( void );

void stackFree( Stack * obj );

void stackPush( Stack * obj, int elem );

int stackPop( Stack * obj );

int stackEmpty( Stack * obj );

void stackRemoveEven( Stack * p);



/* 
    Função para criar a pilha aloca dinamicamente essa estrutura 
    e inicializa a pilha como vazia 
*/
Stack * stackNew( void ) {
    Stack * obj = (Stack * ) malloc( sizeof( Stack ));

    obj->numero = 0;

    return obj;
}

/*
    Função para liberar a memória alocada
*/
void stackFree( Stack * obj ) {

    free(obj);
}

/*
    Funcao inserir um elemento na pilha    
*/
void stackPush( Stack * obj, int elem ) {

    if( obj->numero == Tamanho ) {

        printf( "-> Capacidade esgotada! " );
        exit(1);
    }

    obj->vetor[obj->numero] = elem;
    obj->numero++ ;
}

/*
    Função para retirar o elemento do topo da pilha
*/
int stackPop( Stack * obj ) {

    int retorno;

    // Verifica se há elementos
    if ( obj->numero == 0 ) {

        printf( "-> Vazia! Não há elementos na pilha. ");
        exit(1);
    }

    // Retirar o elemento
    // retorno = obj->vetor[ obj->numero -1];
    retorno = obj->vetor[ obj->numero--];

    //obj->numero--;

    return ( retorno );
}

int stackEmpty( Stack * obj ) {

    return (0);
}

/*
    função que receba uma pilha e retire todos os 
    elementos pares desta pilha

*/
void stackRemoveEven( Stack * p) {

    printf(" :: stackRemoveEven :: ");

    int x, retorno = 0 ;


    for (x = 0; x < p->numero; x++) {


        // Verificar se nr eh par
        if ( x % 2 == 0 ) {

            // Verificar fortemente
            retorno = stackPop( p );

        }
    }
}



void stackList( Stack * obj ) {

    printf( "\n :: stackList :: " );

    int x = 0;

    for (x =0; x < obj->numero; x++ ) {

        printf( "\n :: stackList :: obj->vetor[%d] = %d", x, obj->vetor[x] );

    }

} 

void stackVectorInserts( Stack * obj ) {

    int x = 0;

    for (x =0; x < obj->numero; x++ ) {
        
        stackPush( obj, x);
    }
} 





int main() {

    system( "clear" );
    printf( "\n :: main() :: ");

    printf( "\n hello world ");
    printf( "\n me livrei da maldição ");

    // Instanciar Stack
    Stack * objStack = stackNew();

    // popular
    stackVectorInserts( objStack );

    // Exibir/Listar pilha
    stackList( objStack );

    // Liberar memoria
    stackFree( objStack );

    // Remover pares

    // Exibir/Listar pilha
    // stackList( objStack );


    return(0);
}

