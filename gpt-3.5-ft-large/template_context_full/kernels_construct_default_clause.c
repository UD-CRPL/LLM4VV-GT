#include "acc_testsuite.h"
#ifndef T1
//T1:kernels construct default clause,V:2.7-3.3
int test1(){
    int err = 0;
    srand(SEED);

    if(0){
        int device = 0;
        #pragma acc data copyin(device: 1)
        while(acc_get_device_num(acc_get_device_type()) == device)
        {
            #pragma acc parallel
            {}
            device++;
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