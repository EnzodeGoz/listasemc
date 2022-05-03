#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct molde
{
    int codigo;
    int quantidade;
    float preco;
}produto, *ptrproduto;

int n, *ptrn = 0;

int print_menu(){
    printf ("Escolha uma das opções do menu abaixo:\n");
    printf("1) Inserir itens\n2) Exibir lista de itens\n3) Pesquisar itens\n4) Remover itens\n5) Sair\n>");
    return 0;
}
int inserir(){
    int escolha = 0, y, u, t;
    printf("Gostaria de criar uma nova lista ou adicionar itens a lista existente?\n");
    printf("1) Nova lista\n2) Adicionar itens\n>");
    scanf("%d", &escolha);
    switch(escolha){
    case 1:
        printf("Gostaria de inserir quantos itens?\n>");
        scanf("%i",&ptrn);
        if ((int)ptrn > 5){
        printf("A lista deve ter no máximo 5 itens.\n\n");
        return 0;
        }
        else if ((int)ptrn < 5){
        for (int i = 0; i<(int)ptrn; i++){
        printf("Código do item %i:\n>", i);
        scanf("%i",&(ptrproduto + i)->codigo);
        printf("Preço do item %i:\n>", i);
        scanf("%f", &(ptrproduto + i)->preco);
        printf("A quantidade do item %i:\n>", i);
        scanf("%i", &(ptrproduto + i)->quantidade);
        }
        }
    break;
    case 2:
        printf("Quantos itens deseja adicionar?\n>");
        scanf("%i",&y);
        if ((int)ptrn + y > 5){
            printf("A lista deve ter no máximo 5 itens.\n");
            return 0;
        }
        else {
            for(int o = (int)ptrn; o < (int)ptrn + y; o++ ){
                printf("Código do item %i:\n>", o);
                scanf("%i",&(ptrproduto + o)->codigo);
                printf("Preço do item %i:\n>", o);
                scanf("%f", &(ptrproduto + o)->preco);
                printf("A quantidade do item %i:\n>", o);
                scanf("%i", &(ptrproduto + o)->quantidade);
               
            }
            u = (int)ptrn;
            t = u + y;
            ptrn = (int *)t;
        }
        break;
    }
    return 0;
}

int exibir_lista(struct molde* ptrproduto, int *ptrn){
    if((int)ptrn == 0){
        printf("A lista está vazia.\n");
        return 1;
    }
    else if ((int)ptrn != 0){
    for (int o = 0; o <(int)ptrn; o++){
        printf("Item %i\nCódigo:%i\nPreco:R$%.2f\nQuantidade:%i\n\n",o, (ptrproduto + o)->codigo, (ptrproduto + o)->preco, (ptrproduto + o)->quantidade);
    }
    return 0;
    }
    return 0;
}

int pesquisar(){
    int u, o;
    int t = 0;
    printf("Esse é o lista atual:\n");
    o = exibir_lista(ptrproduto, ptrn);
    if (o == 1){
    printf("\n\nAdicione itens a lista.\n");
    }
    else if ( o == 0){
    printf("Qual o código do item que deseja pesquisar?\n>");
    scanf("%i", &u);
    for(t = 0; t < 5; t++){
        if((ptrproduto + t)->codigo == u){
            printf("\nO item %i está na posição %d da lista.\n\n", u, t + 1);
            return 0;
        }
        else{
            printf("Procurando item...%i\nItem não encontrado...\n", t);
        }
        
    }
    }
    return 0;
}

int remover(){
    int j, p, k, l;
    p = exibir_lista(ptrproduto, ptrn);
    if( p == 1){
        printf("\n\nAdicione itens a lista.\n");
    }
    else if( p == 0){
    printf("Qual o código do item que deseja remover?\n>");
    scanf("%i",&j);
    printf("Qual a posição do item que deseja remover?\n>");
    scanf("%i",&k);
    l = (int)ptrn - 1;
    ptrn = (int*)l;
    for (int o=0;o<5;o++){
        if((ptrproduto + o)->codigo == j){
            for(o=k;o<(int)ptrn;o++){
            (ptrproduto + o)->codigo = (ptrproduto + o +1)->codigo;
            (ptrproduto + o)->preco =  (ptrproduto + o +1)->preco;
            (ptrproduto + o)->quantidade = (ptrproduto + o +1)->quantidade;
            return 0;
            }
        }
        else {
        printf("Procurando item...\nItem não encontrado...\n");
        }

    }
    printf("\nItem encontrado e removido.\nCheque a atual lista de itens.\n\n");
    return 0;
    }
    return 0;
}

int main(){
    ptrn = &n;
    ptrn = 0;
    ptrproduto = &produto;
    ptrproduto = (struct molde *) calloc(5, sizeof(struct molde));
    printf("Olá! Bem vindo ao programa de Listas Sequenciais.\n");
    for(int menu = 0; menu != 5; menu = menu){
        print_menu();
        scanf("%i", &menu);
        switch(menu){
            case 1:
                inserir();
            break;
            case 2:
                printf("Essa é a atual lista de itens:\n");
                exibir_lista(ptrproduto, ptrn);
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