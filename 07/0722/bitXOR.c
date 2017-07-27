#include <stdio.h>
#include <assert.h>

int bitXOR(int a, int b) {

    int x = (~a) & b;
    int y = (~b) & a;

    return ~(~x & ~y);
}


int main() {

    assert(bitXOR(4, 15) == 11);
    assert(bitXOR(23, 33) == 54);

    return 0;
}
