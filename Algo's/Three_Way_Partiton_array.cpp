#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, we had to divide the array into three parts such that first part contains numbers that are less
            than lets say 'a', second part contains numbers between [a,b] and third part contains number greater than b.
            Now to do that in O(n) and constant space, we can swap with the last number when we see a number greater than b
            and we can swap with the first number when we see a number smaller than a. In other cases, we just run the loop.
            This is as simple as it sounds. We maintain two pointers, start and end, which points at the start and end of the
            array initially. Now, we dont have to maintain any sort of order, so we can just randomly swap numbers. So if a number
            is >b, it will surely be in the back of the array, thatswhy we swap it with the number, and if it is smaller than
            a, it surely will be at the front.
            NOTE : wHEN we swap with the last pointer, we dont update i, because the swapped number could also be greater than b.

            This same approach can be applied when we have a single pivot according to which we need to make two partitons. In
            that case too, we swap when we see a larger index with the end or we can also swap a smaller number with start.
            That's completely a choice.

 */

class Solution{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int start=0, end=arr.size()-1, i=0;

        while(i<=end){
            if(arr[i]<a){
                swap(arr[i],arr[start]);
                start++, i++;
            }
            else
            if(arr[i]>b)
            {
                swap(arr[i],arr[end]);
                end--;
            }
            else i++;
        }
    }
};