#include "funcoes.h"

int main() {
    Contato contatos[MAX_CONTATOS];
    int contador = 0;
    int opcao;
    char nome[MAX_NOME];

    carregarContatosBinario(contatos, &contador);  
    carregarContatosTexto(contatos, &contador);   

    do {
        printf("\n1. Adicionar contato\n");
        printf("2. Excluir contato\n");
        printf("3. Listar contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &contador);
                break;
            case 2:
                printf("Digite o nome do contato: ");
                scanf(" %[^\n]s", nome);
                excluirContato(contatos, &contador, nome);
                break;
            case 3:
                listarContatos(contatos, contador);
                break;
            case 0:
                printf("Obrigado, até breve...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
