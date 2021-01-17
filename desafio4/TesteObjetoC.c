/*
https://www.embarcados.com.br/objetos-em-linguagem-c/



gcc TesteObjetoC.c -o TesteObjetoC

./TesteObjetoC


*/


#include <stdio.h>
 
//classe do objeto
typedef struct {
    //parametros
    int Valor1;
    int Valor2;
    int Valor3;
 
    //metodos
    int (*ptrMetodo)(int,int,int);
}TClasse;
 
//prototypes
int MediaValores(int v1, int v2, int v3);
int FuncaoConstrutora(TClasse * ObjetoAlvo);
 
//funcao construtora
int FuncaoConstrutora(TClasse * ObjetoAlvo) {
        if(ObjetoAlvo == NULL)     
             return 0;
 
        ObjetoAlvo->Valor1 = 0;
    ObjetoAlvo->Valor2 = 0;
    ObjetoAlvo->Valor3 = 0;
    ObjetoAlvo->ptrMetodo = MediaValores;
        return 1;
}
 
//função a ser referenciada no ponteiro de funcao do metodo
int MediaValores(int v1, int v2, int v3) {
    return ((v1+v2+v3)/3);
}
 
 
//programa principal
int main(void) {
    TClasse Objeto;
    int Resultado;
 
    //chama funcao construtora
    if (FuncaoConstrutora(&Objeto) == 0)
            return 0;
 
    //popula objeto
    Objeto.Valor1 = 10;
    Objeto.Valor2 = 20;
    Objeto.Valor3 = 30;
    printf("\n\rValor 1 do objeto: %d\n", Objeto.Valor1);
    printf("\n\rValor 2 do objeto: %d\n", Objeto.Valor2);
    printf("\n\rValor 3 do objeto: %d\n", Objeto.Valor3);
 
    //chama metodo do objeto
    Resultado = Objeto.ptrMetodo(Objeto.Valor1, Objeto.Valor2, Objeto.Valor3);
    printf("\n\rResultado do metodo: %d\n\n", Resultado);
}