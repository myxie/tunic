#include <stdio.h> 
#include <stdlib.h>
#include "ctest.h" 


int tests_run = 0;
char * simple_assert()
{
    int foo = 6;
    ctest_assert("Error, assertion test fails", foo == 7);
    return 0;
}

char * another_assert(){
    int bar = 5;
    ctest_assert("Error, another assertion failed", bar == 6);
}

char * run_tests() {
    ctest_run_test(simple_assert);
    ctest_run_test(another_assert);
    return 0;
}

int main(void) 
{
//    char *result1 = ctest_run_test(simple_assert);
    char *result = run_tests();
    if(result != 0) {
        printf("%s\n", result);
    }
    else { 
        printf("All tests passed\n");
    }

    printf("Tests run: %d\n", tests_run);

}

