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
// https://pt.stackoverflow.com/questions/127832/remover-elemento-de-array-em-c
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

int stackPop( Stack * obj, int elem );

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

    printf( "\n :: stackVectorInserts :: stackPush: %d", elem );

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
int stackPop( Stack * obj, int elem ) {

    //printf( "\n:: stackPop :: elemento %d ", elem);
    
    int x, retorno;

    // Verifica se há elementos
    if ( obj->numero == 0 ) {

        printf( "-> Vazia! Não há elementos na pilha. ");
        exit(1);
    }

    //printf( "\n:: stackPop :: passou do if :: antes de retirar o elemento  ");
    //printf( "\n %d ", obj->vetor[ obj->numero -1] );
    // Retirar o elemento
    // retorno = obj->vetor[ obj->numero -1];

    /*
    retorno = obj->vetor[ obj->numero -1];

    obj->numero--;
    */

    // for( x = )

    obj->vetor[elem] = -1;
    
    return ( retorno );
}

// TODO: ???
/*
    Eliminar os elementos pares que foram marcados
*/
int stackEmpty( Stack * obj ) {

    int x, xVetorNovo = 0;
    int vetorNovo[Tamanho] = {0};


    for ( x = 0; x < Tamanho; x++ ) {

        if ( obj->vetor[x] != -1) {

            vetorNovo[xVetorNovo] = obj->vetor[x];
            xVetorNovo++ ;
        }
    }

    printf( "stackEmpty :: for " );

    for ( x = 0; x < Tamanho; x++ ) {

        printf( "\n :: stackEmpty :: for :: vetorNovo[%d] = %d",x, vetorNovo[x] );

        obj->vetor[x] = vetorNovo[x];

        // obj->numero-- ;
    }

    return (0);

}


int stackEmptyOLD( Stack * obj ) {

    printf( "\n :: stackEmpty :: " );

    int x, tamanhoSemPar = 0;
    printf( "\n :: stackEmpty 2 :: " );

    // Contar quantos pares - Ocorrencia de -1
    tamanhoSemPar = Tamanho;

    for (x = 1; x < tamanhoSemPar -1 ; x++) {

        if( obj->vetor[x] == -1) {

            // printf( "\n :: stackEmpty :: Eliminando par %d", x );       

            //printf( "\n :: stackEmpty 3 :: encontrou -1 " );
            //tamanhoSemPar++ ;

                tamanhoSemPar-- ;

                obj->vetor[x] = obj->vetor[x +1];
            /*    
            if (x > 2 ) {

                obj->vetor[x -1] = obj->vetor[x +1];
            } else {

                obj->vetor[x] = obj->vetor[x +1];
            }
            */
            
        }
    }

    /*
    printf( "\n :: stackEmpty :: tamanhoSemPar =%d :: ", tamanhoSemPar );
    printf( "\n :: stackEmpty 4 :: " );

    int vetorSemPar[tamanhoSemPar];
    int xVetorSemPar = 0;
    

    for (x = 0; x < tamanhoSemPar ; x++) {

        if( obj->vetor[x] != -1) {

            // printf( "\n :: stackEmpty :: Eliminando par %d", x );       

            vetorSemPar[ xVetorSemPar ] = obj->vetor[x];       

            xVetorSemPar++ ;

        }
    }
    

    // obj->vetor = vetorSemPar;

    for (x = 0; x < tamanhoSemPar; x++ ) {
        printf("\n :: stackEmpty :: Listar vetorSemPar[%d] = %d ", x, vetorSemPar[x] );
    }

    */
    return (0);
}

/*
    função que receba uma pilha e retire todos os 
    elementos pares desta pilha

*/
void stackRemoveEven( Stack * p) {

    printf("\n :: stackRemoveEven :: ");

    int x, retorno = 0 ;


    printf( "\n" );
    printf( "\n" );

    for (x = 0; x < p->numero; x++) {

        // Verificar se nr eh par
        if ( x % 2 == 0 ) {

            // Verificar fortemente
            //printf("\n :: stackRemoveEven :: par: %d ", x);

            // Deixar este comentário
            // Para utilizar a funcao stackPop é necessario passar o elem
            retorno = stackPop( p, x );

        }
    }

    // Reorganizar o vetor
    stackEmpty( p );
}

/*
    Listar o conteudo da pilha
*/
void stackList( Stack * obj ) {

    printf( "\n :: stackList :: " );

    int x, lidos = 0;

    for (x =0; x < obj->numero; x++ ) {

        if( obj->vetor[x] != 0) {

            printf( "\n :: stackList :: obj->vetor[%d] = %d", x, obj->vetor[x] );

            lidos++ ;
        }
    }

    printf( "\n :: stackList :: toal de lidos: %d, obj->numero: %d", x, obj->numero );

} 

void stackVectorInserts( Stack * obj ) {

    int x = 0;

    // 
    //printf( "\n :: stackVectorInserts :: " );
    //printf( "\n :: stackVectorInserts :: obj->numero : %d", obj->numero );

    for (x =0; x < Tamanho; x++ ) {
        
        //printf( "\n :: stackVectorInserts :: for (x=%d)", x );

        stackPush( obj, x);
    }
} 



int main() {

    system( "clear" );
    printf( "\n :: main() :: ");

    //printf( "\n hello world ");
    //printf( "\n me livrei da maldição ");

    // Instanciar Stack
    Stack * objStack = stackNew();

    // popular
    stackVectorInserts( objStack );

    // Exibir/Listar pilha
    stackList( objStack );

    // Remover pares
    stackRemoveEven( objStack );

    // Exibir/Listar pilha
    printf( "\n");
    printf( "\n");
    printf( "\n");
    printf( "\n");
    printf( "\n :: Vai listar após remover pares ::" );
    stackList( objStack );

    // Liberar memoria
    stackFree( objStack );

    return(0);
}

