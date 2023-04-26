#include "list.h"

bool empty(list *self) {
    return self->head == NULL && self->tail == NULL;
}

void push(list *self, int number) {
    node *new = initNode(malloc(sizeof(*new)), number);

    if (empty(self)) {
        self->head = self->tail = new;
        return;
    }

    insertNodeAfter(self->tail, new);
    self->tail = new;
}

list *initList(list *self) {
    *self = (list) {};
    return self;
}

void insertNodeAfter(node *that, node *new) {
    new->next = that->next;
    new->prev = that;

    that->next = new;
    if (new->next) new->next->prev = new;
}

void freeNode(node *what) {
    if (!what) return;

    if (what->next) what->next->prev = what->prev;
    if (what->prev) what->prev->next = what->next;

    free(what);
}

void eraseFromList(list *self, node *what) {
    if (self->head == what) self->head = what->next;
    if (self->tail == what) self->tail = what->prev;
    freeNode(what);
}

node *initNode(node *self, int number) {
    *self = (node) {
            .number = number,
            .next = self,
            .prev = self,
    };
    return self;
}

void visitList(list *self, visitor_f visitor, void *data) {
    for (node *it = self->head; it != self->tail; it = it->next) {
        visitor(it, data);
    }
    visitor(self->tail, data);
}
