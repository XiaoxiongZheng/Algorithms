//
// Created by zhengxx on 15/8/4.
//

#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    bool flag = false;
    TrieNode *nodes[26];

    TrieNode() {
        for (int i = 0; i < 26; i++)
            nodes[i] = nullptr;
    }
};


class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->nodes[word[i] - 'a'] == nullptr)
                p->nodes[word[i] - 'a'] = new TrieNode();
            p = p->nodes[word[i] - 'a'];
        }
        p->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }

    bool search(const string& word, int pos, TrieNode *p) {
        if (pos == word.size()) return p->flag;
        if (word[pos] == '.') {
            for (int j = 0; j < 26; j++) {
                if (p->nodes[j] != nullptr && search(word, pos+1, p->nodes[j])) return true;
            }
            return false;
        }
        if (p->nodes[word[pos] - 'a'] == nullptr) return false;
        if (p->nodes[word[pos] - 'a'] != nullptr) return search(word, pos+1, p->nodes[word[pos] - 'a']);
    }

private:
    TrieNode *root = new TrieNode();
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");