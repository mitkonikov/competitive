// Task: https://mendo.mk/Task.do?id=968

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct FenwickTree {
    vector<int> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    int getFWT(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};

struct node {
    int value;
    node* next;
    node* prev;
};

int main() {
    int q;
    cin >> q;

    vector<node*> mp(q);
    node* root;
    node* tail;

    for (int i = 0; i < q; i++) {
        char c;
        scanf(" %c", &c);
        
        if (i == 0) {
            root = new node { i, nullptr, nullptr };
            tail = root;
            mp[i] = tail;
        } else {
            if (c == 'K') {
                tail->next = new node { i, nullptr, tail };
                tail = tail->next;
                mp[i] = tail;
            } else {
                int x;
                scanf("%d", &x);
                x--;

                node* target = mp[x];
                node* in_between = new node{ i, target, target->prev };
                if (in_between->prev != nullptr)
                    in_between->prev->next = in_between;
                    
                if (in_between->next != nullptr)
                    in_between->next->prev = in_between;
                
                if (target == root) {
                    root = in_between;
                }
                mp[i] = in_between;
            }
        }
    }

    vector<int> v(q);
    vector<int> ans(q, 0);
    int i = 0;
    node* current = root;
    while (current != nullptr) {
        v[i++] = current->value;
        current = current->next;
    }

    FenwickTree fwt(q + 10);
    for (int i = 0; i < q; i++) {
        ans[v[i]] = fwt.getFWT(v[i]) + 1;
        fwt.addFWT(v[i], 1);
    }

    for (auto c: ans) {
        cout << c << '\n';
    }

    cout << flush;
    return 0;
}