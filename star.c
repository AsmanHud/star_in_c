#include <stdio.h>
#include <stdint.h>

// the main idea here is to count the leading "outer" spaces
// and the symbols + spaces after
// n_sym_and_inner_spaces is for the symbols and inner spaces
// and n_outer_spaces is for the leading spaces that shape the star

// this function prints a single line of the star
void star_for_loop(int16_t n_sym_and_inner_spaces, int16_t max, uint8_t sym, uint8_t spacesym) {
    int16_t j;
    int16_t n_outer_spaces = (max - n_sym_and_inner_spaces) / 2;
    for (j = 0; j < n_outer_spaces; j++) {
        printf("%c", spacesym);
    }
    for (j = 0; j < n_sym_and_inner_spaces; j++) {
        printf("%c%c", sym, spacesym);
    }
    printf("\n");
}

// this function uses the one above to print the star shape
void star(int16_t size, uint8_t sym, uint8_t spacesym) {
    int16_t i;
    int16_t max = size * 2 - 1;
    for (i = 1; i < max; i += 2) {
        star_for_loop(i, max, sym, spacesym);
    }
    for (i = max; i > 0; i -= 2) {
        star_for_loop(i, max, sym, spacesym);
    }
}

int main() {
    uint8_t c = '*';
    uint8_t space = '\t';
    star(1, c, space);
    star(2, c, space);
    star(3, c, space);
    star(4, c, space);
    return 0;
}