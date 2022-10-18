#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


int main(){
    char c;
    char may;
    int n = 0;
    int count = 0;

    do{
        n = read(STDIN_FILENO,&c,1);
        may = toupper(c);
        if(may == 'A' || may == 'E' ||may == 'I' ||may == 'O' ||may == 'U') {
            count++;
        }
    } while(n != 0);
    printf("%d", count);
    return 0;
}