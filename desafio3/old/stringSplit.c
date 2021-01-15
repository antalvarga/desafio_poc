/*

    AV 20210112
    Desafio muxi:


    > 3. Escreva uma função que dada uma string composta por substrings 
    separadas por um dado caractere, retorne todas as suas substrings da 
    string original. Por exemplo, dado o separador ‘/’, 
    a string “/Fla/Flu/Bota/” será decomposta em:
        • Fla
        • Flu
        • Bota

    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio3

    compilacao:
    gcc substr.c -o substr

    Execucao: 
    ./substr

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define zero 0



int totalLimitador ( char strIn[], char limitador[] ) {

    int x, total = 0;
    int tamanho = strlen( strIn );


    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];


    for ( x = 0; x <= tamanho; x++ ) {

        asciStrIn = strIn[x];

        if (asciStrIn == asciLimite ) {

            total ++ ;
        }
    }

    return( total );
}



int totalLimitador2( const char * text, char separator ) {


    int x1, retorno = zero;
    
    int tamanho = strlen( text );

    int asciStrIn, asciLimite = zero;

    asciLimite = separator;


    // printf( "\n stringSplit :: length: %d", tamanho );
    // printf( "\n separator :: length: %c", separator );


    for ( x1 = zero; x1 <= tamanho; x1++ ) {

        asciStrIn = text[x1];

        if (asciStrIn == asciLimite) {
            
            retorno ++ ;
        }
    }

    return(retorno);
}



char ** stringSplit( const char * text, char separator, int *length) {

    int x1, x2 = zero;

    char ** retorno = 0;


    // para evitar bug no casting
    int tamanho = *(length);

    //char * novoTexto = *(text);

    char * novoTexto;

    strcpy(novoTexto, text);


    //char * novoLimitador = &(separator);

    




    //int asciStrIn, asciLimite = zero;

    //asciLimite = separator;
    
    // count
    //int total = totalLimitador2( text, asciLimite );

    char * subString;

    // char * strtok( char * endereçoStrOrigem, char * endereçoStrDelimitador);
    // char * subString = strtok( "/Fla/Flu/Bota/", "/" );
    // char * subString = strtok( novoTexto, "/" );
    
    //subString = strtok( novoTexto, novoLimitador );

    subString = strtok( "/Fla/Flu/Bota/", "/" );

    //retorno = malloc( sizeof( char *) * total );

    // printf( "\n stringSplit :: length: %d", tamanho );
    // printf( "\n separator :: length: %c", separator );

    //printf( " subString %s", subString );

    while ( subString ) {

        // incrementa vetor de retorno
        //*(retorno + x1++ ) = subString;

        x1++ ; 

        //printf( " subString %s", subString );


        // 
        subString = strtok( zero, "/" ); 

    }

    //*(retorno + x1) = 0;






    return(retorno);

}



int main() {


    system("clear");
    printf("main() :: Split :: " );
 


    char texto[] = "/Fla/Flu/Bota/";
    
    int tamanho = strlen( texto );

    char limitador[] = "/";


    int x1 = zero;

    char ** subStrings;
    
    subStrings = stringSplit( texto, '/', &tamanho) ;

    if (subStrings) {

        printf("\n :: subStrings :: ");

        for ( x1 = zero; x1 < tamanho; x1++ ) {

            //                 *(subsString + 1) 
            printf("\n :: %s", subStrings[x1] );
        }

        free(subStrings);
    }


    return(0);
}