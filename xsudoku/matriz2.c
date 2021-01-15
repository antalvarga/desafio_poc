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

#define numeroInicio 1
#define numeroFim 9




// Percorre todas as linhas (Y) da coluna recebida x
// E avalia se o numero recebido existe nestas linhas
void varrerLinhas( int matriz[][totalColunas], int x, int numero, int * lidos ) {

    int y;

    for ( y = 0; y < totalLinhas; y++) {

        //printf( "\n varrerLinhas :: %d", matriz[y][x] );
        // printf( "\n Avaliando  :: Linha: %d, coluna: %d", y, x );
        printf( "\n Avaliando  :: Linha: %d, coluna: %d :: matriz: %d, numero %d", y, x, matriz[y][x], numero );

        // avaliar se Numero existe na coluna de todas as linhas
        if ( matriz[y][x] == numero ) {
            
            lidos[ numero ]++;  
        } 

    }
}



int main() {

    // Despreza a posicao zero :: validos de 1 a 9
    int lidos[totalColunas +1] = {0, 0,0,0,0,0,0,0,0,0};

    

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


    int NrPesquisar, x, y, z;


    system("clear");
    printf("main() :: Matriz Quadrada" );



    // contador de 1 .. 9
    for ( NrPesquisar = numeroInicio; NrPesquisar <= numeroFim; NrPesquisar++) {

        printf( "\n " );
        printf( "\n Avaliar numero :: %d", NrPesquisar );

        // Avaliar todas as linhas (Y) recebendo x, a matriz e a coluna
        // Teste *** avaliar apenas uma coluna numeroInicio
        // for( x = 0; x < totalColunas; x++ ) {
        for( x = 0; x <=0 ; x++ ) {

            varrerLinhas( matrizSudoku, x, NrPesquisar, lidos );

        }


        // Avaliar todas colunas recebendo a matriz e x


        // Avaliar todos os quadrantes passando recebendo lidos, matriz,
        // eixoX e eixcoY

        
        
    }




    // OK => varrer 9 linhas => da coluna 1     
    // varrerLinhas( matrizSudoku, 1 );

    // OK => varrer 9 colunas => da linha 1 
    // varrerColunas( matrizSudoku[1] );

    // OK => varrer 3 linhas Y x 3 colunas x => 3 x 3
    // varrerQuadrante( lidos, matrizSudoku, 3, 3 ); // 761 / 853 / 924

    // OK => varrer 9 linhas Y x 9 colunas => 9 x 9 (toda matriz)
    // varrerMatriz( matrizSudoku );

    // Valido de 1 a 9
    for (x = 1; x < totalColunas +1; x++) {

        printf( "\n :: " );
        printf("\n :: Número: %d, lido %d vezes", x, lidos[x] );

    }

    return(0);
}

