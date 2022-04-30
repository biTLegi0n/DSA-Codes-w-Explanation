/**
 * @file Hacks_For_BitManip.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-07-04
 *
 * @copyright Copyright (c) 2021
 *
 *
It is recommended to refer Interesting facts about Bitwise Operators as a prerequisite.
1. How to set a bit in the number ‘num’ :
If we want to set a bit at nth position in number ‘num’ ,it can be done using ‘OR’ operator( | ).


    First we left shift ‘1’ to n position via (1<<n)
    Then, use ‘OR’ operator to set bit at that position.’OR’ operator is used because it will set the bit even if the bit is unset previously in binary representation of number ‘num’.

** n&(n-1) Finds set bit of n and ands it with set bit of n-1.
    n & (n - 1) drops the lowest set bit. It's a neat little bit trick.

    Let's use n = 00101100 as an example. This binary representation has three 1s.

    If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.

    If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.

    If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.

    n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.

#include<iostream>
using namespace std;
// num is the number and pos is the position
// at which we want to set the bit.
void set(int & num,int pos)
{
     // First step is shift '1', second
     // step is bitwise OR
     num |= (1 << pos);
}
int main()
{
     int num = 4, pos = 1;
     set(num, pos);
     cout << (int)(num) << endl;
     return 0;
}

Output:

6

We have passed the parameter by ‘call by reference’ to make permanent changes in the number.
2. How to unset/clear a bit at n’th position in the number ‘num’ :


Suppose we want to unset a bit at nth position in number ‘num’ then we have to do this with the help of ‘AND’ (&) operator.




    First we left shift ‘1’ to n position via (1<<n) than we use bitwise NOT operator ‘~’ to unset this shifted ‘1’.
    Now after clearing this left shifted ‘1’ i.e making it to ‘0’ we will ‘AND'(&) with the number ‘num’ that will unset bit at nth position position.



#include <iostream>
using namespace std;
// First step is to get a number that  has all 1's except the given position.
void unset(int &num,int pos)
{
    //Second step is to bitwise and this  number with given number
    num &= (~(1 << pos));
}
int main()
{
    int num = 7;
    int  pos = 1;
    unset(num, pos);
    cout << num << endl;
    return 0;
}

Output: 5


3.  Toggling a bit at nth position :
Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.We will be using ‘XOR’ operator here which is this ‘^’. The reason behind ‘XOR’ operator is because of its properties.


    Properties of ‘XOR’ operator.
        1^1 = 0
        0^0 = 0
        1^0 = 1
        0^1 = 1
    If two bits are different then ‘XOR’ operator returns a set bit(1) else it returns an unset bit(0).



#include <iostream>
using namespace std;
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num,int pos)
{
    num ^= (1 << pos);
}
int main()
{
    int num = 4;
    int pos = 1;
    toggle(num, pos);
    cout << num << endl;
    return 0;
}

Output: 6



4. Checking if bit at nth position is set or unset:

It is quite easily doable using ‘AND’ operator.

    Left shift ‘1’ to given position and then ‘AND'(‘&’).

#include <iostream>
using namespace std;

bool at_position(int num,int pos)
{
    bool bit = num & (1<<pos);
    return bit;
}

int main()
{
    int num = 5;
    int pos = 0;
    bool bit = at_position(num, pos);
    cout << bit << endl;
    return 0;
}

Output: 1


Observe that we have first left shifted ‘1’ and then used ‘AND’ operator to get bit at that position. So if there is ‘1’ at position ‘pos’ in ‘num’, then after ‘AND’ our variable ‘bit’ will store ‘1’ else if there is ‘0’ at position ‘pos’ in the number ‘num’ than after ‘AND’ our variable bit will store ‘0’.

Some more quick hacks:


    Inverting every bit of a number/1’s complement:


If we want to invert every bit of a number i.e change bit ‘0’ to ‘1’ and bit ‘1’ to ‘0’.We can do this with the help of ‘~’ operator. For example : if number is num=00101100 (binary representation) so ‘~num’ will be ‘11010011’.

This is also the ‘1s complement of number’.


#include <iostream>
using namespace std;
int main()
{
    int num = 4;

    // Inverting every bit of number num
    cout << (~num);
    return 0;
}

Output: -5


    Two’s complement of the number: 2’s complement of a number is 1’s complement + 1.

So formally we can have 2’s complement by finding 1s complement and adding 1 to the result i.e (~num+1) or what else we can do is using ‘-‘ operator.

#include <iostream>
using namespace std;
int main()
{
    int num = 4;
    int twos_complement = -num;
    cout << "This is two's complement " << twos_complement << endl;
    cout << "This is also two's complement " << (~num+1) << endl;
    return 0;
}

Output:
This is two's complement -4
This is also two's complement -4



    Stripping off the lowest set bit :


In many situations we want to strip off the lowest set bit for example in Binary Indexed tree data structure, counting number of set bit in a number.

We do something like this:


X = X & (X-1)

But how does it even work ?
Let us see this by taking an example, let X = 1100.
(X-1)  inverts all the bits till it encounter lowest set ‘1’ and it also invert that lowest set ‘1’.
X-1 becomes 1011. After ‘ANDing’ X with X-1 we get lowest set bit stripped.


#include <iostream>
using namespace std;
void strip_last_set_bit(int &num)
{
    num = num & (num-1);
}
int main()
{
    int num = 7;
    strip_last_set_bit(num);
    cout << num << endl;
    return 0;
}

Output: 6




    Getting lowest set bit of a number:

This is done by using expression ‘X &(-X)’Let us see this by taking an example:Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ and 2’s complement will be (~X+1 or -X) i.e  ‘11010100’.So if we ‘AND’ original number ‘X’ with its two’s complement which is ‘-X’, we get lowest set bit.

00101100
& 11010100
-----------
00000100



#include <iostream>
using namespace std;
int lowest_set_bit(int num)
{
    int ret = num & (-num);
    return ret;
}
int main()
{
    int num = 10;
    int ans = lowest_set_bit(num);
    cout << ans << endl;
    return 0;
}

Output:  2

Division by 2 and Multiplication by 2 are very frequently that too in loops in Competitive Programming so using Bitwise operators can help in speeding up the code.

Divide by 2 using right shift operator:

00001100 >> 1 (00001100 is 12)
------------
00000110 (00000110 is 6)

#include <iostream>
using namespace std;
int main()
{
    int num = 12;
    int ans = num>>1;
    cout << ans << endl;
    return 0;
}
Output

6

Multiply by 2 using left shift operator:

00001100 << 1 (00001100 is 12)
------------
00011000 (00000110 is 24)

#include <iostream>
using namespace std;
int main()
{
    int num = 12;
    int ans = num<<1;
    cout << ans << endl;
    return 0;
}
Output

24
*/