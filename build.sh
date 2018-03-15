# Build file for the example test suite
# Comment/Uncomment the lines for the compiler you are using (e.g. gcc, clang etc.) 

gcc -std=c99 -Wall -Werror -pedantic -I=mtest.h mtest_template.c -o mtest

clang -std=c99 -I=mtest.h mtest_template.c -o clmtest

