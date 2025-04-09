/* count digits, white space, others */

/*

#include <stdio.h>
int main(void)
{
        int c, i, nwhite, nother;
        // values    ndigit = [13, 47, 9, 3, ...]
        // positions ndigit = [0,   1, 2, 3, 4, 5, 6, 7, 8, 9]
        int ndigit[10];

        nwhite = nother = 0;

        for (i = 0; i < 10; ++i)
                ndigit[i] = 0;

        while ((c = getchar()) != EOF)
                if (c >= '0' && c <= '9') {
                        ++ndigit[c-'0']; 
                        printf("Value of c-'0': %i\n", c-'0');
                }
                else if (c == ' ' || c == '\n' || c == '\t')
                        ++nwhite; // nwhite = nwhite + 1
                else
                        ++nother; // nother = nother + 1
                                  
        printf("digits =");

        for (i = 0; i < 10; ++i)
                printf(" %d", ndigit[i]);

        printf(", white space = %d, other = %d\n",
                        nwhite, nother);
}

*/


/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include<stdio.h>
#define MAX_WORD_LEN 20

int main(void)
{
        int c, len, i, j;
        int nlength[MAX_WORD_LEN];      // declare array nlength of size MAX_WORD_LEN to hold lengths of words seen from input
        /* len = i = j  = 0; */ // possibly conflicting this          

        len = 0;

        for (i = 0; i < MAX_WORD_LEN; ++i) {
                nlength[i] = 0;
        }

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\t' || c == '\n') {
                        if (len <= MAX_WORD_LEN) {
                                ++nlength[len];
                                len = 0;
                        } else {
                                ++len;
                        }
                }
        }

        for (i = 0; i < MAX_WORD_LEN; ++i) {      // Changed ++i from i++ and it fixed //
                printf("%2d ", i);

                for (j = 0; j < nlength[i]; ++j) {
                        printf("|");
                }
                printf("\n");
        }

}


/*

include <stdio.h>


#define MAXWLENGTH 20

int main(void)
{
        int c, wlen, i, x;
        int lengths[MAXWLENGTH];

        wlen = 0;

        for (i = 0; i < MAXWLENGTH; ++i) {
                lengths[i] = 0;
        }

        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' || c == '\t') {
                        if (wlen <= MAXWLENGTH) {
                                ++lengths[wlen];
                                wlen = 0;
                        }
                } else {
                        ++wlen;
                }
        }

        for (i = 0; i < MAXWLENGTH; ++i) {
                printf("%2d ", i);

                for (x = 0; x < lengths[i]; ++x) {
                        printf("|");
                }
                printf("\n");
        }

        return 0;
}
*/

