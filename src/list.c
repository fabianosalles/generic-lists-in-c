#pragma once

#include "list.h"
#include <assert.h>


List *list_create(int dataSize) {
	assert(dataSize > 0);

	List *list = (List *)malloc(sizeof(List));
	list->count = 0;
	list->data_size = dataSize;
	list->head = NULL;
	list->tail = NULL;
	return list;
}


void list_destroy(List *list) {
	assert(list != NULL);

	if (list->head != NULL) {
		Node *node = list->head;
		while (node != NULL) {
			list->head = node->next;
			free(node->data);
			free(node);
			list->count--;
			node = list->head;
		}
	}
	free(list);
}


void list_add(List *list, void *data) {
	assert(list != NULL);
	assert(data != NULL);

	Node *newNode = calloc(sizeof(Node), 1);
	newNode->data = malloc(list->data_size);
	memcpy(newNode->data, data, list->data_size);
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
	}
	else {
		list->tail->next = newNode;
		list->tail = newNode;
	}
	list->count++;
}

void list_remove(List *list, int index) {
	assert(list != NULL);
	assert(index >= 0);
	assert(index <= list->count - 1);

	int i = 0;
	Node *curr_node = list->head;
	while (i < index - 1) {
		curr_node = curr_node->next;
		i++;
	}

	Node *target_node = curr_node->next;
	if (target_node == NULL) {
		list->tail = curr_node;
	}
	else {
		curr_node->next = target_node->next;
		if (target_node->next == NULL) {
			list->tail = curr_node;
		}
		free(target_node->data);
		free(target_node);
	}
	list->count--;
}