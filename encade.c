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
    printf ("\nEscolha uma das opções do menu abaixo:\n");
    printf("1) Inserir itens\n2) Exibir lista de itens\n3) Pesquisar itens\n4) Remover itens\n5) Sair\n>");
    return 0;
}
Mol* criarmol(){
    Mol *novMol = (Mol*)malloc(sizeof(Mol));
    return novMol;
}
Mol* inseririnicio(Mol*ptrproduto){
    Mol*novomol = criarmol();
    printf("Insira o código do produto:\n>");
    scanf("%i",&novomol->codigo);
    printf("Insira a quantidade do produto:\n>");
    scanf("%i", &novomol->quantidade);
    printf("Insira o preço do produto:\n>");
    scanf("%f", &novomol->preco);
    if(ptrproduto == NULL){
        ptrproduto = novomol;
        novomol->prox = NULL;
    }
    else{
        novomol->prox = ptrproduto;
        ptrproduto = novomol;
    }
    return ptrproduto;
    
}


Mol* inserirfim(Mol*ptrproduto){
    Mol*novomol = criarmol();
    printf("Insira o código do produto:\n>");
    scanf("%i",&novomol->codigo);
    printf("Insira a quantidade do produto:\n>");
    scanf("%i", &novomol->quantidade);
    printf("Insira o preço do produto:\n>");
    scanf("%f", &novomol->preco);
    if(ptrproduto == NULL){
        novomol->prox = NULL;
        ptrproduto = novomol;
    }
    else{
        Mol *mau=ptrproduto;
        while(mau->prox != NULL){
                mau=mau->prox;
        }
        novomol->prox = NULL;
        mau->prox = novomol;
    }
    return ptrproduto;
}

void exibir_lista(Mol* ptrproduto){
    Mol *printmol = ptrproduto;
    if (ptrproduto == NULL){
        printf("A lista está vazia.\n");
    }
    else{
        while(printmol != NULL){
            printf("\nItem:\nCódigo: %i\nQuantidade: %i\nPreço: R$%.2f\n", printmol->codigo, printmol->quantidade, printmol->preco);
                printmol = printmol->prox;
        }
    }
}

void pesquisar(Mol * ptrproduto){
    int cod;
    if (ptrproduto == NULL){
        printf("A lista está vazia.\n");
    }
    else{
        printf("Qual o código do item que deseja pesquisar?\n>");
        scanf("%i", &cod);
        Mol *pesquisamol = ptrproduto;
            while(pesquisamol != NULL){
                if(pesquisamol->codigo == cod){
                    printf("\nItem:\nCódigo: %i\nQuantidade: %i\nPreço: R$%.2f\n", pesquisamol->codigo,pesquisamol->quantidade,pesquisamol->preco);
                }
                pesquisamol = pesquisamol->prox;
            }
    }
}

Mol * removerinicio(Mol * ptrproduto){
    free(ptrproduto);
    ptrproduto = ptrproduto->prox;
    return ptrproduto;
}

Mol * removerfim(Mol * ptrproduto){
    Mol * antemol = ptrproduto;
    Mol * atuamol = ptrproduto->prox;
    while(atuamol->prox != NULL){
        antemol = atuamol;
        atuamol = atuamol->prox;
    }
    antemol->prox = NULL;
    free(atuamol);
    return antemol;
}

int main(){
    ptrproduto = NULL;
    int pos, poos;
    printf("Olá! Bem vindo ao programa de Listas Sequenciais.\n");
    for(int menu = 0; menu != 5; menu = menu){
        print_menu();
        scanf("%i", &menu);
        switch(menu){
            case 1:
                printf("Deseja inserir um elemento em que posição da lista?\n");
                printf("1) Inicio\n2) Final\n3) Sair\n>");
                scanf("%i", &pos);
                switch(pos){
                    case 1:
                        ptrproduto = inseririnicio(ptrproduto);
                    break;
                    case 2:
                        ptrproduto = inserirfim(ptrproduto);
                    break;
                    case 3:
                        printf("Sair foi escolhido.\n");
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
                pesquisar(ptrproduto);
            break;
            case 4:
                if (ptrproduto == NULL){
                    printf("A lista está vazia.\n");
                }
                else{
                printf("Deseja remover o elemento de que posição da lista?\n");
                printf("1) Inicio\n2) Fim\n3) Sair\n>");
                scanf("%i", &poos);
                switch(poos){
                    case 1:
                        ptrproduto = removerinicio(ptrproduto);
                    break;
                    case 2:
                        ptrproduto = removerfim(ptrproduto);
                    break;
                    case 3:
                        printf("Sair foi escolhido.\n");
                    break;
                    default:
                        printf("Comando inválido. Insira uma escolha válida.\n");
                }
                }
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