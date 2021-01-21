/*

    AV 20210119

    Desafio muxi:
 

    > 5. Implemente a seguinte função

    void listPartition(SingleLinkedListOfIntsNode **head, int x);

    Onde head é o início de uma lista de inteiros com encadeamento 
    simples que deve ser particionada de forma que todos os valores 
    menores do que x apareçam antes dos valores maiores do que x.

    pwd:  *** alterar no fim ***
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/poc/desafio5

    compilacao: *** alterar no fim ***
    gcc pocNew1.c -o pocNew1

    Execucao: 
    ./pocNew1 

*/

// Referencias
// https://www.youtube.com/watch?v=Ta1SODOsen0
// 

// Referencias
// https://pt.stackoverflow.com/questions/300449/retirar-elemento-de-um-vetor-em-c
// http://linguagemc.com.br/redefinicao-de-tipos-com-typedef/
// https://pt.stackoverflow.com/questions/486590/como-ordenar-uma-lista-encadeada-por-ordem-do-código


#include <stdio.h>
#include <stdlib.h>


typedef int err_t;


#define Tamanho 10
#define zero 0



err_t findCommon( int * list1, int numElem1, int * list2, int numElem2, int * result, int resultSize ) {

    //int x1, x2 = zero;
    int xResult = 0;

    err_t retorno = 0;


    for (int x = zero; x < Tamanho; x++) {

        printf( "\n:: findCommon :: list1[%d] = %d :: list2[%d] = %d ", x, list1[x], x, list2[x] );
    }
    

    
    printf( "\n");
    printf( "\n :: findCommon :: Pesquisando... ");

    for ( int x1 = zero; x1 < Tamanho; x1++ ) {

        printf( "\n :: findCommon :: Pesquisando...:: list1[%d] = %d :: ", x1, list1[x1] );

        for ( int x2 = zero; x2 < Tamanho; x2++ ) {

            printf( "\n :: findCommon :: Pesquisando...:: list2[%d] = %d :: ", x2, list2[x2] );

            if( list1[x1] == list2[x2] ) {

                result[ xResult ] = list1[x1];

                xResult++ ;
            }
        }
    }


    return( retorno );                    
}

void popularArray( int * list1, int * list2 ) {

    printf( "\n :: popularArray :: ");
    // printf( "\n :: popularArray :: ");

    int x = zero;

    for ( x = zero; x < Tamanho; x++ ) {

        list1[x] = x;
        list2[x] = x *3;
    } 
}





int main() {

    system( "clear" );
    printf( "\n :: main() :: ");

    int x = zero;

    int * list1 = malloc(sizeof(int) * Tamanho);
    int numElem1 = Tamanho;

    int * list2 = malloc(sizeof(int) * Tamanho);
    int numElem2 = Tamanho;

    int * result = malloc(sizeof(int) * Tamanho);
    int resultSize = Tamanho;

    // 
    popularArray( list1, list2 );


    err_t erro = findCommon( list1, numElem1, list2, numElem2, result, resultSize );     


    printf( "\n:: Conjunto Intersecção ::" );
    
    for (x = zero; x < Tamanho; x++) {

        if ( result[x] != 0 ) {

            printf( "\n:: result[%d] = %d ::", x, result[x] );
        }
    }
    

    free(list1);
    free(list2);
    free(result);

    printf( "\n :: Fim :: ");

    return(0);
}

