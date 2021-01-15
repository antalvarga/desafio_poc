// http://www.br-c.org/doku.php?id=strtok&s[]=strtok

/* strtok.c */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
    // meuSplit
   char *psRetorno;

   // text
   char sFrase[]="/Fla/Flu/Bota/";

    // retorno
   char** retorno = 0;

    // x
    size_t idx = 0;

    int x1 = 0;

    system( "clear") ;
 
   printf("\nFrase = %s", sFrase);
 
   /* Primeira pesquisa por / . */
   psRetorno = strtok(sFrase, "/");
 
   printf("\nRetorno = %s", psRetorno);
   //printf("\nFrase = %s", sFrase);
 

    // pegar o totalLimitador
    int totalLimitador = 4;

    retorno = malloc( sizeof( char *) * totalLimitador );

    if ( retorno ) {

        printf( "alocou" );
    } else {

        printf( "*** bugou *** " );
    }



   printf("\n vai fazer o do ");

   do
   {



      /* Um valor nulo (NULL) é considerado sempre falso em comparações 
         booleanas (verdadeiro ou falso). 
      */
      if(psRetorno)
      {
         // printf("\nRetorno = %s", psRetorno);

        // ***    psRetorno    não preenchido     ***

        // result ou retorno
        printf( "\n:: *** ::" );
        printf( "\n:: result ou retorno + idx  ::" );
        printf( "\n:: *** ::" );

        *(retorno + idx++ ) = strdup( psRetorno );

        x1++;

      } 

        printf("\n vai fazer o psRetorno = strtok  ");

      /* Nas próximas chamadas, deve-se passar um ponteiro “nulo”. 
         Isto “indica” para a função que a pesquisa deve continuar 
         no ponteiro anterior. 
      */ //  --> Demais pesquisas por ,  /


        // *** não deu erro de compilaçao/execucao mas retorno null ***
        // psRetorno = strtok("\0", "/");    
 
        // *** Deu erro de compilaçao ***
        //psRetorno = strtok("\0", '/');

        // funcionou 
        psRetorno = strtok( 0, "/"); 





   } while(psRetorno);

    printf( "\n:: saiu do while :: " );




    int x = idx;
    
    printf( "\n:: vai incrementar retorno :: " );
    printf( "\n:: x = %d :: ", x );
    printf( "\n:: x1 = %d :: ", x1 );
    



    
    *(retorno + idx) = 0;

    int xpto = 0;

    printf( "\n" );
    printf( "\n:: resultado ::" );
    printf( "\n" );


    if (retorno ) {

        for (xpto = 0; *( retorno + xpto) ; xpto++ ) {

            printf( "\n %s", *(retorno +xpto) );

            free( *(retorno +xpto) );

        }
    }


    free( retorno );

    




   return 0;
}