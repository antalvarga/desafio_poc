#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMANHO 40



char * inverterString( char * palavra) {
//char * inverterString( char palavra[] ) {

    int tamanho = strlen( palavra );
    char palavraInvertida;
    int x, y, ascii;

    // y = tamanho -1;

    // for ( x=0; x < y; x++) {
    //     ascii = palavra[x];
    //     y--;
    // }

    //printf( "\n " );
    //printf( "\n inverterString :: tamanho :: %d ", tamanho );
    //printf( "\n inverterString :: x :: %d ", x );
    //printf( "\n inverterString :: y :: %d ", y );

/*

    printf( "\n inverterString :: palavra :: %c ", palavra[x] );
    printf( "\n inverterString :: x :: %d ", x );
    printf( "\n inverterString :: y :: %d ", y );


    for ( x = 0; x <= y; x++) {
        //ascii = palavra[x];

        palavraInvertida[ y -x] = palavra[x];
    }


*/
    // for ( x = y; x >= 0; x--) {
    for ( x = 0, y = tamanho -1; x < y; x++, y--) {
        ascii = palavra[x];

        palavra[x] = palavra[y];

        palavra[y] = ascii;
        //palavraInvertida[ y -x] = palavra[x];
    }


    // return(palavraInvertida);
    return(palavra);
 
}




// int inverterString2( char palavraInicial[TAMANHO] ) {
char * inverterString2( char * palavraInicial ) {

    int tamanhoPalavraInicial = strlen( palavraInicial );
    int x, y, ascii;

    y = tamanhoPalavraInicial -1;

    // char teste[TAMANHO] = "\0";
    char palavraInvertida[TAMANHO];



    printf("\n inverterString2 :: tamanho %d ", tamanhoPalavraInicial);

    strcpy(palavraInvertida, palavraInicial);

    printf("\n inverterString2 :: depois do strcpy ");

    printf("\n %s", palavraInvertida);

    // *** até aqui está ok ***


    printf("\n inverterString2 :: tamanhoPalavraInicial :: %d", tamanhoPalavraInicial );





    for ( x = y; x >= 0; x--) {

        //palavraInvertida[ y -x] = palavraInicial[x];

        // printf("\n inverterString2 :: dentro do for :: invertida: %c ", palavraInvertida[ 7 -x] );

        //printf("\n inverterString2 :: dentro do for :: X: %d, Y: %d ", x, y );
        //printf("\n inverterString2 :: dentro do for :: Letra inicial : %c", palavraInicial[x] );
        //printf("\n inverterString2 :: dentro do for :: Letra final : %c", palavraInicial[y -x] );

        palavraInvertida[ y-x] = palavraInicial[x];

    }

    printf("\n inverterString2 :: dentro do for :: palavra invertida : %s", palavraInvertida );

    strcpy( palavraInicial, palavraInvertida );

    printf("\n inverterString2 :: dentro do for :: palavra inicial : %s", palavraInicial );



    return( palavraInicial );
}





int main() {

    char palavra[TAMANHO];
    char palavra2[TAMANHO] = "Deus";
    
    
    system("clear");
    printf("\n main() :: \n ");

    printf( "Digite: ");
    scanf("%s", palavra);
    //fgets( palavra, 40, stdin);


    // *** aqui funcionou *** 
    // char * invertida = inverterString( palavra );
    //inverterString( palavra );
    //printf("\n main :: palavra %s", palavra );
    //printf("\n main :: nova %s", invertida );

    // free(palavra);


    inverterString2( palavra );
    inverterString2( palavra2 );
    // strcpy( palavra, inverterString2( palavra2 ) );

    printf("\n main :: após inverter a palavra %s", palavra );
    printf("\n main :: após inverter a palavra2 %s", palavra2  );




    return(0);
}