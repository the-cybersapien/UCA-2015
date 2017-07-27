#include <stdio.h>
#include <assert.h>

int bang(int a) {
    a = ((a | (~a + 1)) >> 31) & 1;
    return (a & 0) | (~a & 1);
}


int main() {

    assert(bang(-1) == 0);
    assert(bang(12) == 0);
    assert(bang(0) == 1);
    assert(bang(1) == 0);
}
