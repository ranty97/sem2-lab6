#pragma once

#include <stdio.h>
#include <stdlib.h>

int inputNatural(const char *title);

int inputNaturalRange(int min, int max, const char *title);

char *readString(FILE *in);
