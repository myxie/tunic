#include <stdio.h>
#include <stdlib.h>
#include "ctest.h"

int tests_run, tests_passed = 0;

int main(){
    int x = 1;
    int y = 1; 
    ctest_int_assert(true, x, y);
    
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    ctest_int_array_assert(true, a, b);

    ctest_report();

    return 0;
}
