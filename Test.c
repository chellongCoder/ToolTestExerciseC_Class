 #include "CuTest.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char* StrToUpper(char* str) {
    char* p;
    for (p = str ; *p ; ++p) *p = toupper(*p);
    return str;
}

int SumOfNumberInteger(int number) {
    int sum = 0;
    int i;
    for (i=1; i<=number; i++) {
        sum+=i;
    }
    return sum;
}

float SumOfNumberDouble(float number) {
    float sum = 0;
    int i;
    for (i=1; i<=number; i++) {
        sum+=(float)1/i;
    }
//    printf("sum=%f", sum);
    return sum;
}
    void TestStr(CuTest *tc) {
        char input[50];
        char test[20];
        printf("nhap test case : ");
        gets(test);
        gets(input);
        printf("testcase> %s\n", input);
//        fflush(stdin);
        char* actual = StrToUpper(input);
        char expected[50];
        printf("nhap ket qua mong doi : ");
        gets(expected);
        printf("expected> %s", expected);
        CuAssertStrEquals(tc, expected, actual);
    }


void TestSumOfNumberInteger(CuTest *tc) {
    int input;
    FILE *fp;
    fp=fopen("sumOfNumber.c","r");
    printf("input> ");
    scanf("%d", &input);
    int actual = SumOfNumberInteger(input);
    int expected;
    printf("expected> ");
    scanf("%d", &expected);
    CuAssertIntEquals(tc, expected, actual);
}

void TestSumOfNumberDouble(CuTest *tc) {
    float input;
    printf("input> ");
    scanf("%f", &input);
    float actual = SumOfNumberDouble(input);
    float expected;
    printf("expected> ");
    scanf("%f", &expected);
    CuAssertDblEquals(tc, expected, actual, 1);
}
   
    CuSuite* TestUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        printf("you choice input that is typeof integer | float | string? \n");
        int choice;
        printf("======Menu=======\n");
        printf("1. integer\n");
         printf("2. float\n");
         printf("3. string\n");
         printf("CHOICE> ");
        scanf("%d", &choice);
//        fflush(stdin);
        switch (choice) {
            case 1:
                SUITE_ADD_TEST(suite, TestSumOfNumberInteger);
                break;
            case 2:
                SUITE_ADD_TEST(suite, TestSumOfNumberDouble);
                break;
            case 3:
                SUITE_ADD_TEST(suite, TestStr);
                break;
            default:
                break;
        }
//        SUITE_ADD_TEST(suite, TestSumOfNumberDouble);
        return suite;
    }
