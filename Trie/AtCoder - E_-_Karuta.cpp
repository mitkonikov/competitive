#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct Node {
    vector<Node*> children;
    Node* parent = nullptr;
    bool removed = false;
    int count = 0;

    Node(Node* parent) {
        children.resize(26, nullptr);
        this->parent = parent;
    }

    Node* add(string& s, int i, int ans) {
        removed = false;
        count++;
        if (i >= s.size()) {
            return this;
        }
        if (children[s[i]-'a'] == nullptr) {
            children[s[i]-'a'] = new Node(this);
            return children[s[i]-'a']->add(s, i + 1, ans);
        }

        return children[s[i]-'a']->add(s, i + 1, ans + 1);
    }

    int traverse(string& s, int i, int ans) {
        if (i >= s.size()) return ans;
        if (children[s[i] - 'a'] != nullptr && !children[s[i] - 'a']->removed) {
            return children[s[i]-'a']->traverse(s, i + 1, ans + 1);
        }
        return ans;
    }

    void remove() {
        count--;

        bool ok = (count == 0);
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr && !children[i]->removed) {
                ok = false;
                break;
            }
        }

        if (ok) {
            removed = true;
            if (parent != nullptr) {
                parent->remove();
            }
        }
    }
};

int main() {
    int N;
    cin >> N;
    Node* trie_back = new Node(nullptr);
    Node* trie_front = new Node(nullptr);
    vector<string> strs(N);
    vector<Node*> endpoints(N);
    for (int i = 0; i < N; i++) cin >> strs[i];
    for (int i = 1; i < N; i++) {
        endpoints[i] = trie_back->add(strs[i], 0, 0);
    }
    for (int i = 0; i < N; i++) {
        int back = trie_back->traverse(strs[i], 0, 0);
        int front = trie_front->traverse(strs[i], 0, 0);
        cout << max(back, front) << endl;
        trie_front->add(strs[i], 0, 0);
        if (i+1<N) endpoints[i+1]->remove();
    }
    return 0;
}