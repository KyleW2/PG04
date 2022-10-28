#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_input_length(char* input_file) {
    int length;
    FILE* fp = fopen(input_file, "r");

    fscanf(fp, "%d", &length);

    fclose(fp);
    return length;
}

void load_input_to_array(char* input_file, float* array) {
    FILE* fp = fopen(input_file, "r");

    int skip;
    fscanf(fp, "%d", &skip);

    int i = 0;
    float holder;
    while(fscanf(fp, "%f", &holder) != EOF) {
        array[i] = holder;
        i++;
    }

    fclose(fp);
}

void write_stats(char* output_file, float* stats) {
    FILE* fp = fopen(output_file, "w");

    fprintf(fp, "Min: %d\n", stats[0]);
    fprintf(fp, "Max: %d\n", stats[1]);
    fprintf(fp, "Avg: %d\n", stats[2]);
    fprintf(fp, "Std: %d\n", stats[3]);

    fclose(fp);
}

float* compute_stats(float* array, int length) {
    float min = array[0];
    float max = array[0];
    float mean = 0.0;

    for(int i = 0; i < length; i++) {
        if(array[i] < min) {
            min = array[i];
        }
        if(array[i] > max) {
            max = array[i];
        }

        mean += array[i];
    }

    mean = mean / length;

    float squared_differences = 0.0;

    for(int i = 0; i < length; i++) {
        float diff = array[i] - mean;
        squared_differences += diff * diff;
    }

    squared_differences = squared_differences / length;
    squared_differences = sqrt(squared_differences);

    float* stats = (float*)malloc(sizeof(float) * 4);
    stats[0] = min;
    stats[1] = max;
    stats[2] = mean;
    stats[3] = squared_differences;

    return stats;
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

            // Create array
            int length_of_array = get_input_length(input_file);
            float* array = (float*)malloc(sizeof(float) * length_of_array);
            load_input_to_array(input_file, array);

            // Compute stats
            float* stats = compute_stats(array, length_of_array);

            // Write to output
            write_stats(output_file, stats);

            // Free array
            free(array);
            break;
    };
    return 0;
}