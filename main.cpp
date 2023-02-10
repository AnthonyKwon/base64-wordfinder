#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "base64.h"

char* toLower(char*);

int main (void) {
    FILE* dict;
    dict = fopen("dict.txt", "r");
    if (dict == NULL) {
        printf("ERROR: cannot open dictionary file!");
        return 1;
    }
    char* input;
    while (fscanf(dict, "%ms", &input) > 0) {
        char *result = base64_encode(input);
        if(result != 0) printf("%s => %s\n", input, result);
        free(result);
    }

    fclose(dict);
    return 0;
}

char* toLower(char* str) {
    char* newstr = (char*)malloc(sizeof(char) * strlen(str));
    for(int i = 0; str[i]; i++){
        newstr[i] = tolower(str[i]);
    }
    return newstr;
}
