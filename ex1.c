#include <stdio.h>
#include <string.h>

int main(){
    char name[100];

    printf("Enter name: ");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = 0;
    printf("Hello, %s!\n", name);

    return 0;
}