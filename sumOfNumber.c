#include "CuTest.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

extern int SumOfNumber(int number) {
    int sum = 0;
    int i;
    for (i=1; i<=number; i++) {
        sum+=i;
    }
    return sum;
}
