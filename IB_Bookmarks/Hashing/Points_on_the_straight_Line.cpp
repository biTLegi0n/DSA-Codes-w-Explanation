#include<bits/stdc++.h>
using namespace std;

/**
  @brief    As simple as it seems. Just hash the slope using n^2. Select any two points, and find the slope of line passing
            through those two points.
 */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int res = 1;

        for(int i=0; i<points.size(); i++){
            unordered_map <double,int> mp;
            for(int j=0; j<points.size(); j++){
                if(i==j) continue;

                double m = 100000000.0;
                int y2 = points[j][1], y1 = points[i][1];
                int x2 = points[j][0], x1 = points[i][0];
                if(points[j][0]!=points[i][0]) m = double(y2-y1)/double(x2-x1);
                mp[m]++;
            }

            int maxi = 0;
            for(auto u : mp) maxi = max(maxi,u.second+1);
            res = max(res,maxi);
        }
        return res;
    }
};