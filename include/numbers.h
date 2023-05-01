#pragma once

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "list.h"

bool isPrime(int number);

bool isEven(int number);

void visitSimple(node *x, void *data);

void visitEven(node *x, void *data);

void eraseFromToPrime(list *from, list *to);

void eraseFromToEven(list *from, list *to);

void eraseFromToPrime1(list *from, list *prime, list *even, list *odd);