#define MTEST_LIBRARY

#include "mtest.h"
/*
If you want to use timing functionalities for linux, use the following definition:
*/
#define TIME_TESTS

//For use in test_assert_int()
int test_function(void){
    return 1;
} 

void test_assert_int(void){
    int x = 1;
    int y = 1;
    int z = 0;

    MTEST_assert_int(TRUE, x, y); // Pass
    y = 2;
    MTEST_assert_int(TRUE, test_function(), y); //This should report as a fail
    MTEST_assert_int(FALSE, x, x); // Fail
    MTEST_assert_int(FALSE, x, z); // Pass
}

void test_assert_array_int(void) {
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    int c[] = {1, 2, 3, 4, 4};

    MTEST_int_array(TRUE, a, b, 5); // Pass
    MTEST_int_array(TRUE, a, c, 5); // Fail
    MTEST_int_array(FALSE, a, b, 5); // Fail
    MTEST_int_array(FALSE, a, c, 5); // Pass
}

void test_assert_float(void) {
    float x = 0.0;
    float y = 0.0;
    float z = 0.1;

    MTEST_assert_float(TRUE, x, y);
    MTEST_assert_float(TRUE, x, z);
    MTEST_assert_float(FALSE, x, y);
    MTEST_assert_float(FALSE, x, z);
}

void test_assert_array_float(void) {
    float a[] = {0.0, 0.1, 0.2};
    float b[] = {0.0, 0.1, 0.2};
    float c[] = {0.0, 0.2, 0.2};

    MTEST_float_array(TRUE, a, b, 3);
    MTEST_float_array(TRUE, a, c, 3);
    MTEST_float_array(FALSE, a, b, 3);
    MTEST_float_array(FALSE, a, c, 3);
}

void test_assert_double(void) {
    double x = 1e-8;
    double y = 1e-8;
    double z = 2e-6;

    MTEST_assert_double(TRUE, x, y);
    MTEST_assert_double(TRUE, x, z);
    MTEST_assert_double(FALSE, x, y);
    MTEST_assert_double(FALSE, x, z);
}

void test_assert_array_double(void) {
    double a[] = {0.0, 1e-8, 1e-8};
    double b[] = {0.0, 1e-8, 1e-8};
    double c[] = {0.0, 1e-6, 1e-8};

    MTEST_double_array(TRUE, a, b, 3);
    MTEST_double_array(TRUE, a, c, 3);
    MTEST_double_array(FALSE, a, b, 3);
    MTEST_double_array(FALSE, a, c, 3);
}

int main(int argc, char *argv[]) {
    MTEST_run_test_suite(test_assert_int, STD_OUTPUT);
    MTEST_run_test_suite(test_assert_array_int, STD_OUTPUT);
    MTEST_run_test_suite(test_assert_float, STD_OUTPUT);
    MTEST_run_test_suite(test_assert_array_float, STD_OUTPUT);
    MTEST_run_test_suite(test_assert_double, STD_OUTPUT);
    MTEST_run_test_suite(test_assert_array_double, STD_OUTPUT);
    return 0;
}
