#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    vector<node*> children;
    int val = -1;
    int special = false;
    node(int val) {
        this->val = val;
    }

    node(string s) {
        if (s.empty()) return;
        if (s.front() == '[' && s.back() == ']') {
            s.pop_back();
            s = s.substr(1);
        }
        if (s.empty()) return;
        int bal = 0;
        int start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {

            } else if (s[i] == '[') {
                bal++;
                if (start == -1) {
                    start = i;
                }
            } else if (s[i] == ']') {
                bal--;
                if (bal == 0) {
                    string new_str = s.substr(start, i-start+1);
                    children.push_back(new node(new_str));
                    start = -1;
                }
            } else {
                if (bal == 0) {
                    int new_val = (s[i] == 'A' ? 10 : (s[i] - '0'));
                    children.push_back(new node(new_val));
                }
            }
        }
    }
};

int dfs(node* S, node* T) {
    if (S->children.size() == 0 && T->children.size() == 0) {
        if (S->val == T->val) return 0;
        return (S->val < T->val ? 1 : -1);
    }
    if (S->children.size() == 0) {
        S->children.push_back(new node(S->val));
        S->val = -1;
    }
    if (T->children.size() == 0) {
        T->children.push_back(new node(T->val));
        T->val = -1;
    }
    for (int i = 0; i < min(S->children.size(), T->children.size()); i++) {
        int comp = dfs(S->children[i], T->children[i]);
        if (comp == 0) continue;
        return comp;
    }
    if (S->children.size() > T->children.size()) return -1;
    if (S->children.size() < T->children.size()) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    t *= 2;
    vector<node*> roots;
    for (int i = 0; i < t; i++) {
        string s; cin >> s;
        roots.push_back(new node(s));
        if (i <= 1) roots.back()->special = true;
    }
    sort(roots.begin(), roots.end(), [](node* a, node* b) {
        int ans = dfs(a, b);
        if (ans == 1) return true;
        return false;
    });
    ll ans = 1;
    for (int i = 0; i < roots.size(); i++) {
        if (roots[i]->special) ans *= (i + 1);
    }
    cout << ans << endl;
    return 0;
}