///Calculate the expression (1 + x) * e^(-x) with a loop for

# include <stdio.h>
# include <math.h>
# include "checker.h"

long double function(long double, int);


int main() {
    long double arg = 0, answer = 0, rightAnswer = 0;
    int accur = 0;

    printf("(1 + x) * e^(-x)\n");

    printf("x = ");
    scanf("%Lf", &arg);
    arg  = lcheck(arg);

    printf("\nEnter count of row members:\ncount = ");
    scanf("%d", &accur);
    accur = check(accur);

    answer = function(arg, accur);
    printf("\nAnswer: %Lf\n", answer);

    rightAnswer = (1 + arg) * expl(-arg);
    printf("Right answer: %Lf\n", rightAnswer);


    return 0;
}


long double function(long double x, int n) {
    long double sumEls = 1, element = 1;

    element *= (-x * x) / 2;
    sumEls += element;

    for (int i = 3; i <= n; i++) {
        element *= (-x * (i - 1)) / (i * (i - 2));
        sumEls += element;
    }

    return sumEls;
}