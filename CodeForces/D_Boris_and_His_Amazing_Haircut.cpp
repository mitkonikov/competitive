#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    map<int, int> r;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        r[x]++;
    }
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            while (!st.empty() && st.top() < b[i]) {
                st.pop();
            }
            continue;
        }
        if (a[i] < b[i]) {
            cout << "NO" << endl;
            return;
        }
        if (st.empty()) {
            if (r[b[i]] == 0) {
                cout << "NO" << endl;
                return;
            }
            r[b[i]]--;
            st.push(b[i]);
            continue;
        }
        if (st.top() == b[i]) continue;
        if (st.top() > b[i]) {
            if (r[b[i]] == 0) {
                cout << "NO" << endl;
                return;
            }
            r[b[i]]--;
            st.push(b[i]);
        } else {
            while (!st.empty() && st.top() < b[i]) {
                st.pop();
            }
            i--;
            continue;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}