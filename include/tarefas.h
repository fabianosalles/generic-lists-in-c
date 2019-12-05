#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef struct {
	char descicao[255];
	bool pendente;
} Tarefa;

Tarefa *tarefa(char *descricao, bool pendente) {
	Tarefa *result = calloc(1, sizeof(Tarefa));
	memcpy(result->descicao, descricao, strlen(descricao));
	result->pendente = pendente;
	return result;
}


#define TEL_FIXO 0x00
#define TEL_CELULAR 0x01
typedef struct {
	char tipo;
	char ddd[3];
	char numero[15];
} Telefone;

Telefone *telefone(char tipo, char *ddd, char *numero) {
	Telefone *result = calloc(1, sizeof(Telefone));
	result->tipo = tipo;
	memcpy(result->ddd, ddd, strlen(ddd));
	memcpy(result->numero, numero, strlen(numero));
	return result;
}

void telefone_destroy(Telefone *telefone) {
	free(telefone);
}

typedef struct {
	char nome[80];
	List *tarefas;
	List *telefones;
} Pessoa;


Pessoa *pessoa_create(char *nome) {
	Pessoa *result = calloc(1,sizeof(Pessoa));
	memcpy(result->nome, nome, strlen(nome));
	result->tarefas = list_create(sizeof(Tarefa));
	result->telefones = list_create(sizeof(Pessoa));
	return result;
}

void pessoa_destroy(Pessoa *pessoa){
	list_destroy(pessoa->tarefas);
	list_destroy(pessoa->telefones);
	free(pessoa);
}

void adicionar_tarefa(Pessoa *pessoa, Tarefa *tarefa) {
	list_add(pessoa->tarefas, tarefa);	
}

void listar_tarefas(Pessoa *pessoa) {
	Node *node = pessoa->tarefas->head;
	Tarefa *tarefa;
	int i = 1;
	printf("Tarefas:\n");
	while (node != NULL){
		tarefa = (Tarefa *)node->data;
		printf("  [%s] %02d - %s\n", tarefa->pendente ? "  " : "OK", i,  tarefa->descicao);
		node = node->next;
		i++;
	}
}

void adicionar_telefone(Pessoa *pessoa, Telefone *telefone) {
	list_add(pessoa->telefones, telefone);
}

void listar_telefones(Pessoa *pessoa) {
	Node *node = pessoa->telefones->head;
	Telefone *telefone;
	int i = 1;
	printf("Telefones:\n");
	while (node != NULL) {
		telefone = (Telefone *)node->data;
		switch (telefone->tipo){
		case TEL_FIXO:
			printf("  FIXO    (%s)  %s\n", telefone->ddd, telefone->numero);
			break;
		case TEL_CELULAR:
			printf("  CELULAR (%s) %s\n", telefone->ddd, telefone->numero);
			break;
		}
		node = node->next;
		i++;
	}
}

void listar_detalhes(Pessoa *pessoa) {
	printf("Listando dados de %s:\n", pessoa->nome);
	pessoa_listar_tarefas(pessoa);
	pessoa_listar_telefones(pessoa);
}