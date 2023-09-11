#include "acc_testsuite.h"

#ifndef T1
//T1:loop construct independent clause,V:2.7-3.3
int test1(){
    int err = 0;
    srand(SEED);

    // Initialize arrays
    int a[100];
    int b[100];
    for (int i = 0; i < 100; i++) {
        a[i] = i;
        b[i] = i;
    }

    // Set up loop construct
    #pragma acc loop independent
    for (int i = 0; i < 100; i++) {
        a[i] = b[i];
    }

    // Check results
    for (int i = 0; i < 100; i++) {
        if (a[i] != b[i]) {
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