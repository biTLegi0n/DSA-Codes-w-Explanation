#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   In this problem, we use binary search over search space concept. We have to minimize the maximum number of pages that we can
 *          allocate to the students. In such type of problems, we have to use binary search over search space. Now, we find a mid, and
 *          check if this mid is a valid candidate for our answer or not. Now the question is how to check its validity??
 *           - Initially, i thought i have to use the fact that number of students are given so i divided the array.size() by number of
 *              students to find that this much books have to be allocated to a student, but i was wrong. That's not the use of students here.
 *          Students are used to check the validity of mid. We keep on adding the elements of the array untill we get a sum>=mid. In that case
 *          we increase the count of students. This implies that after mid number of pages have reached, we have to pass the next book to another
 *          student. And after this process is completed, if the number of students required for mid is > number of students provided, then
 *          we have to increase the mid, else, we go by decreasing it.
 *          One thing to note is that if at some point, sum > mid, then sum is not resetted to 0, instead, it is resetted to arr[i], because
 *          after arr[i-1]th book allocated to one student, we have to consider this arr[i]th book too! So we cannot just omit it!
 *
 * @param mid
 * @param arr
 * @param B
 * @return int
 */

int isvalid(int mid, vector<int>&arr, int B){
    int num_of_stud=0,sum=0;
    for(int i = 0; i<arr.size(); i++){
        // If there is any element in the array that is greater than mid, then there is no way that we can allocate this book to any of
        // the student, since the max we can allocate is mid...
        if(arr[i]>mid) return INT_MAX;

        sum += arr[i];
        if(sum>mid){
            num_of_stud++;
            sum=arr[i];
        }
        else
        if(sum == mid)
            num_of_stud++, sum=0;
    }
    if(sum>0) num_of_stud++;
    return num_of_stud;
}
int books(vector<int> &arr, int B) {
    // we dont pre decide the number of pages that a student will/have to get
    // instead, we use this fact to check the validity of our mid, we increase the no. of
    // students every time we get our sum>that mid
    if(B>arr.size()) return -1;

    int low = 0, high = 0;
    for(auto u : arr) high += u;
    int res = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(isvalid(mid,arr,B)<=B){
            res=mid;
            high=mid-1;
        }
        else
            low = mid+1;
    }
    return res;
}
