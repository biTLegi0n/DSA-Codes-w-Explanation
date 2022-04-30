#include <bits/stdc++.h>
using namespace std;

// To have a better understanding :: https://www.youtube.com/watch?v=6PX6wqDQE20&list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl&index=1

struct TrieNode {
    char c;
    int wc = 0;
    TrieNode* next[26];
};

class Trie {
public:

    TrieNode* root;
    //This here below is the Constructor, which is called as we call the class...
    //So basically, it initializes all the by default variables that we'll use in our class.
    Trie() {
        //Its important to initialize it here, doing this process somewhere else causes problem. This makes sure to initialise it everytime
        //class Trie is called.
        root = new TrieNode();
    }

    //This here inserts the new words or characters. First it follows if we already have a node and
    //when we dont have one, we create one. So basically, we trace a given word till it is found in our trie, and when the current
    //is not present, we create a new node, point the earlier to it, and make it the current active node...
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a'] == NULL){
                TrieNode* node = new TrieNode();
                node->c = word[i];
                node->wc = 0;
                temp->next[word[i]-'a'] = node;
                temp = node;
            }
            else
                temp = temp->next[word[i]-'a'];

            if(i==word.size()-1) temp->wc++;
        }
    }

    //Similiar work is done by search function. It traces down the characters one by one and when we reach the end, we check the word_count
    //value, if it is >0, means we have words ending at this particular character, thus we can return true else we have to return false.
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i<word.size(); i++){
            if(temp->next[word[i]-'a'] == NULL) return false;
            else{
                temp = temp->next[word[i]-'a'];
            }
            if(i==word.size()-1 and temp->wc==0) return false;
        }
        return true;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0; i<prefix.size(); i++){
            if(temp->next[prefix[i]-'a'] == NULL) return false;
            else{
                temp = temp->next[prefix[i]-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */