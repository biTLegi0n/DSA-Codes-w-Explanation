#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This is the solution i got AC at Leetcode. i was not able to solve this on IB. So in nfrustration, i submitted this one
            Now logic is pretty simple, just see the code for any errors you might face.

 */

vector <int> v[100005];
bool visited[100005];
int dis[100005];
unordered_map <string, int> mp;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    mp.clear();

    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;

    set <string> s;
    vector <string> copy;
    copy.push_back(beginWord);
    for(auto u : wordList)
        copy.push_back(u);

    for(int i = 0; i<copy.size(); i++){
        mp.insert({copy[i], i});
        s.insert(copy[i]);
    }

    for(int i = 0; i<copy.size(); i++)
        v[i].clear(), visited[i] = false, dis[i] = 1e8;

    for(int i = 0; i<copy.size(); i++){
        string str = copy[i];
        for(int j = 0; j<copy[i].size(); j++){
            string temp = str;
            for(int k = 0; k<26; k++){
                temp[j] = 'a'+k;
                if(mp.find(temp) != mp.end() and temp != str){
                    v[mp[str]].push_back(mp[temp]);
                }
            }
        }
    }

    queue <int> q;
    q.push(0);
    visited[0] = true;
    dis[0] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : v[curr]){
            if(!visited[child]){
                visited[child] = true;
                dis[child] = dis[curr] + 1;
                q.push(child);
            }
        }
    }
    return (dis[mp[endWord]] != 1e8) ? dis[mp[endWord]] : 0;
}

int solve(string A, string B, vector<string> &C) {
    return ladderLength(A,B,C);
}