#if HAVE_CONFIG_H
    #include <config.h>
#endif

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <limits.h>
#include "rand.h"



int main(int argc, char **argv) {
    uint64_t min = 0, max = UINT64_MAX;
    if(argc > 1)
        min = strtoumax(argv[1], NULL, 0);
    if(argc > 2)
        max = strtoumax(argv[2], NULL, 0);
    
    union {
        uint64_t i;
        unsigned char c[sizeof(uint64_t)];
    } u;

    if(random_buf(u.c, sizeof(uint64_t)) > 0) {
	
        if(printf("%"PRIu64"\n", (u.i % max) + min) > 0) return 0;
        perror("printf");
        return 1;
    }
    perror("getnrand");
    return 1;
}
