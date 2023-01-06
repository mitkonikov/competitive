#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> visited(N, -1);
    int id = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] != -1) continue;
        int count = 0;
        int t = i;
        while (visited[t] == -1) {
            visited[t] = id;
            t = A[t];
            count++;
        }
        ans += count - 1;
        id++;
    }
    for (int i = 1; i < N; i++) {
        if (visited[i] == visited[i-1]) {
            cout << ans - 1 << endl;
            return;
        }
    }
    cout << ans + 1 << endl;
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