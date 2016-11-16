#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "ctest.h" 

int ctest_int_assert(int cond, int a, int b){
    if(((a==b) && (cond == TRUE)) || ((a !=b) && (cond == FALSE) )){
        tests_passed++;
        return 0;
    }
    else{
        return -1;
    }

    tests_run++;
}

int ctest_int_array(int cond, int *a, int *b){
    if(((memcmp(a, b, sizeof(a)) == 0 ) && (cond ==TRUE)) \
        || ((memcmp(a, b, sizeof(a)) != 0) && (cond == FALSE))){
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
