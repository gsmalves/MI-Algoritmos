/*******************************************************************************
Autor: Gustavo dos Santos Menezes Alves
Componente Curricular: Algoritmos I
Concluido em: 30/12/2017
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
#include <stdio.h>//Biblioteca de entrada e sa�da.//
#include <stdlib.h>//Biblioteca que funciona como prompt de comando do sistema operacional utilizado.//
#include <locale.h>//Biblioteca utilizada para poder acentuar as palavras em portugu�s. //
#include <string.h>//Biblioteca que cont�m uma s�rie de fun��es para manipular strings.//
struct cel//Estrutura para lista encadeada, que salva as palavras de determinado arquivo,a quantidade de vezes e o nome do arquvo//
{
    char palavra[100];
    int quantidade;
    char nomearquivo[50];
    struct cel *prox;// ponteiro para o proximo elemento da lista//

};
typedef struct cel celula;
// os prototipos (esbo�o) da fun��o.
void ajuda();
void listaInvertida(celula *inicio);
void adicionarArq(int argumentos, char *comandos[]);
int Vazia(celula *lista);
void procuraNalista(celula *lista,FILE *leitura);
void Buscarpalavra(celula *lista,char palavra_chave[]);
void pesquisar(int argumentos, char *comandos[],FILE *leitura,celula *lista);

int main(int argc, char *argv[])// composta por argumento de linha de comando .//
{
	setlocale(LC_ALL, "Portuguese");
    FILE *leitura;
    celula *lista = (celula*) calloc(1, sizeof(celula)); // Fun��o calloc para aloca��o da lista.//
    //Condicionais abaixo, serve como um tratamento de erro, caso usu�rio, n�o digite corretamente os argumentos.//
    if (argc==1)
        ajuda();
    else if (strcmp(argv[1], "adicionar") != 0 && strcmp(argv[1], "pesquisar") != 0)
        ajuda();
    else if(strcmp(argv[1],"adicionar")==0)
    {
        adicionarArq(argc, argv);

    }

    else if(strcmp(argv[1],"pesquisar")==0)
    {
        pesquisar(argc,argv,leitura,lista);
    }
    else{
        ajuda();
    }
}
void listaInvertida(celula *inicio)//Fun��o que cria o arquivo.txt de persist�ncia(Lista invertida)//
{
    FILE *arqEscreve;
    arqEscreve=fopen("ListaInvertida.txt","a");//Modo abertura "a", para escrever abaixo do que j� existe ou criar um arquivo, se n�o existir//
    celula *aux2=inicio;
    while( aux2!=NULL)
    {
        fprintf(arqEscreve,"%s %d %s\n", aux2->palavra, aux2->quantidade,aux2->nomearquivo);
        aux2= aux2->prox;
    }

    fclose(arqEscreve);


}

void ajuda()//Fun��o para ajudar o usu�rio, caso o mesmo escreva algum argumento errado.//
{
    printf("Digite um dos comandos abaixo:\n");
    printf("programa.exe adicionar nomeArquivo(sem.txt)\n");
    printf("programa.exe pesquisar palavra-chave");

}

void adicionarArq(int argumentos, char *comandos[])//Fun��o que faz a leitura do arquivo inserido e salva na lista encadeada//
{

    FILE *arqLer;
    celula *inicio=NULL, *aux=NULL, *aux2=NULL;
    char palavraArq[50];
    char palavraTratada[50];
    char nomearq[100];

    strcpy(nomearq,comandos[2]);//Passando o nome do arquivo digitado na linha de argumento para uma vari�vel//
    strcat(nomearq,".txt");//Concatenando o .txt no nome do arquivo//
    arqLer = fopen(nomearq, "r");
    //testando se o arquivo foi realmente criado//
    if (arqLer == NULL)  // Se houve erro na abertura//
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    else
    {

        while(!feof(arqLer))
        {

            fscanf(arqLer, "%s", palavraArq);
            strcpy(palavraTratada,strtok(palavraArq,".,(){};:?!"));// tratamento de erro para pontua��o//
            if(inicio == NULL)//Se a lista estiver vazia, insere os dados nela//
            {
                inicio = (celula *) malloc(sizeof(celula));
                strcpy(inicio->palavra, palavraTratada);
                strcpy(inicio->nomearquivo,nomearq);
                inicio->quantidade=0;// Vari�vel inicialmente como 0, posteriormente se�ra incrementada//

                inicio->prox = NULL;
            }
            aux2=inicio;
            while(aux2!=NULL)//Percorre a lista at� o final//
            {
                if(strcasecmp(palavraTratada,aux2->palavra)==0) //Se existir palavras iguais//
                {
                    aux2->quantidade++;//A vari�vel � incrementada//
                    strcpy(palavraTratada,"");
                    break;
                }
                if(aux2->prox==NULL && strcmp(palavraTratada,"")!=0)// Se percorrer toda lista e n�o achar palavra igual, ent�o a vari�vel quantidade recebe 1, de apenas uma vez.//
                {
                    aux= inicio;
                    inicio= (celula*)malloc(sizeof(celula));
                    inicio->quantidade= 1;
                    strcpy(inicio->palavra, palavraTratada);
                    strcpy(inicio->nomearquivo,nomearq);
                    inicio->prox= aux;
                    strcpy(palavraTratada,"");
                }
                aux2=aux2->prox;
            }
        }

        fclose(arqLer);
        printf("Arquivo inserido de maneira correta! Evite inserir novamente!");
    }
    listaInvertida(inicio);//Chamada da fun��o que cria a Lista invertida.//


}
int Vazia(celula *lista) // Fun��o que verifica a condi��o da lista, se tem algum elemento ou est� vazia//
{
    if(lista->prox == NULL)
        return 1;
    else
        return 0;
}

void procuraNalista(celula *lista,FILE *leitura) // Fun��o que pega as palavras do arquivo ListaInvertida e adiciona na lista encadeada.//
{
    celula *novo=(celula*) malloc(sizeof(celula)); // Aloca��o utilizada malloc

    fscanf(leitura, "%s %d %s \n", novo->palavra, &novo->quantidade, novo->nomearquivo);

    novo->prox = NULL;

    if(Vazia(lista))
        lista->prox=novo;
    else                            // Caso a celula n�o seja vazia, ser� adicionado a lista//
    {
        celula *aux = lista->prox;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }
}


void Buscarpalavra(celula *lista,char palavra_chave[])
{

    celula *aux;
    aux = lista->prox;

    while(aux != NULL) // Percorre a lista e printa a palavra, sua quantidade de repeti��es e nome do arquivo, caso exista!//
    {

        if(!strcasecmp(aux->palavra, palavra_chave)) // Fun��o strcasecmp para comparar a palavra digitada pelo usuario, com a existente a lista encadeada//
        {
            printf( "Palavra: %-4s ", aux->palavra);
            printf( " ||  Quantidade: %-4d", aux->quantidade);
            printf( "|| %-4s\n",aux->nomearquivo);

        }
        aux = aux->prox;

    }

    printf("\n\n");

}
void pesquisar(int argumentos, char *comandos[],FILE *leitura,celula *lista)//Fun��o que faz a pesquisa da palavra solicitada pelo usu�rio.//
{
    char palavra_chave[50];
    strcpy(palavra_chave,comandos[2]);//Transfere a palavra digitada na linha de comando para a vari�vel.//
    leitura=fopen("ListaInvertida.txt","r");
    if (leitura == NULL)  // Se houve erro na abertura, printa a mensagem a seguir.//
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    else
    {

        do
        {
            procuraNalista(lista,leitura);//Chamada da fun��o que pega as informa��es da lista invertida e salva na lista encadeada.//
        }
        while(!feof(leitura));

        Buscarpalavra(lista,palavra_chave);//Chamada da fun��o de buscar a palavra solicitada.//

    }


    fclose(leitura);


}
