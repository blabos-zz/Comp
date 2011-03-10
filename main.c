#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLS     4
#define STATES      3

int* get_matrix() {
    int* matrix = (int*) malloc(SYMBOLS * STATES * sizeof(int));

    if (matrix) {
        matrix[0] = 0;
        matrix[1] = 1;
        matrix[2] = 2;
        matrix[3] = -1;
        matrix[4] = 2;
        matrix[5] = -1;
        matrix[6] = 2;
        matrix[7] = 0;
        matrix[8] = -1;
        matrix[9] = 1;
        matrix[10] = 1;
        matrix[11] = 1;
    }

    return matrix;
}

void print_matrix(int* matrix, int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("%d ", matrix[i + j * x]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int i, j, count;

    char symbols[SYMBOLS] = { 'a', 'b', 'c', 'd' };
    char* states[STATES] = { "e0", "e1", "e2" };

    int* mat = get_matrix();
    printf("int main(int argc, char** argv) {\n");
    printf("    int curr  = -1;\n");
    printf("    char* str = argv[1];\n");

    for (i = 0; i < STATES; i++) {
        printf("\n    %s:\n         curr++;\n", states[i]);
        count = 0;
        for (j = 0; j < SYMBOLS; j++) {
            if (mat[i + j * STATES] != -1) {
                if (count > 0)
                    printf("    else ");
                else
                    printf("         ");
                count++;
                printf("if(str[curr] == '%c') goto %s;\n", symbols[j],
                        states[mat[i + j * STATES]]);
            }
        }
        if (count > 0) printf("    else ");
        else printf("    ");
        printf("goto error;\n");
    }
    printf("\n    error:\n        return -1;\n");
    printf("\n    success:\n        return 0;\n}\n");

    return EXIT_SUCCESS;
}
