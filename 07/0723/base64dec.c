#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * Function to append Characters to the output string
 * This function takes an integer which will contain 24 bits, denoting 3 characters.
 * It then goes on to extract the three characters one by one and append them to the string
 */
void appendChars(char *input, int x) {

    for (int i = 0; i < 3; ++i) {
        char a = (char) ((x >> ((2 - i) * 8)) & 0xFF);
        strncat(input, &a, 1);
    }
}

/**
 * Simple function to get the predefined integer value of a valid character
 */
int getIntVal(char x) {
    static char b64_arr[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'};

    for (int i = 0; i < 64; ++i) {
        if (b64_arr[i] == x)
            return i;
    }
    return 0;
}

/**
 * Magic happens here.
 * @param input string to be decoded
 * @param inSize size of @param input
 * @param output pointer to output string(char array)
 * @param outSize size of @param output
 */
char *decode_base_64(char *input, int inSize, char *output, int *outSize) {

    // Get the output size based on the size of the input.
    // This may give a size greater than required, in case of Padded codes,
    // but a couple extra bytes of memory are really no loss.
    *outSize = (int) ceil(inSize * 4.0 / 3);
    output = calloc(*outSize, sizeof(char));

    // Extract the characters from input 4 at a time
    for (int i = 0; i < (inSize / 4.0); i++) {
        int x = 0;
        // Get their corresponding B64 value and add them to an int.
        for (int j = 0; j < 4 && input[(i * 4) + j] != '='; ++j) {
            int c = getIntVal(input[(i * 4) + j]);
            x ^= (c << ((3 - j) * 6));
        }
        // Append these to the output string
        appendChars(output, x);
    }
    return output;
}

int main() {
    char *str = "TUFO";
    int strSize = 4;
    char *out;
    int outSize = 0;
    out = decode_base_64(str, strSize, out, &outSize);
    printf("%s %s\n",str, out);
    char *str2 = "TUFOTw==";
    int str2Size = 8;
    char *out2;
    int out2Size = 0;
    out2 = decode_base_64(str2, str2Size, out2, &out2Size);
    printf("%s %s\n",str2, out2);
    char *str3 = "TUFOT04=";
    int str3Size = 8;
    char *out3;
    int out3Size = 0;
    out3 = decode_base_64(str3, str3Size, out3, &out3Size);
    printf("%s %s\n",str2, out3);
}
