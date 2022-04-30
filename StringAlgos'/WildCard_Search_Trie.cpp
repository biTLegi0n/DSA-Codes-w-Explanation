#include <bits/stdc++.h>
using namespace std;

/**
 * @p https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
    word may contain dots '.' where dots can be matched with any letter.
 *
 *
 * @brief The basic idea behind this is that we replace the '.' with all the 26 characters and check if any one of them matches our
 *        requirements. If we have any one of them matching, then we return true.
 *
 */

struct Trie {
    char c;
    int wc = 0;
    Trie* next[26];
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a']==NULL){
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

    bool search(string word) {
        Trie* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(word[i]=='.'){
                bool flag = false;
                for(int k = 0; k<26; k++){
                    if(temp->next[k]!=NULL){
                        string str = word.substr(0,i);
                        str.push_back('a'+k);
                        str.append(word.substr(i+1,word.size()-i-1));
                        if(search(str)){
                            flag = true;
                            return true;
                        }
                    }
                }
                if(!flag) return false;
            }
            else
            if(temp->next[word[i]-'a']!=NULL)
                temp = temp->next[word[i]-'a'];
            else
                return false;
            if(i==word.size()-1 and temp->wc>0) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */