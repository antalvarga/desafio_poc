/*
    AV 20210109
    Desafio muxi:

    Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em cada célula, 
    escreva um programa que verifique se esta matriz é uma solução válida para o 
    Sudoku (isto é, uma solução é válida no Sudoku se cada linha, cada coluna  e 
    cada bloco contém os números de 1 a 9 somente uma vez).

    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio2

    compilacao:
    gcc matrizQuadrada.c -o matriz

    Execucao: 
    ./matriz 

*/
#include <stdio.h>
#include <stdlib.h>

// #define Linhas 9
// #define Colunas 9

#define Linhas 3
#define Colunas 2


// recebe o vetor linha e inicia as colunas
void iniciarMatriz( int matriz[Colunas]) {
    int x;

    for ( x=0; x < Colunas; x++ ) {

        matriz[x] = x * Colunas;
    }
}


void exibirMatriz( int matriz[][Colunas] ) {

    int x, y;



    printf( "%d \n", matriz[0][0] );
    
    for ( x = 0; x < Linhas; x++ ) {
        
        for ( y = 0; y < Colunas; y++ ) {

            //printf( "\n exibirMatriz :: x: %d - y: %d :: ", x, y );

            // matriz[x][y] = 0;
            printf( "%d \n", matriz[x][y] );

        }
        
    }

}



int main() {

    /*

        5 3 4 | 6 7 8 | 9 1 2
        6 7 2 | 1 9 5 | 3 4 8
        1 9 8 | 3 4 2 | 5 6 7

        8 5 9 | 7 6 1 | 4 2 3
        4 2 6 | 8 5 3 | 7 9 1
        7 1 3 | 9 2 4 | 8 5 6

        9 6 1 | 5 3 7 | 2 8 4
        2 8 7 | 4 1 9 | 6 3 5
        3 4 5 | 2 8 6 | 1 7 9

    */

    int matriz4[Linhas] [Colunas] = {
        {1,2}
        , {3,4}
        , {5,6}
    } ;

    int x, y, z;


    system("clear");
    printf("main() :: Matriz Quadrada" );


    /*
    for ( x = 0; x < Linhas; x++) {

        // enviando o vetor linha y
        iniciarMatriz( matriz4[x] );

    }
    */


    // exibirMatriz( matriz4[Linhas] [Colunas -1] );
    // exibirMatriz( &matriz4[Linhas][Colunas] );
    exibirMatriz( matriz4 );


    return(0);
}
