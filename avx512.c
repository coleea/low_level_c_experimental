#include <stdio.h>
#include <immintrin.h> // AVX-512 내장 함수를 위한 헤더

void vector_add(float *a, float *b, float *result, int size) {
    for (int i = 0; i < size; i += 16) { // AVX-512는 16개의 float을 동시에 처리
        __m512 va = _mm512_loadu_ps(a + i);
        __m512 vb = _mm512_loadu_ps(b + i);
        __m512 vresult = _mm512_add_ps(va, vb);
        _mm512_storeu_ps(result + i, vresult);
    }
}

int main() {
    float a[16] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
    float b[16] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    float result[16];

    vector_add(a, b, result, 16);

    for (int i = 0; i < 16; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}