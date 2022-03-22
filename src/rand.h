#ifndef RAND_H
#define RAND_H

#if HAVE_CONFIG_H
    #include <config.h>
#endif
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>


#if HAVE_GETRANDOM
    #if HAVE_DECL_GETRANDOM
        #include <sys/random.h>
    #else
        ssize_t getrandom(void *buf, size_t n, unsigned flags);
    #endif
#else
    #include <unistd.h>
    #include <fcntl.h>
#endif


static inline ssize_t random_buf(void *buf, size_t nb) {
    #if HAVE_GETRANDOM
        return getrandom(buf, nb, 0);
    #else
        static const char *devices[] = {
            "/dev/urandom", "/dev/arandom", "/dev/random", NULL
        };
    
        size_t i = 0;
        int rfd;
        do {
            rfd = open(devices[i], O_RDONLY);
        } while(rfd < 0 && devices[++i]);
        if(rfd < 0) return -1;
    
        ssize_t n;
        size_t t = 0;
        while((n = read(rfd, buf + t, nb - t)) > 0) {
            t += n;
            if(t >= nb) {
                close(rfd);
                return t;
            }
        }
        close(rfd);
        return -1;
    #endif
}
#endif
