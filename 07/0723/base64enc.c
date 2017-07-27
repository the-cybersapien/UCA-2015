#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void appendChars(char* inp, int x) {
    printf("%d ", x);
    // Take a static array of all the possible characters
    static char b64_arr[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'};
    // Take a static char for = sign, because this is C -.-
    static char eq = '=';
    for(int i = 0; i < 4; i++) {
        // get the required 6 bits in the order, and append them to the output
        unsigned int a = (x >> ((3 - i) * 6)) & 0x3F;
        if (a != 0){
            strncat(inp, &b64_arr[a], 1);
        } else {
            // if all the required bits are 0, then it's probably an ending case
            // where there aren't total 3 bytes for conversion.
            // Add '=' symbol
            strncat(inp, &eq, 1);
        }
    }
}


char* encode_base_64(char* input, int n, char* output, int* outN) {

    // get the size of the output string
    *outN = (int) ceil(n / 3.0) * 4;
    output = (char*) calloc (*outN, sizeof(char));

    for (int i = 0; i < (n / 3.0); i++) {
        // get the ith 3 bits in accordance to the number of characters left.
        int x = input[(i * 3)] << 16;
        if ((i * 3) <= n - 3) {
            printf("3 ");
            x ^= input[(i * 3) + 1] << 8;
            x ^= input[(i * 3) + 2];
        } else if ((i * 3)  == n - 2) {
            printf("2 ");
            x ^= input[i + 1] << 8;
        }
        // use the append char function to actually append data to the string
        appendChars(output, x);
    }

    return output;
}

int main() {

    char* str = "MANO";
    int x = 4;
    int y = 0;
    char* out;
    out = encode_base_64(str, x, out, &y);

    printf("%s\n", out);
   
    char* str1 = "MAN";
    int x1 = 3;
    int y1 = 0;
    char* out1;
    out1 = encode_base_64(str1, x1, out1, &y1);

    printf("%s\n", out1);

    char* str2 = "MANON";
    int x2 = 5;
    int y2 = 0;
    char* out2;
    out = encode_base_64(str2, x2, out2, &y2);

    printf("%s\n", out);



    return 0;
}
