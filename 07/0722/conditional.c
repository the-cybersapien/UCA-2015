#include <stdio.h>

int conditional(int condition, int trueVal, int falseVal) {

    condition = ~condition + 1;

    return (condition & trueVal) | (~condition & falseVal);
}

int main() {

    printf("%d\n", conditional(1, 5, 6));
    printf("%d\n", conditional(0, 5, 6));
}


