#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct molde
{
    int codigo;
    int quantidade;
    float preco;
    struct molde * prox;
}produto, *ptrproduto;

int n, *ptrn = 0;

int print_menu(){
    printf ("Escolha uma das opções do menu abaixo:\n");
    printf("1) Inserir itens\n2) Exibir lista de itens\n3) Pesquisar itens\n4) Remover itens\n5) Sair\n>");
    return 0;
}
int inseririnicio(){
    printf("Insira o código do produto:\n>");
    scanf("%i",&ptrproduto->codigo);
    printf("Insira a quantidade do produto:\n>");
    scanf("%i", &ptrproduto->quantidade);
    printf("Insira o preço do produto:\n>");
    scanf("%i", &ptrproduto->preco);

    return 0;
}

int inserirmeio(){
    return 0;
}

int inserirfim(){
    return 0;
}

void exibir_lista(){
    return 0;
}

int pesquisar(){
    return 0;
}

int remover(){
    return 0;
}

int main(){
    ptrproduto = &produto;
    ptrproduto->prox = NULL;
    ptrproduto = (struct molde *) malloc(sizeof(produto));
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
                        inseririnicio();
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
                exibir_lista();
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