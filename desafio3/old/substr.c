// https://pt.stackoverflow.com/questions/190755/como-separar-uma-string-em-pedaços
/*

    AV 20210111
    Desafio muxi:


    > 3. Escreva uma função que dada uma string composta por substrings 
    separadas por um dado caractere, retorne todas as suas substrings da 
    string original. Por exemplo, dado o separador ‘/’, 
    a string “/Fla/Flu/Bota/” será decomposta em:
        • Fla
        • Flu
        • Bota

    O protótipo da função é o seguinte: 

    char** stringSplit (const char *text, char separator, int *length);


    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio2

    compilacao:
    gcc matriz.c -o matriz

    Execucao: 
    ./matriz 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zero 0



int totalLimitador ( char strIn[], char limitador[] ) {

    int x, total = 0;
    int tamanho = strlen( strIn );

    //printf( "%d", strlen( texto2 ));
 

    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];


    for ( x = 0; x <= tamanho; x++ ) {

        asciStrIn = strIn[x];

        if (asciStrIn == asciLimite ) {

            total ++ ;
        }
    }

    //printf( " :: total limitadores: %d ::  ", total );

    return( total );
}



//int splitTexto( char strIn[], const char limitador ) {
int splitTextoBugouNaoUsar( char strIn[], char limitador[] ) {

    int tamanho = strlen( strIn );

    int x1, x2 = 0;

    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];

    char subString[] = "";

    
/*
    printf( "\n tamanho :: %d", tamanho);
    printf( "\n limitador :: %s", limitador);
    printf( "\n strIn :: %s", strIn);
    printf( "\n lim :: %d", asciLimite);
*/

    for (x1 = 0; x1 < tamanho; x1++) {

        asciStrIn = strIn[x1];

        //printf( "\n :: x1: %d :: ", x1 );
        printf( "\n strIn[%d]: %c =>  asciLimite: %d - asciStrIn: %d", x1, strIn[x1], asciLimite, asciStrIn  );


        // Avaliar se limitador foi encontrado
        if ( asciStrIn == asciLimite ) {

            // printf( "\n Avaliou limitador foi encontrado" );

            // montar array contendo a substr
            // retorno[x2] = subString;
            if ( x1 > 0 ) {

                //printf( "\n Avaliar x1 > 0 " );

                // Salvar a posicao na string
                // strcpy( retorno[x2], subString );

                x1++;
                x2++;


                //printf("%s", retorno[x2] ); 
                //printf("\n x1: %d :: substring: %s", x1, subString ); 

                // system( "pause > null ");
                

            }


        } else {
            // salva e incrementa a subString
            subString[x1] = strIn[x1];
            
            // printf( "\n x1: %d :: asciStrIn: %d :: ", x1, asciStrIn);
            //printf( "%c", strIn[x1] );

        }


        //printf( "\n ");
        //printf( "\n x1: %d :: x2: %d" , x1, x2);

    }


    return( 0 );
    
}



int splitTexto( char strIn[], char limitador[] ) {

    int x1, x2 = zero;
    int tamanho = strlen( strIn );

    int asciStrIn, asciLimite = zero; 

    asciLimite = limitador[zero];


    int total = totalLimitador( strIn, limitador );

    char * retorno[total][tamanho];


    for ( x1 = zero; x1 <= tamanho; x1++ ) {

        asciStrIn = strIn[x1];

        if (asciStrIn == asciLimite ) {

            // total ++ ;
            // salvar aonde foi encontrado o limitador
            if ( x1 >= 0) {

                // incrementa x1 para desprezar o limitador
                x1++ ; 
                x2++ ;

                printf( "\n" );
            }

        }

        // Recupero o byte e salva acumulando
        //retorno[x2][x1] += strIn[x1]; 

        printf( "%c", strIn[x1] );

    }

    printf( " :: total limitadores: %d ::  ", total );


    // 
    /*
    for ( x1 = 0; x1 < total; x1++) {

        printf( "\n retorno: %s", retorno[x1][tamanho] );
    }
    */

    return( total );
}









int main() {


    system("clear");
    printf("main() :: Split :: " );


    // 
    char texto[] = "/Fla/Flu/Bota/";
    
    // static char texto2[] = "/Fla/Flu/Bota/";

    int tamanho = strlen( texto );

    char limitador[] = "/";

    // Nr de vezes que aparece o limitador dentro da string texto
    int totalLimite = totalLimitador( texto, limitador );

    // printf( "%d", totalLimite); 

    // montar array para receber as sub strings encontradas
    // typeof ... record ... verificar o que 
    //char retorno[tamanho];
    //char * retorno[ totalLimite ];

    int x1 = 0;


    // splitTexto( texto, '/' );
    //splitTexto( texto, limitador );

    // Chamar funcao nova



/*
    // exibir retorno *** 3
    for (x1 = 0; x1 <= 3 ; x1++) {
        // printf( "\n :: retorno: %s :: x1: %d :: ", retorno[x1], x1);
        printf( "\n :: retorno: %s :: ", retorno[x1]);
    }
*/



    return(0);

    //system("pause > null");

}