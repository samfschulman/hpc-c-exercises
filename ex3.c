#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

int *matrix;
int *vector;
int *out;
int rows;
int cols;
int vdim;

void readData(){
    char line[100];
    char *cursor;
    FILE *mv = fopen("mv.txt", "r");
    
    // read rows and cols, allocate buffer
    fgets(line, 100, mv);
    sscanf(line, "%d %d", &rows, &cols);
    matrix = malloc(rows*cols*sizeof(int));

    // load in matrix
    for (int i=0; i < rows; i++){
        fgets(line, 100, mv);

        // read each value from line in file
        cursor = line;
        for (int j=0; j < cols; j++){
            sscanf(cursor, "%d", &(matrix[i*cols+j]));
            // locate next space so we know where to load next value
            cursor = strchr(cursor, ' ') + 1;
        }
    }

    // read vector dimensionality
    fgets(line, 100, mv);
    sscanf(line, "%d", &vdim);
    vector = malloc(vdim*sizeof(int));

    // load in vector
    fgets(line, 100, mv);
    cursor = line;
    for (int i=0; i < vdim; i++){
        sscanf(cursor, "%d", &(vector[i]));
        cursor = strchr(cursor, ' ') + 1;
    }

    fclose(mv);
}

int main(){
    struct timeval start, stop;
    readData();

    if (cols != vdim){
        puts("Error: matrix columns and vector dimension do not match. Multiplication impossible.\n\nExiting.");
    }
    else{
        out = calloc(rows, sizeof(int));
        gettimeofday(&start, NULL);
        for (int i=0; i < rows; i++){
            for (int j=0; j < cols; j++){
                out[i] += matrix[i*cols+j]*vector[j];
            }
        }
        gettimeofday(&stop, NULL);
    }

    // print result
    for (int i=0; i < rows; i++){
        printf("%d\n", out[i]);
    }
    printf("Completed in %ld microseconds.\n", stop.tv_sec*1000000 + stop.tv_usec - start.tv_sec*1000000 - start.tv_usec);

    free(matrix);
    free(vector);
}