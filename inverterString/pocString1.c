#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void myFunction4( char original[], char novaPar[] ) {

    printf("\nmyFunction4 :: ");

    int i, x;


    // for ( i = original[i] != '\0'; i >= 0; i-- ){
    x = strlen( original ) -1;

    for ( i = strlen( original ) -1; i >= 0; i-- ){
    
        if( original[i] == '\n' || original[i] == '\0') {

            printf( "\n myFunction4 :: estou no for :: ENTER" );

        } else {

            novaPar[x -i] = original[i];

            //printf( "\n myFunction4 :: estou no for :: original %c", original[i] );
            //printf( "\n myFunction4 :: estou no for :: nova %c", novaPar[x -i] );

        }

    }


    //novaPar[x+1] = '\0';
    x = strlen( novaPar);


    printf( "\n " );
    printf( "\n (novo x) %d", x  );
    printf( "\n " );



    for ( i=0; i <= x; i++) {

        //printf( "\n registro i: %d", i );
        printf( "\n main :: novaPar %c", novaPar[i] );
        // printf( "\n registro i: %s", i );
    }





    //printf( "\n myFunction4 :: saí do for :: nova %c", nova[i] );

}




int main () {

    char palavra[40];
    char nova[40];

    int i;
    
    system("clear");
    //printf("\n main() :: \n ");


    printf( "Digite: ");
    fgets( palavra, 40, stdin);

    myFunction4( palavra, nova );


    //printf("\n main :: nova %s", nova );

    return(0);
        
}

