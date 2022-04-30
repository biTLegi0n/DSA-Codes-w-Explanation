#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, we have to return all the paths which are of minimum length. To do so, we can use the dfs but
            since that would be backtracking, that is exponential, therefore, we will use dijkstra, and reduce the time complexity.

 */

vector <int> v[10005];
int visited[10005];
int ans = INT_MAX;
vector <vector <string>> res;
class Solution {
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& words) {
        if(find(words.begin(),words.end(),end)==words.end()) return {};
        if(find(words.begin(),words.end(),begin)==words.end()) words.push_back(begin);

        for(int i = 0; i<words.size(); i++) v[i].clear(), visited[i] = 0;
        res.clear();
        ans = INT_MAX;

        int start=-1,target=-1;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(valid(words[i],words[j]))
                    v[i].push_back(j), v[j].push_back(i);
            }
            if(words[i]==begin) start = i;
            else if(words[i]==end) target = i;
        }

        vector <int> dist(words.size()+1,INT_MAX);
        vector <string> path;
        priority_queue <pair<int,pair<int,vector<string>>>,vector<pair<int,pair<int,vector<string>>>>,greater<pair<int,pair<int,vector<string>>>>> q;
        q.push({1,{start,path}});
        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second.first;
            vector <string> p = q.top().second.second;
            q.pop();

            p.push_back(words[node]);
            dist[node] = d;

            if(d>ans) continue;

            if(node == target){
                ans = d;
                res.push_back(p);
                continue;
            }

            for(auto u : v[node])
                if(dist[u]>d+1)
                    q.push({d+1,{u,p}});
        }
        return res;
    }

protected:
    bool valid(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        int count = 0;
        for(int i = 0; i<s1.size(); i++)
            if(s1[i]!=s2[i]) count++;

        if(count!=1) return false;
        return true;
    }
};