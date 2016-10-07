#ifndef CTEST_H
#define CTEST_H
/*Code initially developed from http://www.jera.com/techinfo/jtns/jtn002.html*/
#include <stdbool.h>
extern int tests_run;
extern int tests_passed;
int ctest_int_assert(bool val, int a, int b);
int ctest_int_array_assert(bool val, int *a, int *b);
int ctest_report(void);
#endif

