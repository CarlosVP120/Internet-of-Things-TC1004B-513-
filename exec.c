#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Soy el proceso hijo y me voy a convertir en ls\n");
        execl("/workspace/Internet-of-Things-TC1004B-513-/hola", "holamundo", NULL);
        printf("No deberia de ejecutarse");
    } else {
        printf("Soy el proceso padre\n");

    }

    return 0;
}