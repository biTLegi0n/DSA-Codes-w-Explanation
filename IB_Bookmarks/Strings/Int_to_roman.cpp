#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   Earlier, i had no idea how to solve this question, but then, after talking to motu, i got this idea. That we save all the
 *          important characters and their previous in an array, and then we keep on subtracting from the max, and if the current
 *          index element is smaller than the number itself, we subtract it from the number and append its string accordingly....
 *
 */

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> mp;
        mp.push_back({1000,"M"});
        mp.push_back({900,"CM"});
        mp.push_back({500,"D"});
        mp.push_back({400,"CD"});
        mp.push_back({100,"C"});
        mp.push_back({90,"XC"});
        mp.push_back({50,"L"});
        mp.push_back({40,"XL"});
        mp.push_back({10,"X"});
        mp.push_back({9,"IX"});
        mp.push_back({5,"V"});
        mp.push_back({4,"IV"});
        mp.push_back({1,"I"});

        int i = 0;
        string roman = "";
        while(i<mp.size() and num>0){
            if(num>=mp[i].first){
                roman.append(mp[i].second);
                num -= mp[i].first;
            }
            else
                i++;
        }
        return roman;
    }
};