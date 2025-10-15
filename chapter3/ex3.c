/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading or trailing - is taken literally. 
 * 
Unexpanded:  a-z
Expanded  : abcdefghijklmnopqrstuvwxyz
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This function expands shorthand notations (e.g., 'a-z', '0-9')
 * found in string s1 into the full, uncompressed list in s2.
 *
 * It handles:
 * - Lowercase letter ranges (e.g., a-f)
 * - Uppercase letter ranges (e.g., A-F)
 * - Digit ranges (e.g., 0-9)
 * - Multiple ranges in a single string (e.g., a-z0-9)
 * - A leading or trailing '-' is treated as a literal character
 * - Ranges like 'a-c-e' are expanded correctly as 'abce'
 */

void expand(char s1[], char s2[]) {
	int i, j, k;
	char start, end;

	// Initialize the destination string index and the source string index
	j = 0;
	i = 0;

	// Check for a leading literal hyphen
	if (s1[i] == '-') {
		s2[j++] = s1[i++];
	}

	// Loop through the rest of the source string
	while (s1[i] != '\0') {
		// Look ahead to check for a range pattern: char, hyphen, char
		if (s1[i+1] == '-' && s1[i+2] != '\0') {
			start = s1[i];
			end = s1[i+2];

			// Check if it's a valid range (same type and start <= end)
			if ((isdigit(start) && isdigit(end)) ||
					(islower(start) && islower(end)) ||
					(isupper(start) && isupper(end))) {

				// If it's a valid range, expand it
				if (start <= end) {
					for (k = start; k <= end; k++) {
						s2[j++] = k;
					}
				} else {
					// If the range is reversed (e.g. z-a), just copy the characters
					s2[j++] = s1[i];
					s2[j++] = s1[i+1];
					s2[j++] = s1[i+2];
				}

				// Move source string index past the range pattern
				i += 3;
			} else {
				// Not a valid range, just copy the current character
				s2[j++] = s1[i++];
			}
		} else {
			// Not a range, just copy the current character
			s2[j++] = s1[i++];
		}
	}
	// Add a null terminator to the end of the new string
	s2[j] = '\0';
}

int main(void)
{
	char *s[] = {"a-z", "1-6", "a-e", "a-r-L", "1-9-1", "5-5", "z-a", NULL }; // index 8 is past the array
	// s1 = "a-z"
	// s2 = "1-6"
	// s3 = "a-e"
	char result[100];
	int i = 0;

	while (s[i]) { //  NULL[0]
		expand(s[i], result);
		printf("Unexpanded: %s\n", s[i]);
		printf("Expanded  : %s\n", result);
		++i;
	}
	return 0;
}
