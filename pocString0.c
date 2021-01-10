#include <stdio.h>
#include <stdlib.h>

#include <string.h>



/*
https://under-linux.org/showthread.php?t=57721
acho q issu resolve 

// devolve o vetor str em UPPERCASE
int str_upper(char str[bufcmd])
{
char aux[bufcmd];
int i;
for(i=0;i<strlen(str);i++)
{
aux[i]=toupper(str[i]);
} 
return(str_trim(aux,i));
}
*/


const char * myFunction2() {
    printf("\nmyFunction2 :: ");
    return ("\nmyFunction2 :: ");
    //char array[] = "my string";

    // return( array[40] );

}

// const char * myFunction3() {
const char * myFunction3( char * param1) {
    printf("\nmyFunction3 :: ");

    // return( "myFunction3" );
    // return( "myFunction3" );
    return( param1 );
}



const char * myFunction4( char * param1) {
    printf("\nmyFunction4 :: ");

    int i;
    char * teste;
    
    // retirar
    teste = param1;

    char * retorno;

    for ( i = strlen( param1 ) -1; i >= 0; i-- ){

        // c = putchar( original[i] ); 

        if( param1[i] != '\n' ){

            //retorno[i] = param1[i];

            printf( "\n myFunction4 :: estou no for :: %c", param1[i] );

        }
    }

    return( teste );
}




//char * myFunction( char original[40]) {
int myFunction( char *original) {
    printf("\nmyFunction :: ");

    int i;
    char aux[40];
    char c;
    char texto[40] = "";

    const char * sSomeString = myFunction3("ipan");

    printf("\n Retornando da myFunction3 :: %s", sSomeString);


    // 
    
    for ( i = strlen(original) -1; i >= 0; i-- ){

        // c = putchar( original[i] ); 

        if( original[i] != '\n' ){

            // aux[i] = original[i];
            aux[i] = original[i];

            //printf( "\nestou no for :: %c", original[i] );
            c = c + aux[i];
            //texto = strncpy( aux[i] );

            printf( "\nestou no for :: %c", aux[i] );

        }
    }

    printf( "\nsaiu do primeiro for" );

    //printf( "Valor da variavel c = %s", c );

    //printf( "%c", aux[i] );
    
    

    printf( "%s", myFunction2() );




    
    // return(c);
    return( 0);
}


int main () {

    char palavra[40];
    //char * nova;
    //char * retorno;

    //clrscr();
    system("clear");
    printf("\n main() :: \n ");


    printf( "Digite: ");
    fgets( palavra, 46, stdin);

    // printf("%s", palavra);

    
    // nova = palavra;

    // printf("/n%s", nova);


    // retorno ok
    //myFunction( palavra );



    const char * nova = myFunction4( palavra );




    // free(nova);

    printf("\n main :: nova %s", nova );






    return(0);
        
}

