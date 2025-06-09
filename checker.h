# include <stdio.h>
# include <ctype.h>


int check(int num) {
    int checker = 0, flag = 1;
    checker = getchar();
    while (flag) {
        flag = 0;
        while (checker != '\n') {
            checker = getchar();
            if (!isdigit(checker)) flag = 1;
        }
        if (flag) {
            printf("ERROR. Enter a integer number (> 0):\ncount = ");
            scanf("%d", &num);
            checker = getchar();
        }
    }
    return num;
}


long double lcheck(long double num) {
    int checker = 0, flag = 1;
    checker = getchar();
    while (flag) {
        flag = 0;
        while (checker != '\n') {
            checker = getchar();
            if (!isdigit(checker) && (checker != '-') && (checker != '.')) flag = 1;
        }
        if (flag) {
            printf("ERROR. Enter a floating point or integer number:\nx = ");
            scanf("%Lf", &num);
            checker = getchar();
        }
    }
    return num;
}