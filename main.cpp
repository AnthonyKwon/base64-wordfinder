#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "base64.h"

std::string toLower(std::string);

int main (void) {
    // open dictonary file - dict.txt
    FILE* dictfile;
    dictfile = fopen("dict.txt", "r");
    if (dictfile == NULL) {
        // failed to open file - notify to user and exit
        std::cout << "ERROR: cannot open dictfileionary file!\n";
        return 1;
    }

    // add word to original dictonary, and base64 dictonary (after convertion)
    std::vector<std::string> dict;
    std::vector<std::string> b64dict;
    // create temporary input value variable
    char* input;
    while (fscanf(dictfile, "%ms", &input) > 0) {
        // add original word to dictionary 
        dict.push_back(input);
        // convert word to base64
        char* result = base64_encode(input);
        // if base64 has invalid value, skip current loop
        if(result == 0) continue;
        // add converted word to base64 dictionary
        b64dict.push_back(std::string(result));
        // free char* result variable from memory
        free(result);
    }
    if (!feof(dictfile)) {
        // unknown file error has occured while reading
    }
    // clear input buffer
    free(input);
    // close input file
    fclose(dictfile);

    //
    std::vector<std::string>::iterator iter;
    for (iter = b64dict.begin(); iter != b64dict.end(); iter++) {
        //
        if (std::count(dict.begin(), dict.end(), toLower(*iter)))
            std::cout << *iter << "(" << toLower(*iter) << ") found.\n";
    }
    return 0;
}

std::string toLower(std::string string) {
        // convert input string to lowercase
        std::transform(
            string.begin(),
            string.end(),
            string.begin(),
            ::tolower
        );
        return string;
}
