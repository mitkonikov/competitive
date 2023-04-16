#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<multiset<int>> boxes(N);
    vector<set<int>> contain(2e5 + 1000);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            i--; j--;
            boxes[j].insert(i);
            contain[i].insert(j);
        } else if (t == 2) {
            int i;
            cin >> i;
            i--;
            for (auto el: boxes[i]) {
                cout << el + 1 << " ";
            } cout << endl;
        } else {
            int i;
            cin >> i;
            i--;
            for (auto el: contain[i]) {
                cout << el + 1 << " ";
            } cout << endl;
        }
    }
    return 0;
}