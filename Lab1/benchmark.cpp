#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <stdint.h>

uint32_t xorshift32(uint32_t *seed) {
    uint32_t x = *seed;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return *seed = x;
}

void shell_sort(uint32_t *array, int left, int right) {
    int gap, i, j;
    uint32_t temp;
    for (gap = (right - left + 1) / 2; gap > 0; gap /= 2) {
        for (i = left + gap; i <= right; i++) {
            temp = array[i];
            for (j = i; j >= left + gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    clock_t all_time_start = clock();

    const int count = 10000000;
    uint32_t random_seed = 90214;
    double time_spent = 0;
    int part_size = 0;

    uint32_t *array = (uint32_t *) malloc(count * sizeof(uint32_t));

    //printf("OpenMP: %d;\n======\n", _OPENMP);
    const int runs_num = 20;

    int threads = 12;
    for (int i = 0; i < runs_num; i++) {

        for (int i = 0; i < count; i++) {
            array[i] = xorshift32(&random_seed);
        }

        part_size = count / threads;

        clock_t begin = clock();

        #pragma omp parallel num_threads(threads) shared(array, part_size, threads) default(none)
        {
            int thread_id = omp_get_thread_num();
            int left = thread_id * part_size;
            int right = (thread_id == threads - 1) ? count - 1 : (left + part_size - 1);

            shell_sort(array, left, right);
        }
        
        shell_sort(array, 0, count);

        clock_t end = clock();
        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
        int ptr = 1;
        //printf("Seconds spent: %lf\n", time_spent / ptr);
        ptr++;
    }
    // printf("Threads: %d\nSeconds spent: %lf\n", t, time_spent / runs_num);
    time_spent = 0;
    random_seed = 90214;

    clock_t all_time_end = clock();
    double all_time = (double) (all_time_end - all_time_start) / CLOCKS_PER_SEC;

    printf("Seconds spent: %lf\n", all_time);
    return 0;
}