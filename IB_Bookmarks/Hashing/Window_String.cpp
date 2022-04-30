#include<bits/stdc++.h>
using namespace std;

/**
 @brief     This problem took a lot of time.The mistake that i was doing while solving it was that i kep two maps and whenever i
            found a character belonging to the pattern string, i compared both the maps which was costly. Instead i found this
            method. It says that maintain a counter, which is increased when we recieve a character which will help us to get an
            answer and which will decrement when a character of use is skipped.
            While traversing, if we get a character whose occurrance is required, then we do count++, if we have enough of this
            particular character(like we have 2 'B' in pattern but we encountered a third, then that third B will not increase the
            counter.) then we donot increase the counter, only update the map. When our counter becomes >= B.size(), then we focus
            on shortening the substring that we have. We increase the low pointer untill our counter is still == B.size(). And
            while doing so, we keep checking if we are removing a character which actually contributed in count.

 */

string minWindow(string A, string B) {
    unordered_map <char,int> mp;
    for(int i = 0; i<B.size(); i++) mp[B[i]]++;

    unordered_map <char,int> freq;
    int low = 0, high = 0,count=0,start=0,end=0;

    while(low<=high and high<=A.size()){
        if(count>=B.size()){
            if(start==0 and end==0) start = low, end = high;
            else
            if(end-start>high-low) start = low, end = high;

            if(mp.find(A[low])!=mp.end() and freq[A[low]]<=mp[A[low]]) count--;
            freq[A[low]]--;
            low++;
        }
        else{
            freq[A[high]]++;
            if(mp.find(A[high])!=mp.end() and freq[A[high]]<=mp[A[high]]) count++;
            high++;
        }
    }
    return A.substr(start,end-start);
}
