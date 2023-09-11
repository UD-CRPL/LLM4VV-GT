#include "acc_testsuite.h"

#ifndef T1
//T1:serial construct if clause,V:2.7-3.3
int test1(){
    int err = 0;
    srand(SEED);

    if (acc_get_device_type() == acc_device_host){
        // Execute the region on the host
        err = 1;
    } else {
        // Execute the region on the device
        err = 0;
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