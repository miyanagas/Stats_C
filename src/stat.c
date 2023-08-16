#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: %s <files..>\n", argv[0]);
        return (1);
    }

    return (0);
}