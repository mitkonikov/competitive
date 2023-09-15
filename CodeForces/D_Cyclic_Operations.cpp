#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> A;
vector<bool> visited;
vector<bool> in_stack;
vector<int> dist;
stack<int> st;
int C = 0;

int dfs(int u) {
    if (visited[u]) {
        return dist[u];
    }

    visited[u] = true;
    in_stack[u] = true;
    st.push(u);
    int nxt = A[u];
    if (in_stack[nxt]) {
        dist[nxt] = 0;
        dist[u] = 0;
        C = 1;
        while (!st.empty() && st.top() != nxt) {
            auto t = st.top();
            dist[t] = 0;
            // all of these elements are in the cycle
            C++;
            in_stack[t] = false;
            st.pop();
        }
        while (!st.empty()) {
            in_stack[st.top()] = false;
            st.pop();
        }
        return 0;
    }

    dist[u] = min(dist[u], dfs(nxt) + 1);
    in_stack[u] = false;
    return dist[u];
}

void testCase() {
    int N, K;
    cin >> N >> K;
    A.clear();
    visited.clear();
    in_stack.clear();
    dist.clear();
    A.resize(N);
    visited.resize(N);
    in_stack.resize(N);
    dist.resize(N, 1e9);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    if (K == 1) {
        bool ok = 1;
        for (int i = 0; i < N; i++) ok &= (A[i] == i);
        cout << (ok ? "YES" : "NO") << endl;
        return;
    }

    vector<bool> ok(N);
    
    for (int i = 0; i < N; i++) {
        st = stack<int>();
        C = -1;
        if (!visited[i]) {
            dfs(i);
            if (C != -1 && C != K) {
                cout << "NO" << endl;
                return;
            }
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