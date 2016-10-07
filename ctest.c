#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ctest.h" 

int ctest_int_assert(bool val, int a, int b){
    if((a==b && val) || (a !=b && !val)){
        tests_passed++;
        return 0;
    }
    else{
        return -1;
    }

    tests_run++;
}

int ctest_int_array_assert(bool val, int *a, int *b){
    if(((memcmp(a, b, sizeof(a)) == 0 ) && val) \
            || ((memcmp(a, b, sizeof(a)) != 0) && !val)){
        tests_passed++;
        return 0;
    }
    else{
       return -1; 
    }
    
    tests_run++;
}

int ctest_report(void){
    printf("Passed %d out of %d tests\n", tests_passed, tests_run); 
} 
