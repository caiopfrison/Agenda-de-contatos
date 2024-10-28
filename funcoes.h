#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTATOS 100
#define MAX_NOME 50
#define MAX_TELEFONE 15

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
} Contato;

void adicionarContato(Contato *contatos, int *contador);
void excluirContato(Contato *contatos, int *contador, char *nome);
void listarContatos(Contato *contatos, int contador);
void salvarContatosBinario(Contato *contatos, int contador);
void carregarContatosBinario(Contato *contatos, int *contador);
void salvarContatosTexto(Contato *contatos, int contador);
void carregarContatosTexto(Contato *contatos, int *contador);

#endif
