#include <stdio.h>

void vector_add(float *a, float *b, float *result, int size) {
    for (int i = 0; i < size; i += 4) {
        __asm__ (
            "movups (%0), %%xmm0\n\t"
            "movups (%1), %%xmm1\n\t"
            "addps %%xmm1, %%xmm0\n\t"
            "movups %%xmm0, (%2)"
            :
            : "r" (a + i), "r" (b + i), "r" (result + i)
            : "%xmm0", "%xmm1"
        );
    }
}

int main() {
    float a[] = {1.0, 2.0, 3.0, 4.0};
    float b[] = {5.0, 6.0, 7.0, 8.0};
    float result[4];

    vector_add(a, b, result, 4);

    for (int i = 0; i < 4; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}