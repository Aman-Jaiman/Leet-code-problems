#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26] = {nullptr};
    bool flag =false;

    bool containKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void addKey(char ch , Node* node){
        links[ch - 'a'] = node;
        return ;
    }

    Node* next(char ch){
        return links[ch - 'a'];
    }

    void isSet(){
        flag = true;
        return ;
    }

    bool isEnd(){
        return flag;
    }

};


class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) { 
        Node* node = root;
        for(char ch : word) {
            if(!node->containKey(ch)){
                node->addKey(ch, new Node());
            }
            node = node->next(ch);
        }

        node->isSet();
        return ;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containKey(ch) ) return false;
            node = node->next(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(!node->containKey(ch) ) return false;
            node = node->next(ch);
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