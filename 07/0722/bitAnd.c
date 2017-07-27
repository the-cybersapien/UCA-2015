#include <stdio.h>
#include <assert.h>

int bitAnd(int a, int b) {
    return ~(~a | ~b);
}

int main() {

    assert(bitAnd(25, 5) == 1);
    assert(bitAnd(4, 2) == 0);
    return 0;

}
