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
        freq[word[i]-97]++;
    }
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

            printf("%s\n", word);
            for(int i = 0; i < length; i++) {
                printf("%c", word[i]);
            }

            // Make frequency array
            int* freq = (int*)malloc(sizeof(int) * 26);
            calc_frequency(freq, word, length);

            for(int i = 0; i < 27; i++) {
                printf("%d \n", freq[i]);
            }

            free(word);
            free(freq);
            break;
    };
    return 0;
}