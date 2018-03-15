#include "mtest.h"


// int test_function(void);


int test_function(void){
    return 1;
}

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

    MTEST_INT_ARRAY(TRUE, a, b);

}


int main(){
    
    /*This call initialises the 'behind-the-scene' counters that provide
     test feedback to the user */
    MTEST_INIT();

    MTEST_run_test_suite(test_assert_function,BASIC_RESULTS);
    // MTEST_run_test_suite()

    MTEST_CLOSE();

    return 0;
}
