#include <bits/stdc++.h>
using namespace std;


struct Trie {
    char c;
    int e=0;
    Trie* next[26];
};

Trie* root;
class TrieNode {
public :

    TrieNode(){
        root = new Trie();
    }

    void insert(string word){
        Trie* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a'] == NULL){
                Trie* dummy = new Trie();
                dummy->c = word[i];
                temp->next[word[i]-'a'] = dummy;
                temp = dummy;
            }
            else
                temp = temp->next[word[i]-'a'];
            if(i==word.size()-1) temp->e++;
        }
    }

    bool search(string word){
        Trie* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a'] == NULL) return false;
            else temp = temp->next[word[i]-'a'];
            if(i==word.size()-1 and temp->e==0) return false;
        }
        return true;
    }
};

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return (a.second < b.second);
    } else {
        return (a.first > b.first);
    }
}

vector<int> solve(string str, vector<string> &B) {
    int start = 0;
    TrieNode obj;
    for(int i = 0; i<str.size(); i++){
        if(str[i]=='_'){
            obj.insert(str.substr(start,i-start));
            start = i+1;
        }
    }
    obj.insert(str.substr(start,str.size()-start));

    unordered_map <string,int> mp;
    for(int i = 0; i<B.size(); i++){
        mp[B[i]] = i;
    }

    vector <pair<int,int>> res;
    for(int k = 0; k<B.size(); k++){
        start = 0;
        int count = 0;
        for(int i = 0; i<B[k].size(); i++){
            if(B[k][i]=='_'){
                string temp = B[k].substr(start,i-start);
                start = i+1;
                if(obj.search(temp)) count++;
            }
        }
        if(obj.search(B[k].substr(start,B[k].size()-start))) count++;

        res.push_back({count,k});
    }
    stable_sort(res.begin(),res.end(),compare);
    // for(auto u : res) cout<<"for string "<<u.second<<", count = "<<u.first<<"\n";
    vector <int> ans;
    for(int i = 0; i<res.size(); i++) ans.push_back(res[i].second);
    return ans;
}
