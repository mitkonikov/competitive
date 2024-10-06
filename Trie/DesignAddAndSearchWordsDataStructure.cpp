// LeetCode Task: https://leetcode.com/problems/design-add-and-search-words-data-structure

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline int conv(char c) {
    return c - 'a';
}

struct Node {
    vector<Node*> childs;
    bool end = false;
    
    Node() {
        childs.resize(26, NULL);
    }

    void add(string& word, int i) {
        if (i >= word.size()) {
            end = true;
            return;
        }
        int c = conv(word[i]);
        if (childs[c] == NULL) {
            childs[c] = new Node();
        }
        childs[c]->add(word, i + 1);
    }

    bool search(string& word, int i) {
        if (i >= word.size()) {
            return end;
        }
        
        bool ok = false;
        if (word[i] == '.') {
            // try all
            for (int next = 0; next < 26; next++) {
                if (childs[next] == NULL) continue;
                ok |= childs[next]->search(word, i + 1);
                if (ok) return true;
            }
        } else {
            int next = conv(word[i]);
            if (childs[next] != NULL) {
                ok |= childs[next]->search(word, i + 1);
            }
        }
        
        return ok;
    }
};

class WordDictionary {
public:
    Node* trie;

    WordDictionary() {
        trie = new Node();
    }
    
    void addWord(string word) {
        trie->add(word, 0);
    }
    
    bool search(string word) {
        return trie->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    
    return 0;
}