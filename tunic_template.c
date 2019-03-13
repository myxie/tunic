/**
Copyright (C) 2018 RW Bunney, N Pritchard

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.  
**/

#define TUNIC_LIBRARY

#include "tunic.h"
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

    tunic_ASSERT_int(TRUE, x, y); // Pass
    y = 2;
    tunic_ASSERT_int(TRUE, test_function(), y); //This should report as a fail
    tunic_ASSERT_int(FALSE, x, x); // Fail
    tunic_ASSERT_int(FALSE, x, z); // Pass
}

void test_almost_int(void) {
    int x = 1;
    int y = 1;
    int z = 0;

    tunic_ALMOST_int(TRUE, x, y, 0); // Pass
    tunic_ALMOST_int(TRUE, x, z, 0); // Fail
    tunic_ALMOST_int(FALSE, x, y, 0); // Fail
    tunic_ALMOST_int(TRUE, x, z, 1); // Pass
}

void test_assert_array_int(void) {
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    int c[] = {1, 2, 3, 4, 4};

    tunic_ASSERT_int_array(TRUE, a, b, 5); // Pass
    tunic_ASSERT_int_array(TRUE, a, c, 5); // Fail
    tunic_ASSERT_int_array(FALSE, a, b, 5); // Fail
    tunic_ASSERT_int_array(FALSE, a, c, 5); // Pass
}

void test_almost_array_int(void){
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    int c[] = {1, 2, 3, 4, 4};

    tunic_ALMOST_int_array(TRUE, a, b, 5, 1); // Pass
    tunic_ALMOST_int_array(TRUE, a, c, 5, 0); // Fail
    tunic_ALMOST_int_array(FALSE, a, b, 5, 1); // Fail
    tunic_ALMOST_int_array(FALSE, a, c, 5, 0); // Pass
    tunic_ALMOST_int_array(TRUE, a, c, 5, 2); // Pass
    tunic_ALMOST_int_array(FALSE, a, c, 5, 2); // Fail
}

void test_assert_float(void) {
    float x = 0.0;
    float y = 0.0;
    float z = 0.1;

    tunic_ASSERT_float(TRUE, x, y); // Pass
    tunic_ASSERT_float(TRUE, x, z); // Fail
    tunic_ASSERT_float(FALSE, x, y); // Pass
    tunic_ASSERT_float(FALSE, x, z); // Pass
}

void test_almost_float(void){
    float x = 0.0;
    float y = 1.0;
    float z = 0.1;

    tunic_ALMOST_float(TRUE, x, y, 1.0); // Pass
    tunic_ALMOST_float(FALSE, x, y, 1.0); // Pass
    tunic_ALMOST_float(TRUE, x, z, 0.05); // Fail
    tunic_ALMOST_float(FALSE, x, z, 0.05); // Fail
}

void test_assert_array_float(void) {
    float a[] = {0.0, 0.1, 0.2};
    float b[] = {0.0, 0.1, 0.2};
    float c[] = {0.0, 0.2, 0.2};

    tunic_ASSERT_float_array(TRUE, a, b, 3); // Pass
    tunic_ASSERT_float_array(TRUE, a, c, 3); // Fail
    tunic_ASSERT_float_array(FALSE, a, b, 3); // Fail
    tunic_ASSERT_float_array(FALSE, a, c, 3); // Pass
}

void test_almost_array_float(void){
    float a[] = {0.0, 0.1, 0.2};
    float b[] = {0.0, 0.1, 0.2};
    float c[] = {0.0, 0.2, 0.2};
    float d[] = {0.0, 0.5, 0.2};

    tunic_ALMOST_float_array(TRUE, a, b, 3, 0.05); // Pass
    tunic_ALMOST_float_array(TRUE, a, c, 3, 0.05); // Fail
    tunic_ALMOST_float_array(FALSE, a, b, 3, 0.1); // Fail
    tunic_ALMOST_float_array(FALSE, a, c, 3, 0.1); // Fail
    tunic_ALMOST_float_array(TRUE, a, d, 3, 1.0); // Pass
    tunic_ALMOST_float_array(FALSE, a, d, 3, 1.0); // Fail
    tunic_ALMOST_float_array(TRUE, a, d, 3, 0.05); // Fail
    tunic_ALMOST_float_array(FALSE, a, d, 3, 0.05); // Pass
}

void test_assert_double(void) {
    double x = 1e-8;
    double y = 1e-8;
    double z = 2e-6;

    tunic_ASSERT_double(TRUE, x, y); // Pass
    tunic_ASSERT_double(TRUE, x, z); // Fail
    tunic_ASSERT_double(FALSE, x, y); // Fail
    tunic_ASSERT_double(FALSE, x, z); // Pass
}

void test_almost_double(void){
    double x = 1e-8;
    double y = 1e-8;
    double z = 2e-6;

    tunic_ALMOST_double(TRUE, x, y, 1e-7); // Pass
    tunic_ALMOST_double(FALSE, x, y, 1e-8); // Fail
    tunic_ALMOST_double(FALSE, x, z, 1e-8); // Pass
    tunic_ALMOST_double(TRUE, x, z, 1e-8); // Fail
}

void test_assert_array_double(void) {
    double a[] = {0.0, 1e-8, 1e-8};
    double b[] = {0.0, 1e-8, 1e-8};
    double c[] = {0.0, 1e-6, 1e-8};

    tunic_ASSERT_double_array(TRUE, a, b, 3); // Pass
    tunic_ASSERT_double_array(TRUE, a, c, 3); // Fail
    tunic_ASSERT_double_array(FALSE, a, b, 3); // Fail
    tunic_ASSERT_double_array(FALSE, a, c, 3); // Pass
}

void test_almost_array_double(void){
    double a[] = {0.0, 1e-8, 1e-8};
    double b[] = {0.0, 1e-8, 1e-8};
    double c[] = {0.0, 1e-6, 1e-8};
    double d[] = {0.0, 1e-2, 1e-8};

    tunic_ALMOST_double_array(TRUE, a, b, 3, 1e-9); // Pass
    tunic_ALMOST_double_array(TRUE, a, c, 3, 1e-9); // Fail
    tunic_ALMOST_double_array(FALSE, a, b, 3, 1e-4); // Fail
    tunic_ALMOST_double_array(FALSE, a, c, 3, 1e-4); // Fail
    tunic_ALMOST_double_array(TRUE, a, d, 3, 1.0); // Pass
    tunic_ALMOST_double_array(FALSE, a, d, 3, 1.0); // Fail
    tunic_ALMOST_double_array(TRUE, a, d, 3, 1e-8); // Fail
    tunic_ALMOST_double_array(FALSE, a, d, 3, 1e-8); // Pass
}

void test_boolean(void){
    int a = TRUE;
    int b = FALSE;
    int c = TRUE;

    tunic_ASSERT_bool(TRUE, a, b); // Fail
    tunic_ASSERT_bool(FALSE, a, b); // Pass
    tunic_ASSERT_bool(TRUE, a, c); // Pass
    tunic_ASSERT_bool(FALSE, a, c); // Fail
}

void test_boolean_array(void){
    int a[] = {TRUE, TRUE, TRUE, TRUE, TRUE};
    int b[] = {TRUE, TRUE, TRUE, TRUE, TRUE};
    int c[] = {TRUE, TRUE, TRUE, TRUE, FALSE};

    tunic_ALMOST_int_array(TRUE, a, b, 5, 1); // Pass
    tunic_ALMOST_int_array(TRUE, a, c, 5, 0); // Fail
    tunic_ALMOST_int_array(FALSE, a, b, 5, 1); // Fail
    tunic_ALMOST_int_array(FALSE, a, c, 5, 0); // Pass
    tunic_ALMOST_int_array(TRUE, a, c, 5, 2); // Pass
    tunic_ALMOST_int_array(FALSE, a, c, 5, 2); // Fail
}

void main(int argc, char *argv[]) {
    tunic_run_test_suite(test_assert_int, STD_OUTPUT);
    tunic_run_test_suite(test_almost_int, STD_OUTPUT);
    tunic_run_test_suite(test_assert_array_int, STD_OUTPUT);
    tunic_run_test_suite(test_almost_array_int, STD_OUTPUT);

    tunic_run_test_suite(test_assert_float, STD_OUTPUT);
    tunic_run_test_suite(test_almost_float, STD_OUTPUT);
    tunic_run_test_suite(test_assert_array_float, STD_OUTPUT);
    tunic_run_test_suite(test_almost_array_float, STD_OUTPUT);

    tunic_run_test_suite(test_assert_double, STD_OUTPUT);
    tunic_run_test_suite(test_almost_double, STD_OUTPUT);
    tunic_run_test_suite(test_assert_array_double, STD_OUTPUT);
    tunic_run_test_suite(test_almost_array_double, STD_OUTPUT);

    tunic_run_test_suite(test_boolean, STD_OUTPUT);
    tunic_run_test_suite(test_boolean_array, STD_OUTPUT);
    // return 0;
}
