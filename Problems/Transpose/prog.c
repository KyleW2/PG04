#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int m;
} Dimensions;

Dimensions get_dimensions(char* input_file) {
    Dimensions dimensions;
    FILE* fp = fopen(input_file, "r");

    int n;
    int m;
    fscanf(fp, "%d %d", &n, &m);

    fclose(fp);
    
    dimensions.n = n;
    dimensions.m = m;
    return dimensions;
}

void load_input_to_matrix(char* input_file, int** matrix, Dimensions d) {
    FILE* fp = fopen(input_file, "r");

    int skip;
    fscanf(fp, "%d %d", &skip);

    /*
    while(fscanf(fp, "%d", &holder) != EOF) {
        if(j > d.m) {
            j = 0;
            i++;
        }
        if(i > d.n) {
            i = 0;
        }

        matrix[i][j] = holder;
        j++;
    }
    */

    for(int i = 0; i < d.n; ++i) {
        for(int j = 0; j < d.m; ++j) {
            fscanf(fp, "%d", matrix[i][j]);
        }
    }

    fclose(fp);
}

void write_transpose(char* output_file, int** matrix, Dimensions d) {
    FILE* fp = fopen(output_file, "w");

    fprintf(fp, "%d %d\n", d.m, d.n);

    for(int j = 0; j < d.m; j++) {
        for(int i = 0; i < d.n; i++) {
            fprintf(fp, "%d ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    switch(argc) {
        case 1:
            printf("Please enter an input and output file.");
            break;
        case 2:
            printf("Please enter an input and output file.");
            break;
        case 3:;
            // Get file names
            char* input_file = argv[1];
            char* output_file = argv[2];

            // Create matrix
            Dimensions d = get_dimensions(input_file);

            int** matrix = (int**)malloc(sizeof(int) * d.n);
            for(int i = 0; i < d.n; i++) {
                matrix[i] = (int*)malloc(d.m * sizeof(int));
            }

            load_input_to_matrix(input_file, matrix, d);

            /*/ Write to output
            write_transpose(output_file, matrix, d);

            // Free matrix
            free(matrix);*/
            break;
    };
    return 0;
}