#include <stdio.h>
#include <assert.h>
int getBytes(int x, int b) {

    int a = x >> (b << 3);
    return a & 255;

}

int main() {

    assert(getBytes(0x123456, 0) == 0x56);
    assert(getBytes(0x123456, 1) == 0x34);
    
    return 0;
}
