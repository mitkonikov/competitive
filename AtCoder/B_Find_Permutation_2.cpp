#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> visited(N + 1);
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        A[i] = X;
        if (X == -1) continue;
        if (visited[X]) {
            cout << "No" << endl;
            return 0;
        }
        visited[X] = true;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            for (int j = 1; j <= N; j++) {
                if (!visited[j]) {
                    cout << j << " ";
                    visited[j] = true;
                    break;
                }
            }
        } else {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    return 0;
}