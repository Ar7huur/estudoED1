#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include"TADPilha.h"
#include "TADFila.h"
#define TAML 70


char Menu(void)
{
    system("cls");
    printf("### Menu de Opcoes ###\n");
    printf("[A] Formatador\n"); //ok
    printf("[B] Juntar Pilhas\n");
    printf("[C] Listagem de dados com arquivo texto\n");
    printf("[D] Relatorio da listagem de dados\n");
    printf("[ESC] Sair do Programa\n");
    printf("\nPressione a opcao desejada: ");
    return toupper(getche());
}

//======================================================= EX 1
void Insere (char linha[TAML], int &i, FILE *PtrN){
    fputs(linha,PtrN);
    for(int j=0; j<strlen(linha); j++)
        printf("%c",linha[j]);
    i=0;
    memset(linha,0,TAML);
}

void Formatador (char NomeArq[100]){
    char chr, linha[TAML];
    int i=0;

    FILE *PtrArq = fopen(NomeArq,"r");
    FILE *PtrN = fopen ("Formatado.txt","w");

    chr=fgetc(PtrArq);
    while(!feof(PtrArq)){
        switch(chr){

            case '@':
                chr=fgetc(PtrArq);
                while(chr!= ' '&& i<TAML-1){
                    linha[i]=chr;
                    i++;
                    chr=fgetc(PtrArq);
                }
                if(chr==' '&&i<TAML-1){
                    linha[i-1]=' ';
                    i--;
                }
                if(i==TAML-1){
                    printf("%d",i);
                    Insere(linha,i,PtrN);
                    printf("\nInseriu no @...\n");
                }
            break;
            case '/':
                while(chr!=10){
                    chr=fgetc(PtrArq);
                }
                if(chr==10){
                    memset(linha,0,TAML);
                }
                break;
            case '#':
                chr=fgetc(PtrArq);
                while(chr!=' '&&i<TAML-1){
                    linha[i]=chr;
                    i++;
                    chr=fgetc(PtrArq);
                }
                if(chr == ' ')
                    fputc('\n',PtrN);
                if(i==TAML-1){
                    Insere(linha,i,PtrN);
                    printf("\nInseriu no /....\n");
                }
                break;
            default:
                if(i==TAML-1){
                    Insere(linha,i,PtrN);
                    printf("Inseriu no DEFAULT \n");
                }
                linha[i]=chr;
                i++;
                chr=fgetc(PtrArq);

        }
    }
    getch();
    fclose(PtrN);
    fclose(PtrArq);
}
//==================================================================================


//=========================================EX2=======================================
void JuntarPilhas(void){
    TpPilha pilha1, pilha2, pilhaaux;
    int elem,i;

    inicializa(pilha1);
    for(int i; i<MAXP/2; i++){
        printf("\nInsira 5 numeros para a pilha 1..:");
        scanf("%d",&elem);
        insere(pilha1,elem);
    }
    inicializa(pilha2);
    for(int i; i<MAXP/2; i++){
        printf("\nInsira 5 numeros para a pilha de numero 2...: ");
        scanf("%d",&elem);
        insere(pilha2,elem);
    }
    inicializa(pilhaaux);
    while(!vazia(pilha2.topo))
        insere(pilhaaux,retira(pilha2));
    while(!vazia(pilhaaux.topo))
        insere(pilha1,retira(pilhaaux));
    getch();
}
//==================================================================================

//=========================================EX3=======================================

void ListandoDados (char NomeArq[100]){
    char desc[30];
    int qtde,cod;
    float preco;

    FILE *PtrArq = fopen (NomeArq,"a");
    printf("\n#### CADASTRANDO PRODUTOS ####\n");
    printf("Insira a descricao do produto...: ");
    fflush(stdin);
    gets(desc);

    while(strcmp(desc,"\0")!=0){
        printf("\nDigite o Codigo do produto..: ");
        scanf("%d",&cod);
        printf("\nDigite a qtde desse produto..: ");
        scanf("%d",&qtde);
        printf("\nDigite o preco desse produto.: ");
        scanf("%f",&preco);

        fprintf(PtrArq,"%c \t %d \t %d \t %.2f\n",desc,cod,qtde,preco);
        printf("Insira a descricao de outro produto...: ");
        fflush(stdin);
        gets(desc);
    }
fclose(PtrArq);

}

void RelatorioRecuDados(char NomeArq[100]){
    FILE *PtrArq = fopen(NomeArq,"r");
    if(PtrArq == NULL)
        printf("\nErro com o arquivo...\n");
    else{
        char desc[30];
        int qtde,cod;
        float preco;
        fscanf(PtrArq,"%c %d %d %.2f",&desc,&cod,&qtde,&preco);
        while(!feof(PtrArq)){
            printf("\n### BEM VINDO AO RELATORIO DE PRODUTOS ###\n");
            printf("\nCodigo: %d",cod);
            printf("\nDescricao do produto: %s",desc);
            printf("\nQuantidade do produto %s eh de: %d",desc,qtde);
            printf("\nPreco do produto %s eh de: R$ %.2f",desc,preco);
            fscanf(PtrArq,"%c %d %d %.2f",&desc,&cod,&qtde,&preco);
        }
        getch();
        fclose(PtrArq);
    }
}



//==================================================================================


//========================================EX5========================================
void Criptografia(char NomeArq[100]){
    FILE *PtrArq = fopen (NomeArq,"r");
    char chr;

    if (PtrArq == NULL)
        printf("\nErro com o Arquivo..\n");
    else{
        FILE *PtrN = fopen("Criptografado.txt","w");
        chr=fgetc(PtrArq);
        while(!feof(PtrArq)){
            fputc(chr+43,PtrN);
            chr=fgetc(PtrArq);
        }
        fclose(PtrN);
    }
    fclose(PtrArq);

}

void Descripto(char NomeArq[100]){
    FILE *PtrArq = fopen (NomeArq,"r");
    char chr;

    if(PtrArq == NULL)
        printf("\nErro com o arquivo..\n");
    else{
        FILE *PtrN = fopen("Descripto.txt","w");
        chr=fgetc(PtrArq);
        while(!feof(PtrArq)){
            fputc(chr-43,PtrN);
            chr=fgetc(PtrArq);
        }
        fclose(PtrN);

    }
    fclose(PtrArq);
}
//==================================================================================

void FilaProcessadores (void){
    TpFila f;
    int impre=3, gravaInterno=5, leitura=4, gravaExterno=8;
    int ut=2, tarefa,utTarefa=0;

    inicializa(f);

    do{
        if(ut%2==1){
            tarefa=rand()%4;
            switch(tarefa){
                case '0':
                    if(!cheia(f.fim)){
                        printf("\nInserindo uma IMPRESSAO: ");
                        insere(f,impre);
                        exibe(f);
                    }
                    break;
                case'1':
                    if(!cheia(f.fim)){
                        printf("\nInserindo uma GRAVACAO INTERNA: ");
                        insere(f,gravaInterno);
                        exibe(f);
                    }
                    break;
                case '2':
                    if(!cheia(f.fim)){
                        printf("\nInserindo uma LEITURA");
                        insere(f,leitura);
                        exibe(f);
                    }
                    break;
                case'3':
                    if(!cheia(f.fim)){
                        printf("\nInserindo uma GRAVACAO EXTERNA: ");
                        insere(f,gravaExterno);
                        exibe(f);
                    }
                    break;
            }
        }
        if(utTarefa%3==1 && !vazia(f.fim) && f.fila[0]==5){
            printf("\nRetirando uma IMPRESSAO da fila: ");
            retira(f);
            exibe(f);
        }
        if(utTarefa%5==1 && !vazia(f.fim) && f.fila[0]==5){
            printf("\nRetirando uma GRAVACAO INTERNA da fila: ");
            retira(f);
            exibe(f);
        }
        if(utTarefa%4==1 && !vazia(f.fim) && f.fila[0]==5){
            printf("\nRetirando uma LEITURA da fila: ");
            retira(f);
            exibe(f);
        }
        if(utTarefa%8==1 && !vazia(f.fim) && f.fila[0]==8){
            printf("\nRetirando uma GRAVACAO EXTERNA da fila: ");
            retira (f);
            exibe(f);
        }

        utTarefa++;
        ut++;

    }while(!kbhit());
    getch();


//return 0;

}
//==========================================================================
void CaixasTxtPilha (void){
    FILE *PtrArq = fopen("caixas.txt","r");
    char chr;
    int caixa;
    TpPilha p,pa,pb,pc; //pa=7 pb=5 pc=3
    inicializa(p);
    inicializa(pa);
    inicializa(pb);
    inicializa(pc);

    for (int i; i<MAXP; i++){
        printf("\nInsira as toneladas na ordem: 7 5 3..\n");
        scanf("%d",&caixa);
        insere(p,caixa);
    }
    while((chr=fgetc(PtrArq))!=EOF){
        switch(chr){
            case '3':
                if(!vazia(p.topo)){
                    caixa=retira(p);
                    printf("\nInserindo uma caixa de %d toneladas..",caixa);
                    insere(pc,caixa);
                }else{
                    printf("\nErro ao inserir, valor nao suportado..\n");
                }
                break;
            case '5':
                if(!vazia(p.topo)){
                    caixa=retira(p);
                    printf("\nInserindo uma caixa de %d toneladas..",caixa);
                    insere(pb,caixa);
                }else{
                    printf("\nErro ao inserir, valor nao suportado..\n");
                }
                break;
            case '7':
                if(!vazia(p.topo)){
                    caixa=retira(p);
                    printf("\nInserindo uma caixa de %d toneladas..",caixa);
                    insere(pa,caixa);
                }else{
                    printf("\nErro ao inserir, valor nao suportado");
                }
                break;
        }

    }

    printf("\nPalete C: ");
    exibe(pc);
    printf("\nPalete B: ");
    exibe(pb);
    printf("\nPalete A: ");
    exibe(pa);

    getch();

}

void Executa(void)
{
    char opcao;
    do
    {
        opcao = Menu();
        system("cls");

        switch(opcao)
        {
            case 'A': Formatador("teste.txt");
            break;
            case 'B': JuntarPilhas();
            break;
            case 'C': ListandoDados("ListDados.txt");
            break;
            case 'D': RelatorioRecuDados("ListDados.txt");
            break;
            case 'E': Criptografia("Cripto.txt");
            break;
            case 'F': Descripto("Criptografado.txt");
            break;
            case 'G': FilaProcessadores();
            break;
            case 'H': CaixasTxtPilha();
            break;
        }

    }while(opcao!=27);
}




int main(void) {
    Executa();
    return 0;
}
