#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc <= 1) return 0;
    size_t l = strlen(argv[1]);
    argv[1][l] = '\n';
    write(1, argv[1], l+1);
    argv[1][l] = '\0';
}
