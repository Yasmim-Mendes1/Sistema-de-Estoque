#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100

struct Produto {
  int codigo;
  char nome[50];
  float preco;
  int quantidade;
};

void adicionarProduto(struct Produto produtos[], int *nprodutos){
  if (*nprodutos < MAX_PRODUTOS){
    struct Produto novoProduto;

    printf ("Informe o codigo do produto: ");
    scanf ("%d", &novoProduto.codigo);
    printf ("Informe o nome do produto: ");
    scanf ("%s", novoProduto.nome);
    printf ("Informe o preco do produto: ");
    scanf ("%f", &novoProduto.preco);
    printf ("Informe a quantidade do produto: ");
    scanf ("%d", &novoProduto.quantidade);

    produtos[*nprodutos] = novoProduto;
    (*nprodutos)++;
    printf ("Produto adicionado com sucesso!\n");
  }
  else {
    printf ("Numero maximo de produtos atingido! Nao foi possivel adicionar.\n");
  }
}

void atualizarEstoque (struct Produto produtos[], int nprodutos, int codigo, int quantidade){
  for (int i = 0; i < nprodutos; i++){
    if (produtos[i].codigo == codigo){
      produtos[i].quantidade += quantidade;
      printf ("Quantidade atualizada com sucesso!\n");
      return;
    }
  }
  printf ("Produto nao encontrado!\n");
}

void estoque (struct Produto produtos[], int nprodutos){
  printf ("\n----------ESTOQUE----------\n");
  for (int i = 0; i < nprodutos; i++){
    printf ("Codigo: %d  |  Nome: %s  |  Preco: %.2f  |  Quantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
  }
}

int main (){
  struct Produto produtos[MAX_PRODUTOS];
  int nprodutos = 0;
  int escolha, codigo, quantidade;

  do{
    printf ("\n----------MENU----------\n1- Adicionar produto;\n2- Atualizar estoque;\n3- Visualizar estoque;\n4- Sair;\n");

    printf ("\nEscolha uma opcao: ");
    scanf ("%d", &escolha);

    switch (escolha){
      case 1:
        adicionarProduto(produtos, &nprodutos);
        break;

      case 2:
        printf ("Informe o codigo do produto: ");
        scanf ("%d", &codigo);
        printf ("Informe a quantidade a ser adicionada/subtraída: ");
        scanf ("%d", &quantidade);
        atualizarEstoque(produtos, nprodutos, codigo, quantidade);
        break;

      case 3:
        estoque(produtos, nprodutos);
        break;

      case 4:
        printf ("Saindo do programa...\n");
        break;

      default:
        printf ("Opcao invalida!\n");
        break;
    } 
  } while (escolha != 4);

  return 0;
}
