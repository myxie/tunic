#include "mtest.h"


int test_function(void);


int test_function(void)
{
    return 1;
}

int main(){
    int x = 1;
    int y = 1; 
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    
    /*This call initialises the behind-the-scene counters that provide
     test feedback to the user */
    MTEST_INIT();
    
    MTEST_assert_int(TRUE, x, y);

    y = 2;
    
    MTEST_assert_int(TRUE, test_function(), y); //This should report as a fail 

    MTEST_INT_ARRAY(TRUE, a, b);

    MTEST_CLOSE();

    return 0;
}
