#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

char* gen(int length, bool spec);
int randlim(int min, int max);

int main(int argc, char** argv) {
    int len = randlim(10, 20);
    bool spec = false;

    if (argc < 2) {
        printf("Password length not specified, generating %d chars len\n", len);
    } else {
        for (int i = 0; i < argc; i++) {
            char* cur = argv[i];
            if (strcmp(cur, "-s") == 0) {
                spec = true;
            } else {
                len = atoi(argv[1]);
                if ((len == 0) && (strcmp(cur, "0") != 0)) {
                    printf("Usage: genpas [-s for spec chars] count\n");
                    return 1;
                }
            }
        }
    }

    printf("%s\n", gen(len, spec));

    return 0;
}

int randlim(int min, int max) {
    srand(time(NULL));
    int r = rand();
    return min + r % (max - min + 1);
}

char* gen(int length, bool spec) {
    char* res = malloc(length + 1);
    if (res == NULL) {
        return "";
    }

    FILE* randfil = fopen("/dev/urandom", "rb");

    int ctr = 0;
    while (ctr < length) {
        uint8_t byte; 
        do {
            fread(&byte, 1, 1, randfil);
        } while (!(\
                (spec && byte >= '!' && byte <= 'z') ||\
                (!spec && isalnum(byte))
                ));
        
        res[ctr] = byte;
        ctr++;
    }
    res[length] = '\0';

    return res;
}
