#include <stdio.h>
#include <stdlib.h>

int get_word_length(char* input_file) {
    FILE* fp = fopen(input_file, "r");

    int i = 0;
    float holder;
    while(fscanf(fp, "%c", &holder) != EOF) {
        i++;
    }

    fclose(fp);

    return i;
}

void get_word(char* input_file, char* word) {
    FILE* fp = fopen(input_file, "r");

    int i = 0;
    char holder;
    while(fscanf(fp, "%c", &holder) != EOF) {
        word[i] = holder;
        i++;
    }

    fclose(fp);
}

void calc_frequency(int* freq, char* word, int length) {
    for(int i = 0; i < length; i++) {
        freq[(int)word[i]-97]++;
    }
}

int get_max(int* array, int length) {
    int max = array[0];
    
    for(int i = 0; i < length; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

void write_histogram(char* output_file, int* freq, int max) {
    FILE* fp = fopen(output_file, "w");

    for(int m = max; m > -1; m--) {
        for(int i = 0; i < 27; i++) {
            if(freq[i] == m) {
                freq[i]--;
                fprintf(fp, "x");
            } else {
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "__________________________");
    fprintf(fp, "abcdefghijklmnopqrstuvwxyz");

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

            // Get word
            int length = get_word_length(input_file);
            char* word = (char*)malloc(sizeof(char) * length);
            get_word(input_file, word);

            // Make frequency array
            int* freq = (int*)malloc(sizeof(int) * 26);
            calc_frequency(freq, word, length);

            // Write out histogram
            int max = get_max(freq, 27);
            write_histogram(output_file, freq, max);

            free(word);
            free(freq);
            break;
    };
    return 0;
}