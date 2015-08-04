//
// Created by zhengxx on 15/8/2.
//

#include <iostream>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *nodes[26];
    bool exist = false;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            nodes[i] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->nodes[word[i] - 'a'] == nullptr)
                p->nodes[word[i] - 'a'] = new TrieNode();
            p = p->nodes[word[i] - 'a'];
        }
        p->exist = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->nodes[word[i] - 'a'] == nullptr)
                return false;
            p = p->nodes[word[i] - 'a'];
        }
        return p->exist;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->nodes[prefix[i] - 'a'] == nullptr)
                return false;
            p = p->nodes[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");