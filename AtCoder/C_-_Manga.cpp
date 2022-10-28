#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    deque<int> dq;
    vector<int> same;
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i-1]) {
            same.push_back(v[i]);
        } else {
            dq.push_back(v[i]);
        }
    }

    for (auto el: same) {
        dq.push_back(el);
    }

    int p = 1;
    while (!dq.empty()) {
        if (dq.front() != p) {
            if (dq.size() < 2) {
                break;
            }

            p++;
            dq.pop_back();
            dq.pop_back();
        } else {
            dq.pop_front();
            p++;
        }
    }

    cout << p - 1 << endl;
    return 0;
}