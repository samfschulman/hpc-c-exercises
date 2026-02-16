#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2){
        return 1;
    }

    int i,j;
    int n = atoi(argv[1]);
    double sum;
    clock_t end, start;
    double arr[n][n];
    
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            arr[i][j] = (double) rand()/RAND_MAX;
    
    // ROW MAJOR WORK
    sum = 0;
    start = clock();
    for (i = 0; i<n; i++) // iterate over rows 
        for (j = 0; j<n; j++) // iterate over columns 
            sum += arr[i][j];
    end = clock();

    printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);
    
    // COLUMN MAJOR WORK
    sum = 0;
    start = clock();
    for (j = 0; j<n; j++) // iterate over columns 
        for (i = 0; i<n; i++) // iterate over rows 
            sum += arr[i][j];
    end = clock();

    printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);
    
    return 0;
}

