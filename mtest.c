#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mtest.h" 


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

void MTEST_INT(int assert, int a, int b){
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
    if(((memcmp(a, b, sizeof(a)) == 0 ) && (assert ==TRUE)) \
        || ((memcmp(a, b, sizeof(a)) != 0) && (assert == FALSE))){
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
    clock_t end_t, total_t;
    double seconds; 

    end_t = clock();

    seconds = (double)(end_t - start_t)/1000000.f;
    printf("CPU time is %f seconds\n", seconds);
}






