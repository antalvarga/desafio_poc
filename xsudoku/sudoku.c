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

#define totalLinhas 9
#define totalColunas 9


// OK => recebe o vetor linha Y e percorrer as colunas X
void varrerColunas( int matriz[totalColunas] ) {
    int x;

    for ( x=0; x < totalColunas; x++ ) {

        //matriz[x] = x * x;
        printf( "\n Percorrer colunas :: %d", matriz[x] );
        
    }
}

// OK => receber o vetor coluna e percorre todas as linhas (Y)
void varrerLinhas( int matriz[][totalColunas], int x ) {

    int y;

    for ( y = 0; y < totalLinhas; y++) {

        printf( "\n varrerLinhas :: %d", matriz[y][x] );
    }
}

// OK =>
void varrerQuadrante( int * lidos, int matriz[][totalColunas], int eixoX, int eixoY ) {

    int x, y;

    for ( y = eixoY; y < eixoY +3; y++ ) {

        for ( x = eixoX; x < eixoX +3; x++) {
            
            printf( "\n varrerLinhas :: y: %d - x: %d :: matriz %d", y, x, matriz[y][x] );

            ++lidos[ matriz[y][x] ];
        }
    }

}

// OK => 
void varrerMatriz( int matriz[][totalColunas] ) {

    int x, y;

    printf( "%d \n", matriz[0][0] );
    
    for ( x = 0; x < totalLinhas; x++ ) {
        
        for ( y = 0; y < totalColunas; y++ ) {

            printf( "%d \n", matriz[x][y] );

        }        
    }
}



int main() {

    // Despreza a posicao zero :: validos de 1 a 9
    int lidos[totalColunas +1] = {0,0,0,0,0,0,0,0,0, 0};

    int matrizSudoku[totalLinhas][totalColunas] = {
          {5, 3, 4, 6, 7, 8, 9, 1, 2}
        , {6, 7, 2, 1, 9, 5, 3, 4, 8}
        , {1, 9, 8, 3, 4, 2, 5, 6, 7}

        , {8, 5, 9, 7, 6, 1, 4, 2, 3}
        , {4, 2, 6, 8, 5, 3, 7, 9, 1}
        , {7, 1, 3, 9, 2, 4, 8, 5, 6}

        , {9, 6, 1, 5, 3, 7, 2, 8, 4}
        , {2, 8, 7, 4, 1, 9, 6, 3, 5}
        , {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };


    int x, y, z;


    system("clear");
    printf("main() :: Matriz Quadrada" );



    // OK => varrer 9 linhas => da coluna 1     
    // varrerLinhas( matrizSudoku, 1 );

    // OK => varrer 9 colunas => da linha 1 
    // varrerColunas( matrizSudoku[1] );

    // OK => varrer 3 linhas Y x 3 colunas x => 3 x 3
    varrerQuadrante( lidos, matrizSudoku, 3, 3 ); // 761 / 853 / 924

    // OK => varrer 9 linhas Y x 9 colunas => 9 x 9 (toda matriz)
    // varrerMatriz( matrizSudoku );

    // Valido de 1 a 9
    for (x = 1; x < totalColunas +1; x++) {

        printf("\n :: Número: %d, lido %d vezes", x, lidos[x] );

    }

    return(0);
}
