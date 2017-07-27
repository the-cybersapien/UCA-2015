#include <stdio.h>

/**
 *
 * Represent the cards as an 8bit number,
 * use first 4 bits as the number bits, going from 0001 to 1101
 * use the next 2 bits to represent the Suits
 * Spades: 11 (3d)
 * Hearts: 10 (2d)
 * Diamonds: 01 (1d)
 * Clubs: 00 (0d)
 */
void printCard(char c) {

    int cardNumber = c & 0xF;
    int suitNumber = c >> 4;
    printf("Suit: %d, Card: %d\n", suitNumber, cardNumber);
}

char scanCard() {
    char a, b;
    int x, y;
    printf("Enter the card Suit and card number:\n");
    scanf("%d %d", &x, &y);
    a = (char) x;
    b = (char) y;
    return (a << 4) ^ b;
}

int isSameSuit(char a, char b) {
    return !((a>> 4) ^ (b >> 4));
}

int isSame(char a, char b) {
    return !(a ^ b);
}

char isGreater(char a, char b) {
    int sameSuit = isSameSuit(a, b);
    sameSuit = ~sameSuit + 1;
    sameSuit = (sameSuit & ((a & 0xFF) > (b & 0xFF))) | (~sameSuit & ((a >> 4) > (b >> 4)));
    return (sameSuit & a) | (~sameSuit & b);
}

int main() {

    char a = scanCard();
    char b = scanCard();

    printf("isSameSuit: %d\n", isSameSuit(a, b));
    printf("isSame: %d\n", isSame(a, b));
    printf("Greater number:\n");
    printCard(isGreater(a, b));
}
