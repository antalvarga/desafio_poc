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


#include <stdio.h>
#include <stdlib.h>


struct livro {

    char nome[30];
    struct livro * proximo;
};

struct livro * aloca() {

    return malloc( sizeof( struct livro ) );
}

void AddItem( struct livro * cabeca) {

    struct livro * aux, * novo;

    aux = cabeca;

    while (aux->proximo) {

        aux = aux->proximo;
    }

    novo = aloca();

    printf( "Digite o nome" );

    gets(novo->nome);

    novo->proximo = NULL;

    aux->proximo = novo;

    // 05:50 - usar strcmp para comparar 

    
}

int main() {

    system( "clear" );
    printf( "\n :: main() :: ");

    struct livro acervo;

    acervo.proximo = NULL;

    AddItem( &acervo );

    printf("%s \n", acervo.proximo->nome);
    

    // free

    // fazer funcao pra imprimir os elementos da lista

    return(0);
}

