#include "input.h"

int inputNatural(const char *title) {
    int x;
    char string[256];
    printf("%s", title);
    while (scanf("%d%[^\n]", &x, string) != 1 || x < 0) {
        printf("Invalid value, input again:");
        fseek(stdin, SEEK_END, 0);
    }
    return x;
}

int inputNaturalRange(int low, int high, const char *title) {
    int x;
    char string[256];
    printf("%s", title);
    while (scanf("%d%[^\n]", &x, string) != 1 || x < low || x > high) {
        printf("Invalid value, input again:");
        fseek(stdin, SEEK_END, 0);
    }
    return x;
}

bool isEOL(int ch) {
    return ch == '\n' || ch == '\0' || ch == EOF;
}

char *readString(FILE *in) {
    size_t size = 16;
    size_t read = 0;

    char *buffer = (char *) malloc(size * sizeof(*buffer));
    if (buffer == NULL) exit(1);

    for (int ch = fgetc(in); !isEOL(ch); ch = fgetc(in)) {
        buffer[read++] = (char) ch;

        if (read >= size) {
            size *= 2;

            size_t bufferSize = size * sizeof(*buffer);
            char *newBuffer = (char *) realloc(buffer, bufferSize);
            if (newBuffer == NULL) exit(1);
            buffer = newBuffer;
        }
    }
    buffer[read++] = 0;

    size_t bufferSize = size * sizeof(*buffer);
    char *clippedBuffer = (char *) realloc(buffer, bufferSize);
    if (clippedBuffer == NULL) free(buffer);

    return clippedBuffer;
}