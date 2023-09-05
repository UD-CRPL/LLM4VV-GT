#ifndef T1
//T1:parallel,async,construct,V:2.5-2.7
int test1(){
    int err = 0;

    int *a = (int *)malloc(n*sizeof(int));
    int *b = (int *)malloc(n*sizeof(int));

    #pragma acc data copyin(a[0:n])
    {
        #pragma acc parallel async
        {
            #pragma acc loop
            for (int x = 0; x < n; ++x){
                b[x] = a[x] + 1;
            }
        }
    }

    #pragma acc wait

    for (int x = 0; x < n; ++x){
        if (b[x] != (a[x] + 1)){
            err += 1;
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