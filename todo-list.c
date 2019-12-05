#include <locale.h>
#include <stdlib.h>
#include "tarefas.h"
#include "list.h"

int main(void) {
	setlocale(LC_ALL, "pt");

	Pessoa* fabiano = pessoa_create("Fabiano Salles");	
	adicionar_tarefa(fabiano, tarefa("Publicar artigo sobre listas genéricas em C", false));
	adicionar_tarefa(fabiano, tarefa("Escrever sobre games em SDL e C++", true));
	adicionar_tarefa(fabiano, tarefa("Concluir o curso de microeletrônica", true));
	adicionar_tarefa(fabiano, tarefa("Escrever um artigo sobre Arduino", true));
	adicionar_telefone(fabiano, telefone(TEL_CELULAR, "11", "90000-0000"));
	adicionar_telefone(fabiano, telefone(TEL_FIXO, "11", "0000-0000"));
	listar_detalhes(fabiano);
	pessoa_destroy(fabiano);
	return 0;
}
