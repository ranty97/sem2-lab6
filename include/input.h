#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifndef LAB6_INPUT_H
#define LAB6_INPUT_H

int inputNatural(const char *title);

int inputNaturalRange(int min, int max, const char *title);

char *readString(FILE *in);

#endif //LAB6_INPUT_H
