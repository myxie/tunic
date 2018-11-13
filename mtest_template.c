#define MTEST_LIBRARY
#include "mtest.h"

/*
If you want to use timing functionalities for linux, use the following definition:
*/
#define TIME_TESTS


void test_assert_function(void){
    int x = 1;
    int y = 1; 

    MTEST_assert_int(TRUE, x, y);
    y = 2;
    MTEST_assert_int(TRUE, test_function(), y); //This should report as a fail 
}

void test_assert_array(void){
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};

    MTEST_int_array(TRUE, a, b);
}


int main(){
    
    MTEST_run_test_suite(test_assert_function,STD_OUTPUT);
    MTEST_run_test_suite(test_assert_array, STD_OUTPUT);
    return 0;
}
