#define FINAL_SIDES 100

#include <math.h>
#include <stdio.h>
#include <sys/time.h>

int main(){
    // starting values for inscribed hexagon
    double insSideLen = 1.0;
    double insSemiperimeter;
    double insSqHalfLen;

    // starting values for circumscribed hexagon
    double cirSideLen = 2/sqrt(3);
    double cirSemiperimeter;

    struct timeval start, stop;
    gettimeofday(&start, NULL);

    for (int i = 6; i <= FINAL_SIDES; i=i*2){
        // approximate pi
        insSemiperimeter = i*insSideLen/2;
        cirSemiperimeter = i*cirSideLen/2;

        // display
        printf("Approximation of pi using inscribed %d-gon: %.9f\n", i, insSemiperimeter);
        printf("Approximation of pi using circumscribed %d-gon: %.9f\n", i, cirSemiperimeter);

        // update side length for doubling of sides
        insSqHalfLen = insSideLen*insSideLen/4;
        insSideLen = sqrt(pow(1 - sqrt(1 - insSqHalfLen), 2) + insSqHalfLen);

        cirSideLen = 4*(sqrt(cirSideLen*cirSideLen/4 + 1) - 1)/cirSideLen;
    }
    gettimeofday(&stop, NULL);

    printf("Completed in %ld microseconds.\n", stop.tv_sec*1000000 + stop.tv_usec - start.tv_sec*1000000 - start.tv_usec);

    return 0;
}