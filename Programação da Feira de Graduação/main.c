#include <stdio.h>
#include <stdlib.h>
#include <string.h>







void quantCursos ();
void mostraCursos();
void escolheCurso();
void cadastro();
void ordenar_nomes(char [4][100], char auxi[100]);


int main(){
 int num;


    quantcursos(num);
    escolhecurso();
    cadastro();
    return 0;
}

void quantcursos(){
int qt;

printf("Digite a quantidade de cursos que participarao do evento: ");
fflush(stdin);
scanf("%d",& qt);
}
void mostraCursos(){

 printf("[1]Engenharia Civil\n");
 printf("[2]Engenharia de Computa��o\n");
 printf("[3]Engenharia de Alimentos\n");
 printf("[4]Licenciatura em Matem�tica\n");
 printf("[5]Lic. e Bacharelado em F�sica\n");
 printf("[6]Licenciatura em Qu�mica \n");
 printf("[7]Administra��o \n");
 printf("[8]Ci�ncias Cont�beis")
 printf("[9]Ci�ncias Econ�micas\n ");
 printf("[10]Lic. e Bacharelado em Filosofia\n ");
 printf("[11]Licenciatura em Hist�ria\n ");
 printf("[12]Lic. e Bacharelado em Geografia\n ");
 printf("[13]Licenciatura em Pedagogia\n ");
 printf("[14]Direito\n ");
 printf("[15]Psicologia\n ");
 printf("[16]Licenciatura em Letras Vern�culas\n");
 printf("[17]Licenciatura em Letras c/ Ingl�s\n ");
 printf("[18]Licenciatura em Letras c/ Franc�s\n ");
 printf("[19]Licenciatura em Letras c/ Espanhol\n ");
 printf("[20]Licenciatura em M�sica\n ");
 printf("[21]Licenciatura em Ci�ncias Biol�gicas\n   ");
 printf("[22]Bacharelado em Ci�ncias Biol�gicas\n   ");
 printf("[23]Licenciatura em Educa��o F�sica \n ");
 printf("[24]Enfermagem\n ");
 printf("[25]Odontologia\n  ");
 printf("[26]Medicina\n  ");
 printf("[27]Farm�cia \n ");
 printf("[28]Agronomia\n");

}




void escolhecurso(){

    int opcao,cursos[30];

 printf("Digite o numero correspondente do curso que deseja cadastrar proposta:\n");

 fflush(stdin);
 scanf("%d",& opcao);
 switch(opcao);

   case 1:strcpy(cursos, "Engenharia Civil\0");
   break;
   case 2:strcpy(cursos, "Engenharia de Computa��o\0");
   break;
   case 3:strcpy(cursos, "Engenharia de alimentos\0");
   break;
   case 4:strcpy(cursos, "Licenciatura em Matem�tica\0");
   break;
   case 5:strcpy(cursos, "Lic. e Bacharelado em F�sica\0");
   break;
   case 6:strcpy(cursos, "Licenciatura em Qu�mica\0" );
   break;
   case 7:strcpy(cursos, "Administra��o\0" );
   break;
   case 8:strcpy(cursos, "Ci�ncias Econ�micas\0" );
   break;
   case 9:strcpy(cursos,)

}


//};
void ordenar_nome(char nome[4][100], char auxi[100]){
	 int i=0,j=0;
	for ( i = 0; i < 3 ; i ++ ){
        for( j = i + 1; j < 4; j ++ ){
            if(strcmp( nome[i], nome[j] ) > 0 ){
                    strcpy(auxi,nome[i]);
                    strcpy(nome[i],nome[j]);
                    strcpy(nome[j],auxi);
            }
        }
    }
}

