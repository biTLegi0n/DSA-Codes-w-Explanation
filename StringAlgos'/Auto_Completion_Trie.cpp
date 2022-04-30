#include <bits/stdc++.h>
using namespace std;

struct Trie {
    char c;
    int wc = 0;
    Trie* next[26];
};
class Solution {
public:
    Trie* root;
    vector<vector<string>> suggestedProducts(vector<string>& prod, string word) {
        sort(prod.begin(),prod.end());
        root = new Trie();
        for(auto u : prod) insert(u);
        vector <vector <string>> res;
        string str = "";
        for(int i = 0; i<word.size(); i++){
            str.push_back(word[i]);
            res.push_back(search(str,""));
        }
        return res;
    }
protected:
    void insert(string word){
        Trie* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a'] == NULL){
                Trie* node = new Trie();
                node->c = word[i];
                temp->next[word[i]-'a'] = node;
                temp = node;
            }
            else
                temp = temp->next[word[i]-'a'];
            if(i==word.size()-1) temp->wc++;
        }
    }
    vector <string> search(string str,string word){
        Trie* temp = root;
        vector <string> res;
        for(int i = 0; i<str.size(); i++){
            if(temp->next[str[i]-'a'] == NULL) return res;
            else temp = temp->next[str[i]-'a'];
            if(i==str.size()-1) allWords(temp,res,word);
            word.push_back(str[i]);
        }
        return res;
    }
    bool islast(Trie* temp){
        for(int i = 0; i<26; i++) if(temp->next[i]!=NULL) return false;
        return true;
    }
    void allWords(Trie* temp, vector <string>&res,string word){
        //base case
        if(res.size()>=3) return;
        if(temp->wc>0) {
            word.push_back(temp->c);
            res.push_back(word);
            word.pop_back();
        }
        if(islast(temp)) return;
        for(int i = 0; i<26; i++){
            if(temp->next[i]!=NULL){
                word.push_back(temp->c);
                allWords(temp->next[i],res,word);
                word.pop_back();
            }
        }
    }
};