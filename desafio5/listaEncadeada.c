


// https://www.youtube.com/watch?v=Uk8v7gB2rHk&t=6s

#include <stdio.h>
#include <stdlib.h>


// No = SingleLinkedListOfIntsNode
typedef struct no No;

struct no {

    int num;
    struct no * proximo;

};



// 13:00
// criar_no = criar
No * criar_no() {

    // 14:05
    No * novo = (No * )malloc( sizeof( No ) );

    return( novo );
}

// 15:50
No * inserir_no_inicio( No * lista, int dado ) {

    No * novo_no = criar_no();

    // 17:00
    novo_no->num = dado;


    // 20:!2
    // if ( ! lista ) {
    if ( lista == NULL ) {

        lista = novo_no;

        novo_no->proximo = NULL;

    } else {
        // 22:50
        novo_no->proximo = lista;

        lista = novo_no;

    }

    return( lista );

}

// 24:30
void imprimir_lista( No * lista ) {

    printf( "\n:: imprimir lista :: " );

    // 26:50
    No * auxiliar = lista;

    while (auxiliar != NULL) {

        printf( "\n:: item -> %d :: ", auxiliar->num );

        auxiliar = auxiliar->proximo;        
    }    
}

No * popular_lista( No * lista ) {

    for ( int x = 0; x < 10; x++ ) {

        lista = inserir_no_inicio( lista, x );
    }

    return( lista );

}


// void listPartition(SingleLinkedListOfIntsNode **head, int x) {
void listPartition(No ** head, int x) {


    printf( "\n:: listPartition :: " );

    // 26:50
    No * auxiliar = * head;

    No * auxiliar2 = auxiliar;

    
    while (auxiliar != NULL ) {

        if ( auxiliar->num < x ) {

            printf( "\n:: item -> %d :: ", auxiliar->num );
        }

        auxiliar = auxiliar->proximo;        
    }    
    

    printf( "\n");
    printf( "\n:: X -> %d :: ", x );
    printf( "\n");


    while (auxiliar2 != NULL ) {

        if ( auxiliar2->num > x ) {

            printf( "\n:: item -> %d :: ", auxiliar2->num );
        }

        auxiliar2 = auxiliar2->proximo;        
    }    



}



int main () { 

    system("clear");

    printf( "\n hello zord! ");


    No * lista = NULL;

    // 28:54
    /*
    lista = inserir_no_inicio( lista, 10 );
    lista = inserir_no_inicio( lista, 5 );
    lista = inserir_no_inicio( lista, 15 );
    */

    lista = popular_lista( lista );

    //imprimir_lista( lista );


    //    No * novo = (No * )malloc( sizeof( No ) );
    //No ** teste = ( No ** lista ); 

    listPartition( &lista, 7 );


    return(0);
}