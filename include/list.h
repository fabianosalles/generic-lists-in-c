#pragma once

typedef struct _node {
	void *data;
	struct _node *next;
} Node;

typedef struct {
	int count;
	int data_size;
	Node *head;
	Node *tail;
} List;


List* list_create(int dataSize);
void list_destroy(List *list);
void list_add(List *list, void *data);
void list_remove(List *list, int index);

