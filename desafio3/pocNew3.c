/*

    AV 20210111
    AV 20210113: Refazendo para contemplar o protótipo

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



/*

    Retornar o total de ocorrencia em uma string

*/
int totalLimitador ( char strIn[], char limitador[] ) {

    int x, total = 0;
    int tamanho = strlen( strIn );

    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];


    printf( "\n :: strIn :: %s", strIn);
    printf( "\n :: limitador :: %s", limitador);


    for ( x = 0; x <= tamanho; x++ ) {

        asciStrIn = strIn[x];

        if (asciStrIn == asciLimite ) {

            total ++ ;
        }
    }

    return( total );
}




char ** stringSplit( const char * text, char separator, int *length) {

    
    printf( "\n stringSplit :: text: %s", text );
    printf( "\n stringSplit :: separator: %c", separator );
    printf( "\n stringSplit :: length: %d", *(length) );



    // 
    int x = 0;

    // retorno
    char ** retorno;

    // 
    char * meuSplit;




    // para evitar bug no casting/strtok
    int tamanho = *(length);


    // trabalhando os castings
    // 1@ limitador         ***     OK
    // 2@ texto             *** 
    // totalLimitador       ***     OK



    // TODO: Converter const char * <variavel> para char[] <variavel>
    // char ** stringSplit( const char * text, char separator, int *length) 
    // char novoTexto[] = "/Fla/Flu/Bota/";   // *** assim funcionou ***

    //const char novoTexto2 = *(text);
    //const char novoTexto2 = *(text);
    //char novoTexto2;
    //const char novoTexto2 = (char) * text;   // = *text;
    //strcpy(novoTexto2, &text ) ;
    // sprintf( novoTexto2, text );
    //char novoTexto2 = (char *)text;
    //char novoTexto2;

    //
    // printf( "\n\n :: novoTexto2 ::   %c", novoTexto2 );
    
    /*
    char * novoTexto2 = (char * )text;
    printf( "\n\n :: novoTexto2 ::   %s", novoTexto2 );


    int xxx = totalLimitador( novoTexto2, &separator);
    printf( "\n\n :: xxx ::   %d", xxx );

    meuSplit = strtok( novoTexto2, &separator);
    printf( "\n %s", meuSplit );

    */
   char * novoTexto = (char *)text;
        






    // TODO: Converter char para char *
    // char * novoLimitador = "/";   *** assim funcionou  ***
    //strcpy( novoLimitador, separator ); 

    //char * novoLimitador;
    //novoLimitador = &separator;  //  *** funcionou ***
    char * novoLimitador = &separator;   // *** funcionou ***



    // trabalhando os castings
    // pegar o totalLimitador   ***
    //int total = 4; // totalLimitador( novoTexto, novoLimitador);
    // int total = totalLimitador( novoTexto, novoLimitador);
    int total = totalLimitador( novoTexto, novoLimitador);



    //meuSplit = strtok( text, novoLimitador) ;
    //meuSplit = strtok( novoTexto, separator) ;
    meuSplit = strtok( novoTexto, novoLimitador) ;

    // printf( "\n %s", meuSplit );
    // printf( "\n  :: totalLimitador :: %d", total );


    // Alocar memoria
    retorno = malloc( sizeof( char *) * total );

    do {

        if ( meuSplit ) {
            *( retorno + x++ ) = strdup( meuSplit );

        }

        // TODO: trocar limitador  ***
        // meuSplit = strtok( 0, "/" );   *** funfou ***
        meuSplit = strtok( 0, novoLimitador );

    } while ( meuSplit );

    return( retorno );

}





int main() {




    system("clear");
    printf("main() :: Split :: " );




    // 
    char texto[] = "/Fla/Flu/Bota/";
    
    //static char texto2[] = "/Fla/Flu/Bota/";

    int tamanho = strlen( texto );

    // trabalhando os castings
    // char limitador[] = "/";
    char limitador = '/';


    // Nr de vezes que aparece o limitador dentro da string texto
    // int totalLimite = totalLimitador( texto, limitador );
    // ** acho que sera usada na funcao

    int x1 = zero;

    char ** subStrings;


    // trabalhando os castings
    // subStrings = stringSplit( texto, '/', &tamanho );
    subStrings = stringSplit( texto, limitador, &tamanho );




    if ( subStrings ) {
        
        for ( x1 = zero; *( subStrings + x1); x1++ ) {

            printf( "\n %s", *(subStrings + x1 ));

            free( *(subStrings + x1) );
        }

    }

    free( subStrings );
    
    return(0);

}