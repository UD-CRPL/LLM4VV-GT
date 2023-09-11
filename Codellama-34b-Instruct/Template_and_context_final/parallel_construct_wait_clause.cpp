#include "acc_testsuite.h"
#ifndef T1
//T1:parallel construct wait clause,V:2.7-3.3
int test1(){
    int err = 0;
    srand(SEED);

    #pragma acc parallel num_gangs(1) num_workers(1) wait(1)
    {
        // Do some work
    }

    if (acc_get_num_gangs(acc_get_device_type()) != 1 ||
        acc_get_num_workers(acc_get_device_type()) != 1) {
        err = 1;
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