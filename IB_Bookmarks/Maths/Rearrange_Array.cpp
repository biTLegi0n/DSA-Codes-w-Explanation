#include<bits/stdc++.h>
using namespace std;

/**
 * @brief This question was very tricky. It has to be solved in O(N) time and O(1) space, and since any question like this
 *        is solved by hashing the array we have, we did the same here but with some major changes. Here, how we hash is totally
 *        clever.
 *        The main idea followed the fact that if we add a number 'x' to some multiple of 'n' such that x<n, then the addition of
 *        x would not change the division of that number by n. IE, if we have S = k*n+x, then S/n = k. This can be observed by taking
 *        some real numbers as examples. also we know that divisor changes when we add something which is >=n.
 *            - In this question, we have the constraint that all the numbers are in the range [0,N-1]. therefore, this fact can be
 *        used to our advantage. We can hash the values as arr[i] = newValue*n + oldValue. Now this thing will give us new as well as
 *        old value at the same time. newValue is arr[i]/n and old value is arr[i]%n...
 *
 * @param arr
 */
void arrange(vector<int> &arr) {
    // The main idea here is to hash the new value and the old value at the same place.
    // We hash both the values as arr[i] = newValue * arrSize + oldValue
    // What we are doing is simple. Just take an array of size 5, and imagine you are
    // doing 3*5 + 4 => that when you do arr[i]/arrSize you have new and arr[i]%arrSize gives old
    int n = arr.size();
    for(int i = 0; i<arr.size(); i++){
        arr[i] = arr[i]+(arr[arr[i]]%n)*n;
    }
    for(int i = 0; i<arr.size(); i++)
        arr[i] = arr[i]/n;
}
