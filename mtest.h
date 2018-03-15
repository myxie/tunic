#ifndef MTEST_H
#define MTEST_H
/*Code initially developed from http://www.jera.com/techinfo/jtns/jtn002.html*/

/*Set to 0 if you do not want to time tests/are on Windows*/
#define TIME_TESTS 1

/*A little sugar for the user*/
#define TRUE  1 
#define FALSE 0


#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

#if TIME_TESTS
#include <time.h>
#endif

enum MTEST_output_level{
	BASIC_RESULTS,
	TIME,
	ERRORS_ONLY
};


int tests_run;
int tests_passed;
void MTEST_INIT(void);
// void MTEST_assert_int(int cond, int a, int b);
void MTEST_INT_ARRAY(int cond, int *a, int *b);
void MTEST_CLOSE(void);


/*TODO: WE want to to work like this: 
Separate tests into use cases/functionality 
(like https://github.com/codeplea/minctest)

e.g. 

void test_atoi_function(){
	//Code that runs atoi/returns value 
	MTEST_assert_int(TRUE,...);
	MTEST_assert_int(FALSE,...);
	MTEST_assert_char(TRUE,...);
}

...


int main(){
	m_run_tests();
	etc....

}
*/
// Run timing functions here
#define MTEST_run_test_suite(test_suite_name, mtest_output_level) do {\
	printf("Running tests for: '%s'\n", #test_suite_name);\
	if(mtest_output_level == TIME){\
		test_suite_name();\
	} else{\
		test_suite_name();\
	}\
	printf("Finished test suite\n");\
} while (0)

/* #define run_test(x) do { \
	x;\
} while (0)
start_clock();

    stop_clock();
    TODO Clean up these two lines, they aren't nice
*/
/*#define MTEST_assert_int(assert,a,b) do {\
    if(((a==b) && (assert == TRUE)) || ((a !=b) && (assert == FALSE) )){\
        tests_passed++; \
        status =  1; \
    } else{ \
        status = 0;\
    }\
    tests_run++;\
    test_status(status);\
} while (0)
*/
/*Private function declarations*/
void test_status(int status);
void start_clock();
void stop_clock();

/*Private variable declarations*/
int status;
clock_t start_t;

void MTEST_INIT(void){
    tests_run = 0;
    tests_passed = 0;
}

void MTEST_assert_int(int assert, int a, int b){
    start_clock();
    if(((a==b) && (assert == TRUE)) || ((a !=b) && (assert == FALSE) )){
        tests_passed++;
        status =  1;
    }    
    else{
        status = 0;
    }

    stop_clock();
    //TODO Clean up these two lines, they aren't nice
    tests_run++;
    test_status(status);
}

void MTEST_INT_ARRAY(int assert, int *a, int *b){
    start_clock();
    if(((memcmp(a, b, sizeof(&a)) == 0 ) && (assert ==TRUE)) \
        || ((memcmp(a, b, sizeof(&a)) != 0) && (assert == FALSE))){
         tests_passed++;
         status = 1;
    }
    else{
       status = 0; 
    }
    
    stop_clock(); 
    //TODO Clean up these two lines, they aren't nice
    tests_run++;
    test_status(status);
}

void MTEST_CLOSE(void){
    printf("Passed %d out of %d tests\n", tests_passed, tests_run);     
} 

/*Private mtest functions that are only used in this file*/

void test_status(int status){
    if(status > 0){
        printf("Test %d passed\n", tests_run);    
    }
    else{
        printf("Test %d failed\n", tests_run);    
    }
}

void start_clock(void){
    start_t = clock();
}

void stop_clock(){
    clock_t end_t;
    double seconds;

    end_t = clock();

    seconds = (double)(end_t - start_t)/1000000.f;
    printf("CPU time is %f seconds\n", seconds);
}

#endif