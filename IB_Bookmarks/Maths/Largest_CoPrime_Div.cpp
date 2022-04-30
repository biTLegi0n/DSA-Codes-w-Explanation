#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Earlier, i tried solving with the intuitive approach that came in my mind. But ofcouse, it gave TLE.
 *        So the approach is as follows :
            We can try to remove the common factors of A and B from A by finding the greatest common divisor (gcd) of A and B and dividing A with that gcd.

            Mathematically, A = A / gcd(A, B) —— STEP1
            Now, we repeat STEP1 till we get gcd(A, B) = 1.
            Atlast, we return X = A

            How does this work ?

            On doing prime factorisation of A and B, we get :

            A = p1x1 . p2x2 . … . pkxk
            B = q1y1 . q2y2 . … . qlyl
            Where pi ; i = 1, 2, …, k are prime factors of A and xi ; i = 1, 2, …, k are their respective powers
            Similarly, qj ; i = 1, 2, …, l are prime factors of B and yi ; j = 1, 2, …, l are their respective powers
 *
 * @param A
 * @param B
 * @return int
 */

int cpFact(int A, int B) {
    if(__gcd(A,B)==1) return A;
    // vector <int> divisors;
    // for(int i = 1; i<=sqrt(A); i++){
    //     if(A%i==0){
    //         divisors.push_back(i);
    //         divisors.push_back(A/i);
    //     }
    // }
    // sort(divisors.begin(),divisors.end(),greater<int>());
    // for(int i = 0; i<divisors.size(); i++){
    //     if(__gcd(divisors[i],B)==1)
    //         return divisors[i];
    // }
    while(__gcd(A,B)!=1){
        A /= __gcd(A,B);
    }
    return A;
}
