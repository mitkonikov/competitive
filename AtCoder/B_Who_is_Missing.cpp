#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> visited(N);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        visited[a - 1] = true;
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}