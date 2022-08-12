#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   This question was easy. I wasted almost whole day trying to do what i was doing. And at last, realised that i was wrong. 
 *          I was just moving forward, just like in jump game, moving untill i empty the current fuel and finding maxdist i can do meanwhile.
 *          wHen current fuel is finished, i made a jump and set current fuel to maxdist. That was WRRONG. As, in that, we will only be making
 *          one jump in that region while we could need to make more than one jump. Therefore, I took some help and found this approach which 
 *          is greedy and best. 
 *             hERE, we maintain a priority_queue and in that pq, we are putting the fuel of a range, the max fuel in that range, and when our 
 *          current fuel is emptied, we use that max fuel to move further, and we keep using those max fuels only. Now, you might think that 
 *          order will be altered and any other things too! But, we can say that a+b or b+a both are same thing. Both will lead us to their sum.
 *          Here, the order would not matter but the fuels to choose would. And since we need minimum, we would for sure choose the max fuels. 
 * 
 */

class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& stat) {
        priority_queue <int> q;
        int jump = 0, curr = start, i=0;
        while(curr<target){
            while(i<stat.size() and stat[i][0]<=curr) q.push(stat[i][1]), i++;
            if(q.empty()) return -1;
            curr += q.top(), q.pop();
            jump++;
        }
        return jump;
    }
};