#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if(argc <= 1) return 1;
    struct stat sb;
    int ret = stat(argv[1], &sb);
    if(ret < 0) return 2;
    printf("%lu", (long unsigned)sb.st_size);
    return 0;
}
