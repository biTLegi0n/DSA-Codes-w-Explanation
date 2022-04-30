#include <bits/stdc++.h>
using namespace std;

/**
 * @brief  This question wasted a lot of time. I literally spent hours on this problem even after knowing the logic.
 *         Well, we jsut need to take care of a few test cases.
           There can be three different types of inputs that need to be handled separately.

            - The input number is palindrome and has all 9s. For example “9 9 9”. Output should be “1 0 0 1”
            - The input number is not palindrome. For example “1 2 3 4”. Output should be “1 3 3 1”
            - The input number is palindrome and doesn’t have all 9s. For example “1 2 2 1”. Output should be “1 3 3 1”.

            -> Solution for input type 1 is easy. The output contains n + 1 digits where the corner digits are 1,
            and all digits between corner digits are 0.

            -> Now let us first talk about input type 2 and 3. How to convert a given number to a greater palindrome?

            To understand the solution, let us first define the following two terms:

            |Left Side| : The left half of given number. Left side of “1 2 3 4 5 6” is “1 2 3” and left side of “1 2 3 4 5” is “1 2”
            |Right Side|: The right half of given number. Right side of “1 2 3 4 5 6” is “4 5 6” and right side of “1 2 3 4 5” is “4 5”

            To convert to palindrome, we can either take the mirror of its left side or take mirror of its right side. However, if we
            take the mirror of the right side, then the palindrome so formed is not guaranteed to be next larger palindrome.
            So, we must take the mirror of left side and copy it to right side. But there are some cases that must be handled in different ways.
            We will start with two indices i and j. i pointing to the two middle elements (or pointing to two elements around the middle
            element in case of n being odd). We one by one move i and j away from each other.


 *
 */


bool is9(string &str, int pos) {
    if (pos < 0 or pos >= str.size() or str[pos] != '9') return false;
    else return true;
}

string solve(string A) {
    string bkp = A;
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        if (A[l] != A[r]) {
            A[r] = A[l];
        }
        l++, r--;
    }

    if (A > bkp) return A;

    l--, r++;

    while (is9(A, l)) {
        A[l] = '0';
        A[r] = '0';
        l--, r++;
    }

    // iF there are no 9s in the number, then at this point, both l and r are at mid.
    if (l >= 0) { // if L is >= 0 then R is < str.size() always
        A[l] += 1;
        A[r] = A[l];
    } else { // we enter here if our number is full of 9s. e.g. "99999"
        A[0] = '1';
        A += '1';
    }

    return A;
}