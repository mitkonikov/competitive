#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<pair<int, int>> ranks(N);
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 'o') count++;
        }
        ranks[i] = { count, -i };
    }
    sort(ranks.rbegin(), ranks.rend());
    for (int i = 0; i < N; i++) {
        cout << -ranks[i].second + 1 << " ";
    }
    cout << endl;
    return 0;
}