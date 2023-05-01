#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct visitor visitor;

struct visitor {
    list *prev;
    list *present;
};

bool empty(list *self);

void push(list *self, int number);

void pushNode(list *self, node *new);

list *initList(list *self);

void insertNodeAfter(node *that, node *new);

void freeNode(node *what);

void eraseFromList(list *self, node *what);

void detachFromList(list *self, node *what);

node *initNode(node *self, int number);

typedef void (*visitor_f)(node *x, void *data);

void visitList(list *self, visitor_f visitor, void *data);

void printVisitor(node *x, void *data);
