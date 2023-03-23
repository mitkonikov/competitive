#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(i + 1);
    }
    set<int> called;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            auto top = pq.top();
            pq.pop();
            called.insert(top);
        } else if (type == 2) {
            int x;
            cin >> x;
            called.erase(x);
        } else {
            cout << *called.begin() << endl;
        }
    }
    return 0;
}