#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ITER 1000000

struct timeval start, stop;

void startTime(){
    gettimeofday(&start, NULL);
}

void endTime(char *task){
    gettimeofdat(&stop, NULL);
    printf("Task {%s} completed in %ld microseconds.\n", task, stop.tv_sec*1000000 + stop.tv_usec - start.tv_sec*1000000 - start.tv_usec);
}

int main(){
    int a = 1;
    double b = 1.0;
    srand(time(NULL));
    int divisor = rand() % 1000;
    float d_divisor = *((float *) &divisor);

    startTime();
    for (int i=0; i < ITER; i++){
        a = a*i;
    }
    endTime("int *");

    startTime();
    for (double i=0; i < ITER; i++){
        b = b*i;
    }
    endTime("float *");

    startTime();
    for (int i=0; i < ITER; i++){
        a = i/divisor;
    }
    endTime("int /");

    startTime();
    for (double i=0; i < ITER; i++){
        b = i/d_divisor;
    }
    endTime("float /");
    
    startTime();
    for (double i=0; i < ITER; i++){
        b = sqrt(i);
    }
    endTime("sqrt");
    
    startTime();
    for (double i=0; i < ITER; i++){
        b = sin(i);
    }
    endTime("sin");

    return 0;
}