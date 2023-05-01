#include "numbers.h"

bool isPrime(int number) {
    for (int j = 2; j * j <= number; j++) {
        if (number % j == 0) {
            return false;
        }
    }
    return true;
}

bool isEven(int number) {
    if (number % 2 == 0) return true; else return false;
}

void visitSimple(node *x, void *data) {
    visitor *simple = data;

    if (isPrime(x->number)) {
        push(simple->present, x->number);
        eraseFromList(simple->prev, x);
    }
}

void visitEven(node *x, void *data) {
    list *simple = data;
    if (isEven(x->number)) {
        push(simple, x->number);
    }
}

//void eraseFromToPrime(list *from, list *to) {
//    while (from->head->next != NULL) {
//        if (isPrime(from->head->number)) {
//            push(to, from->head->number);
//            eraseFromList(from, from->head);
//        } else from->head = from->head->next;
//    }
//    if(from->head == NULL){from->head = from->tail;}
//}

void eraseFromToEven(list *from, list *to) {
    while (from->head != NULL) {
        if (isEven(from->head->number)) {
            push(to, from->head->number);
            eraseFromList(from, from->head);
        } else from->head = from->head->next;
    }
}

void eraseFromToPrime1(list *from, list *prime, list *even, list *odd) {
    while (from->head) {
        node *it = from->head;
        detachFromList(from, it);
        if (isPrime(it->number)) {
            pushNode(prime, it);
        } else if (isEven(it->number)) {
            pushNode(even, it);
        } else {
            pushNode(odd, it);
        }
    }
}
