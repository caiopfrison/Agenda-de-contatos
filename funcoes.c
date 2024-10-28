#include "funcoes.h"
#include <string.h>

void adicionarContato(Contato *contatos, int *contador) {
    if (*contador < MAX_CONTATOS) {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", contatos[*contador].nome);
        printf("Digite o telefone: ");
        scanf(" %[^\n]s", contatos[*contador].telefone);
        (*contador)++;
        printf("Contato adicionado com sucesso!\n");
        salvarContatosBinario(contatos, *contador);  
        salvarContatosTexto(contatos, *contador);    
    } else {
        printf("Desculpe, mas você não possui espaço na agenda!\n");
    }
}

void excluirContato(Contato *contatos, int *contador, char *nome) {
    int i, j;
    for (i = 0; i < *contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            for (j = i; j < *contador - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*contador)--;
            salvarContatosBinario(contatos, *contador);  
            salvarContatosTexto(contatos, *contador);   
            printf("Contato excluído!\n");
            return;
        }
    }
    printf("Contato não encontrado!\n");
}

void listarContatos(Contato *contatos, int contador) {
    for (int i = 0; i < contador; i++) {
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n\n", contatos[i].telefone);
    }
}

void salvarContatosBinario(Contato *contatos, int contador) {
    FILE *arquivo = fopen("contatos.bin", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fwrite(contatos, sizeof(Contato), contador, arquivo);
    fclose(arquivo);
}

void carregarContatosBinario(Contato *contatos, int *contador) {
    FILE *arquivo = fopen("contatos.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    *contador = fread(contatos, sizeof(Contato), MAX_CONTATOS, arquivo);
    fclose(arquivo);
}

void salvarContatosTexto(Contato *contatos, int contador) {
    FILE *arquivo = fopen("contatos.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    for (int i = 0; i < contador; i++) {
        fprintf(arquivo, "%s\n%s\n", contatos[i].nome, contatos[i].telefone);
    }
    fclose(arquivo);
}

void carregarContatosTexto(Contato *contatos, int *contador) {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    *contador = 0;
    while (fscanf(arquivo, " %[^\n]s", contatos[*contador].nome) == 1) {
        fscanf(arquivo, " %[^\n]s", contatos[*contador].telefone);
        (*contador)++;
    }
    fclose(arquivo);
}
