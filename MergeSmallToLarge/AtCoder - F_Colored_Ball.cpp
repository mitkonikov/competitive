#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> boxes(N);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        boxes[i].insert(X);
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (boxes[a].size() > boxes[b].size()) {
            boxes[a].swap(boxes[b]);
        }
        for (auto el: boxes[a]) {
            boxes[b].insert(el);
        }
        boxes[a].clear();
        cout << boxes[b].size() << endl;
    }
    return 0;
}