//Suthang Sukrueangkun
//67070503477

#include<stdio.h>
#include<stdlib.h>

int main(void) {

    int d, c, h;
    float max = -9999;
    float dd;

    scanf("%d %d %d", &d, &c, &h);

    float ***data = (float***) malloc(d * sizeof(float**));

    for (int i = 0; i < d; i++) {
        data[i] = (float**) malloc(c * sizeof(float*));

        for (int j = 0; j < c; j++) {
            data[i][j] = (float*) malloc(h * sizeof(float));
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < h; k++) {
                scanf("%f", &data[i][j][k]);
                max = max >= data[i][j][k] ? max : data[i][j][k];
            }
        }
    }

    float avg = 0;

    for (int i = 0; i < d; i++) {
        printf("Day %d:\n", i + 1);
        for (int j = 0; j < c; j++) {
            printf("City %d: ", j + 1);
            for (int k = 0; k < h; k++) {
                printf("%.2f ", data[i][j][k]);
            }
            printf("\n");
        }
    }

    printf("Average Temperature for Each City:\n");

    for (int i = 0; i < c; i++) {
        printf("City %d: ", i + 1);
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < h; k++) {
                avg += data[j][i][k];
                // printf("%.2f ", data[j][i][k]);
            }
        }
        printf("%.2f\n", avg / (float) (d * h));
        avg = 0;
    }

    printf("Maximum Temperature Recorded: %.2f", max);

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            free(data[i][j]);
        }

        free(data[i]);
    }

    free(data);


    return 0;
}
