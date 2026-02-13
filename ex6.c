#include <string.h>
#include <stdio.h>

void transformUpper(char *string){

    for (int i=0; i < strlen(string); i++){
        if (string[i] >= 97 && string[i] <= 122){
            string[i] = string[i]-32;
        }
    }
}

void apply_transform(void (*tform)(char *), char *string){
    tform(string);
}

int main(){
    char string[] = "This is a sentence, hopefully a loud one.";
    apply_transform(transformUpper, string);
    printf("%s", string);
    return 0;
}