#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverse(char *string){
    char *end = string + strlen(string) - 1;
    while (string < end){
        char temp = *end;
        *end = *string;
        *string = temp;

        string++;
        end--;
    }
}

void transform(void (*tform_f)(char *), char *string){
    printf("%s\n", string);
    tform_f(string);
    printf("%s\n", string);
}

int main(){
    // prompt
    printf("Enter string to transform: ");

    // allocate initial dynamic string
    int size = 100;
    char *string = malloc(size*sizeof(char));
    int len = 0;
    char c;
    // grab characters from stdin until newline
    while ((c = fgetc(stdin)) != '\n'){
        *(string+len) = c;
        len++;

        if (len > size){
            size = size*2;
            string = realloc(string, size);
        }
    }
    // null terminator
    *(string+len) = '\0';

    transform(reverse, string);

    free(string);
    return 0;
}