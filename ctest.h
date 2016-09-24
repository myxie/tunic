#ifndef CTEST_H
#define CTEST_H
/*Code initially developed from http://www.jera.com/techinfo/jtns/jtn002.html*/

#define ctest_assert(message, test) do{ if(!(test)) {return message;} } while (0)

#define ctest_run_test(test) do{ char *message = test(); tests_run++; \
                                if (message) return message; } while (0) 

extern int tests_run;
#endif
