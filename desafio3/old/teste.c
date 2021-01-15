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



int splitTexto( char strIn[], char limitador[] ) {
//int splitTexto( char strIn[], const char limitador ) {

    int tamanho = strlen( strIn );

    int x1, x2 = 0;

    char retorno[] = "";

    for ( x1 = 0; x1 <= tamanho; x1++ ) {

        printf( "%c" , strIn[x1]); 

        for ( x2 = x1; x2 <= tamanho; x2++ ) {

            retorno[x2] = strIn[x2];



            // *** erro *** 
            /*
            if ( strIn[x2] == limitador ) {

                //printf( "%s", retorno );
                break;

            }
            */
            
        }



    }

    return(0);
}


// https://pt.stackoverflow.com/questions/190755/como-separar-uma-string-em-pedaços
int main() {

    // char texto = "/Fla/Flu/Bota/";
    char texto[] = "/Fla/Flu/Bota/";

    char limitador[] = "/";

    // splitTexto( texto, '/' );
    splitTexto( texto, limitador );

    return(0);

    //system("pause > null");

}