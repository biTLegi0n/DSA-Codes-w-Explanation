#include<bits/stdc++.h>
using namespace std;
/**
 * @brief This problem was not so easy peasy creamy cheesy! It took half of my day and still i had to take help from the source video of
 *        striver. Now, i might not be able to satisfy you from the explanation but i will try my best!
 *
 *          Basically, we have two sorted arrays and we need to find their median. Now to do that, we have various methods :
 *           - Brute force, which says that append both vectors to each other and sort the resultant vector and then find the median
 *           - Optimized brute force says that merge the two vectors using merge sort algorithm and thus we save the sorting time and
 *             complexity become O(m+n)
 *           - To save the space in previous approach, we can have two variables that store the value of the median elements. Since we only
 *             need one or two elements to find the median, we can only store them and iterate over the remainings.
 *          Now these approaches have a time complexity of more than O(m+n) but the ideal solution to this problem is in O(logn)
 *          Since the arrays are sorted, we must think of binary search. So, we think in a way like, if I take x elements from the front of
 *          first array, then i will need (half_array_size-x) elements from the second array that could complete the first half of the
 *          resultant array.
 *          ref : https://www.youtube.com/watch?v=NTop3VTjmxk&t=1673s
 *          The first think that we need to consider is that the first array, whose elements we choose by mid, should always be of less size
 *          then the second in order to avoid lots of runtime errors and wrong anwers.
 *          The next is that the partition index will always lie between 0 and min(m,n). The remaining elements are calculated as m+n+1/2
 *          This is because it always keeps the answer in safe side. Even if we have even number of elements, we will stil have one more
 *          element on the left hand side that ensures that it wont throw and error of emptiness.
 *          Remaining is self explanatory. I would say that if things are not clear, its best to watch the video, coz this question is
 *          at a whole another level.....
 *
 * @param arr1
 * @param arr2
 * @return double
 */
double findMedianSortedArrays(const vector<int> &arr1, const vector<int> &arr2) {
    // basically, we prefer to have minimum size array as array1 to avoid the possible WA and
    // RE.

    if(arr1.size()>arr2.size()) return findMedianSortedArrays(arr2,arr1);
    int m = arr1.size(), n = arr2.size();

    int low = 0, high = min(m,n), req = (m+n+1)/2;
    while(low<=high){
        int mid = (low+high)/2;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid!=0) l1 = arr1[mid-1];
        if(req-mid!=0) l2 = arr2[req-mid-1];
        if(mid!=m) r1 = arr1[mid];
        if(req-mid!=n) r2 = arr2[req-mid];

        if(l1<=r2 and l2<=r1){
            if((m+n)%2)
                return (max(l1,l2)+min(r1,r2))/2.0;
            else
                return max(l1,l2)*1.0;  // since in case of odd, left has more elements, see req
        }
        else
        if(l1>r2)
            high = mid-1;
        else
            low = mid+1;
    }
    return 0.0;
}
