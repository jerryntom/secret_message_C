#include <stdio.h>
#include <math.h>
#include <ctype.h>

int get_char_from_pos(FILE *file, unsigned long int pos) {
    int c;

    if(file == NULL) return -1;
    fseek(file, (long)pos, SEEK_SET);
    c = fgetc(file);
    fseek(file, 0, SEEK_SET);

    return c;
}

unsigned long int get_index(FILE *file, int start_pos, int end_pos, int index_size) {
    unsigned long int index = 0;

    for(int pos = start_pos; pos <= end_pos; pos++) {
        index += (get_char_from_pos(file, pos) - 48) * (int)pow(10, index_size-1);
        index_size--;
    }

    return index;
}

int is_file_corrupted(FILE *file) {
    int c, pos = 0, index_size = 0, c_from_pos;
    unsigned long int index, file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if(file_size == 0) {
        printf("File corrupted");
        fclose(file);
        return 6;
    }

    c = fgetc(file);
    while(c != '\n') {
        if(c == EOF) {
            printf("File corrupted");
            fclose(file);
            return 6;
        }
        c = fgetc(file);
    }
    fseek(file, 0, SEEK_SET);

    c = fgetc(file);
    while(c != '\n' && c != EOF) {
        if(isalpha(c)) {
            printf("File corrupted");
            fclose(file);
            return 6;
        }
        c = fgetc(file);
    }
    fseek(file, 0, SEEK_SET);

    c = fgetc(file);
    while(!isalpha(c)) {
        if(c == ' ' || c == '\n') {
            index = get_index(file, pos - index_size, pos - 1, index_size);
            c_from_pos = get_char_from_pos(file, index);
            if(index > file_size || isdigit(c_from_pos) || ((c_from_pos < 32 || c_from_pos > 126) && c_from_pos != '\n')) {
                printf("File corrupted");
                fclose(file);
                return 6;
            }
            index_size = 0;
        }
        else index_size++;
        pos += 1;
        c = get_char_from_pos(file, pos);
    }
    fseek(file, 0, SEEK_SET);

    return 0;
}

int main(void) {
    FILE *file;
    char file_path[31];
    int c, index_size = 0, pos;
    unsigned long int index;

    printf("File path:");
    scanf("%30[^\n]", file_path);
    while((c = getchar()) != '\n' && c != EOF) {}

    file = fopen(file_path, "r");
    if(file == NULL) {
        printf("Couldn't open file");
        return 4;
    }
    else {
        pos = 0;
        fseek(file, 0, SEEK_SET);
        if(is_file_corrupted(file) == 6) {
            return 6;
        }
        c = fgetc(file);
        while(!isalpha(c)) {
            if(c == ' ' || c == '\n') {
                index = get_index(file, pos - index_size, pos - 1, index_size);
                printf("%c", get_char_from_pos(file, index));
                index_size = 0;
            }
            else index_size++;
            pos += 1;
            c = get_char_from_pos(file, pos);
        }
        fclose(file);
    }

    return 0;
}
