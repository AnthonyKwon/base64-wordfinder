#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B64_BIT_SIZE 6

char* base64_encode(char* input) {
    // test if input size is multipied by 3 (24 bits = 3 bytes)
    // this is a minimal value both size of plain string and base64 string can be divisible.
    if (strlen(input) % 3 != 0) {
        //printf("ERROR: size of input is not multiplied by 3!\n");
        return 0;
    }

    // base64 encoding part
    int buf, strsize = strlen(input)*sizeof(input);
    // set size of base64 output char array to (base64 string size + \0)
    char *output = (char*)malloc(sizeof(char) * ((strlen(input)/3*4)+1));
     // add '\0' to end of char array (fix for garbage value printed)
    output[((strlen(input)/3*4))] = '\0';
    for (int p = 0; p < strsize; p+=B64_BIT_SIZE) {
        // bit parsing mechamism
        if ((p/B64_BIT_SIZE) % 4 == 1) {
            buf = (*(input-1) << 4) & 48; // get 2 bits(xxxxxx00) from last address
            buf += (*input >> 4) & 15; // get 4 bits(0000xxxx) from current address
            input++;
        } else if ((p/B64_BIT_SIZE) % 4 == 2) {
            buf = (*(input-1) << 2) & 60; // get 4 bits(xxxx0000) from last address
            buf += (*input >> 6) & 3; // get 2 bits(00xxxxxx) from current address
        } else if ((p/B64_BIT_SIZE) % 4 == 3) {
            buf = *input & 63; // get 6 bits(xx000000) from current address
            input++;
        } else {
            buf = (*input >> 2) & 63; // get 6 bits(000000xx) from current address
            input++;
        }

        // verify if value is in alphabet range
        if (buf > 51) {
            //printf("ERROR: encoded result contains non-alphabet character!\n");
            return 0;
        }

        // convert to ascii
        if (buf < 26)
            output[p/B64_BIT_SIZE] = buf + 65;
        else
            output[p/B64_BIT_SIZE] = buf + 71;
    }
    return output;
}
