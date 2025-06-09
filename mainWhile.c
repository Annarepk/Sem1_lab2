///Calculate the expression (1 + x) * e^(-x) with a loop while

# include <stdio.h>
# include <math.h>
# include "checker.h"

long double function(long double, long double, int *);


int main() {
    long double arg = 0, accur = 0, answer = 0, rightAnswer = 0;
    int counter = 1;

    printf("(1 + x) * e^(-x)\n\n");
    printf("x = ");
    scanf("%Lf", &arg);
    arg = lcheck(arg);

    printf("Enter acccurance of count: ");
    scanf("%Lf", &accur);
    accur = lcheck(accur);

    answer = function(arg, accur, &counter);
    printf("\nAnswer: %Lf\n", answer);
    printf("Number of row members: %d\n", counter);

    rightAnswer = (1 + arg) * expl(-arg);
    printf("Right answer: %Lf", rightAnswer);

    return 0;
}


long double function(long double x, long double n, int *count) {
    long double sumEls = 1, element = (-x * x) / 2, lastElement = element, delta = fabsl(element);
    int i = 3;
    sumEls += element;

    while (delta > n) {
        element *= (-x * (i - 1)) / (i * (i - 2));
        sumEls += element;
        delta = fabsl(lastElement - element);
        lastElement = element;
        i++;
        (*count)++;
    }
    return sumEls;
}