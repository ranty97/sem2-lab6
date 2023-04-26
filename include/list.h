#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int number;

    node *next;
    node *prev;
};

typedef struct list list;

struct list {
    node *head;
    node *tail;
};

bool empty(list *self);

void push(list *self, int number);

list *initList(list *self);

void insertNodeAfter(node *that, node *new);

void freeNode(node *what);

void eraseFromList(list *self, node *what);

node *initNode(node *self, int number);

typedef void (*visitor_f)(node *x, void *data);

void visitList(list *self, visitor_f visitor, void *data);
