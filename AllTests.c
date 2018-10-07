#include "CuTest.h"
#include <stdio.h>

CuSuite* TestUtilGetSuite();

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    

        CuSuiteAddSuite(suite, TestUtilGetSuite());
        
        CuSuiteRun(suite);
        CuSuiteSummary(suite, output);
        CuSuiteDetails(suite, output);
        printf("%s\n", output->buffer);
}
int main(void) {
    RunAllTests();
}
