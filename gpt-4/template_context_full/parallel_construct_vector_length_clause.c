#include "acc_testsuite.h"
#ifndef T1
/*T1:parallel construct vector_length clause,V:2.0-2.7*/

#define SIZE 1024
#define VECTOR_LENGTH 256

int test1(){

    int err = 0;
    srand(SEED);
    float a[SIZE], b[SIZE], c[SIZE];

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() / (float)RAND_MAX;
        b[i] = rand() / (float)RAND_MAX;
    }

    #pragma acc parallel vector_length(VECTOR_LENGTH)
    {
        #pragma acc loop vector
        for (int i = 0; i < SIZE; i++) {
          c[i] = a[i] + b[i];
        }
    }

    // Check result
    for (int i = 0; i < SIZE; i++) {
        if (abs(c[i] - (a[i] + b[i])) > 1e-5) {
            err = 1;
            break;
        }
    }

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