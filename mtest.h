#ifndef CTEST_H
#define CTEST_H
/*Code initially developed from http://www.jera.com/techinfo/jtns/jtn002.html*/

#define TRUE  1 
#define FALSE 0

int tests_run;
int tests_passed;
void MTEST_INIT(void);
void MTEST_INT(int cond, int a, int b);
void MTEST_INT_ARRAY(int cond, int *a, int *b);
void MTEST_CLOSE(void);
#endif

