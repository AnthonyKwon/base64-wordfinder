#include <stdio.h>
#include <stdlib.h>
#include "base64.h"

int main (int argc, char** argv) {
    char *input;
    if (argc <= 1) scanf("%ms", &input);
    else input = argv[1];

    char *result = base64_encode(input);
    if (result == 0) return 1; // exit on error
    printf("%s\n", result);
    free(result);

    return 0;
}
