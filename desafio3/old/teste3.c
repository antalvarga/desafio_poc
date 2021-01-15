// https://qastack.com.br/programming/9210528/split-string-with-delimiters-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>




char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;




    printf( "\n :: a_str %s :: ", a_str );
    printf( "\n :: tmp %s :: ", tmp );


    // totalLimitador2
    /* Count how many elements will be extracted. */
    while (*tmp)
    {

        printf( "\n :: *tmp %c :: ", (*tmp) );



        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;

            //printf( "\n :: last_comma %s :: ", last_comma );

        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);


    //int * x6 = &count;

   // printf( "\n :: count %d :: ",  x6 );



    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        printf( "\n :: token :: %s", token);


        while (token)
        {

            // if n < totalLimitador 
            assert(idx < count);
              
            *(result + idx++) = strdup(token);

            token = strtok(0, delim);


            printf( "\n while :: token :: %s", token);

        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int main()
{
    char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    //char months[] = "/Fla/Flu/Bota/";
    char** tokens;   // subsString

    //printf("months=[%s]\n\n", months);

    tokens = str_split(months, ',');
    //tokens = str_split(months, '/');

    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("\n month=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}