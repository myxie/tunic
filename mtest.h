/*Code initially developed from http://www.jera.com/techinfo/jtns/jtn002.html*/

#ifndef MTEST_H
#define MTEST_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
/*
	Define TIME_TESTS in your test file if you want
	to use the timing functions
*/
#ifdef TIME_TESTS
#include <time.h>
#endif
/*
	TESTING API

	All public API functions have MTEST in capitals 
	prepended to the function. Functions with lower case mtest_
	are helper functions within the header file. 
*/

void MTEST_assert_int(int cond, int a, int b);
void MTEST_int_array(int cond, int *a, int *b);

/*
	PUBLIC VARIABLES FOR USER
	Defining TRUE and FALSE makes things easier, and 
	means we do not need to use booleans
*/

#define TRUE  1 
#define FALSE 0

enum MTEST_output_level{
	STD_OUTPUT,
	TIME
};

/*
	The end of the header file! 
*/
#endif //MTEST_H

/*
	IMPLEMENTATION 
*/

#ifdef MTEST_LIBRARY

int test_status;
int tests_run;
int tests_passed;

#ifdef TIME_TESTS
clock_t start_t;
#endif

/*
	Private helper functions 
*/
void mtest_update_test_status(int test_status);
void mtest_init(void);
void mtest_close(void);


/*
	MTEST_run_test_suite: Macro that runs a test suite, which 
	is simply a function with no return value that separates different
	'suites' of tests (based on the users preferred logical/functional
	separation). Accepts optional output condition that affects how
	test results are displayed to the user.
*/ 
#define MTEST_run_test_suite(test_suite_name, mtest_output_level) do {\
	printf("Running tests for: '%s'\n", #test_suite_name);\
	mtest_init();\
	if(mtest_output_level == TIME){\
		test_suite_name();\
	} else{\
		test_suite_name();\
	}\
	mtest_close();	\
	printf("Finished test suite\n\n");\
} while (0)


void MTEST_assert_int(int assert, int a, int b){
    if(((a==b) && (assert == TRUE)) || ((a !=b) && (assert == FALSE) )){
        tests_passed++;
        test_status =  1;
    }    
    else{
        test_status = 0;
    }
    mtest_update_test_status(test_status);
}

void MTEST_int_array(int assert, int *a, int *b){
    if(((memcmp(a, b, sizeof(&a)) == 0 ) && (assert ==TRUE)) \
        || ((memcmp(a, b, sizeof(&a)) != 0) && (assert == FALSE))){
         tests_passed++;
         test_status = 1;
    }
    else{
       test_status = 0; 
    }

    mtest_update_test_status(test_status);
}

/*
	Timing Functions
*/

#ifdef TIME_TESTS
void MTEST_start_timer(void){
    start_t = clock();
}

void MTEST_stop_timer(){
    clock_t end_t;
    double seconds;

    end_t = clock();

    seconds = (double)(end_t - start_t)/1000000.f;
    printf("CPU time is %f seconds\n", seconds);
}
#endif //TIME_TESTS

/*
	Private mtest functions that are only used in this file
*/

void mtest_init(void){
    tests_run = 0;
    tests_passed = 0;
}

void mtest_close(void){
    printf("Passed %d out of %d tests\n", tests_passed, tests_run);     
} 


void mtest_update_test_status(int test_status){
   	tests_run++;
    if(test_status > 0){
        printf("Test %d passed\n", tests_run);    
    }
    else{
        printf("Test %d failed\n", tests_run);    
    }
}

#endif //MTEST_LIBRARY

