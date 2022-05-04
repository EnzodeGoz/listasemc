#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct molde 
{
    int codigo;
    int quantidade;
    float preco;
    struct molde * prox;
} *ptrproduto;
typedef struct molde Mol;
int n, *ptrn = 0;

int print_menu(){
    printf ("Escolha uma das opções do menu abaixo:\n");
    printf("1) Inserir itens\n2) Exibir lista de itens\n3) Pesquisar itens\n4) Remover itens\n5) Sair\n>");
    return 0;
}
Mol* criar(){
    Mol *novMol = (Mol*)malloc(sizeof(Mol));
    return novMol;
}
Mol* inseririnicio(Mol*ptrproduto){
    Mol*novomol = criar();
    printf("Insira o código do produto:\n>");
    scanf("%i",&novomol->codigo);
    printf("Insira a quantidade do produto:\n>");
    scanf("%i", &novomol->quantidade);
    printf("Insira o preço do produto:\n>");
    scanf("%i", &novomol->preco);
    if(ptrproduto == NULL){
        ptrproduto = novomol;
        novomol->prox=NULL;
    }
    else{
        novomol->prox=ptrproduto;
        ptrproduto=novomol;
    }
    return ptrproduto;
    
}

int inserirmeio(){
    return 0;
}

int inserirfim(){
    return 0;
}

void exibir_lista(Mol* ptrproduto){
    Mol *printmol = ptrproduto;
    while(printmol != NULL){
        printf("\nCódigo: %i\nQuantidade: %i\nPreço: %.2f", printmol->codigo, printmol->quantidade, printmol->preco);
        printmol = printmol->prox;
    }
}

int pesquisar(){
    return 0;
}

int remover(){
    return 0;
}

int main(){
    ptrproduto = NULL;
    ptrproduto = (Mol *) malloc(sizeof(Mol));
    printf("Olá! Bem vindo ao programa de Listas Sequenciais.\n");
    for(int menu = 0; menu != 5; menu = menu){
        print_menu();
        scanf("%i", &menu);
        switch(menu){
            case 1:
            int pos;
                printf("Deseja inserir um elemento em que posição da lista?\n");
                printf("1) Inicio\n2) Meio\n3) Final\n4) Sair\n>");
                printf("%i", &pos);
                switch(pos){
                    case 1:
                        inseririnicio(ptrproduto);
                    break;
                    case 2:
                        inserirmeio();
                    break;
                    case 3:
                        inserirfim();
                    break;
                    case 4:
                    PRINTF("Sair foi escolhido.\n");
                    break;
                    default:
                    printf("Comando inválido. Insira um escolha válida.\n");

                }
            break;
            case 2:
                printf("Essa é a atual lista de itens:\n");
                exibir_lista(ptrproduto);
            break;
            case 3:
                pesquisar();
            break;
            case 4:               
                remover();
            break;
            case 5:
                printf("Sair for escolhido.");
            break;
            default:
                printf("\nComando inválido.\nInsira uma escolha válida.\n\n");
        }
    }
    return 0;
}