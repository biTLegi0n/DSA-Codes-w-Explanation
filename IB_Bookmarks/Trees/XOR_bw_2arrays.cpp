#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char c;
    int e = 0;
    TrieNode* next[2];
};

TrieNode* root;
class Trie {
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string str){
        // cout<<"Inserted "<<str<<"\n";
        TrieNode* temp = root;
        for(int i = 0; i<str.size(); i++){
            if(temp->next[str[i]-'0'] == NULL){
                TrieNode* node = new TrieNode();
                node->c = str[i];
                temp->next[str[i]-'0'] = node;
                temp = node;
            }
            else
                temp = temp->next[str[i]-'0'];
            if(i==str.size()-1) temp->e++;
        }
    }

    int fun(string str, int num){
        TrieNode* temp = root;
        string res = "";
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='0'){
                if(temp->next[1]){
                    res.push_back('1');
                    temp = temp->next[1];
                }
                else res.push_back('0'), temp = temp->next[0];
            }
            else{
                if(temp->next[0]){
                    res.push_back('0');
                    temp = temp->next[0];
                }
                else res.push_back('1'), temp = temp->next[1];
            }
        }
        // cout<<"For "<<str<<", max is "<<res<<"\n";
        int ans = 0;
        for(int i = res.size()-1; i>=0; i--){
            ans += (1<<(res.size()-i-1))*(res[i]-'0');
        }
        return (ans^num);
    }
};

int solve(vector<int> &arr1, vector<int> &arr2) {
    Trie obj;

    for(auto u : arr1){
        string temp = "";
        int i = 31;
        while(i--){
            if(u&(1<<i)) temp.push_back('1');
            else temp.push_back('0');
        }
        // reverse(temp.begin(),temp.end());
        obj.insert(temp);
    }
    // cout<<"Inserted\\\ \n";
    int ans = INT_MIN;
    for(auto u : arr2){
        string temp = "";
        int i = 31;
        while(i--){
            if(u&(1<<i)) temp.push_back('1');
            else temp.push_back('0');
        }
        ans = max(ans,obj.fun(temp,u));
    }
    return int(ans);
}
