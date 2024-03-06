#include "acc_testsuite.h"

#ifndef T1
//T1:compute construct self clause,V:2.7-3.3
int test1(){
    int err = 0;
    srand(SEED);

    int N = 100;
    int *data = (int*)malloc(N * sizeof(int));
    int sum = 0;
    int local_sum = 0;

    // Initialize data
    for(int i = 0; i < N; i++) {
        data[i] = rand() % 100;
        sum += data[i];
    }

    // Compute sum with self clause
    #pragma acc data copy(data[0:N])
    {
        #pragma acc parallel loop
        for(int i = 0; i < N; i++) {
            local_sum += data[i];
        }
    }

    // Check if the sums are equal
    if(sum != local_sum) {
        err++;
        printf("Error: Sum is %d, but local sum is %d\n", sum, local_sum);
    }

    free(data);

    return err;
}
#endif

int main(){
    int failcode = 0;
    int failed;
#ifndef T1
    failed = 0;
    for (int x = 0; x < NUM_TEST_CALLS; ++x){
        failed = failed + test1();
    }
    if (failed != 0){
        failcode = failcode + (1 << 0);
    }
#endif
    return failcode;
}