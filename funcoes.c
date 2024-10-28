#include "funcoes.h"
#include <string.h>

void adicionarContato(Contato *contatos, int *contador) {
    if (*contador < MAX_CONTATOS) {
        
    }
}

void excluirContato(Contato *contatos, int *contador, char *nome) {
    for (int i = 0; i < *contador; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            
            for (int j = i; j < *contador - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*contador)--;
            break;
        }
    }
}

void listarContatos(Contato *contatos, int contador) {
    for (int i = 0; i < contador; i++) {
        
    }
}

void salvarContatosBinario(Contato *contatos, int contador) {
    
}

void carregarContatosBinario(Contato *contatos, int *contador) {
    
}

void salvarContatosTexto(Contato *contatos, int contador) {
    
}

void carregarContatosTexto(Contato *contatos, int *contador) {
    
}
