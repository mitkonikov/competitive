#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    vector<pair<int, char>> sorted;
    for (int i = 0; i < N; i++) sorted.push_back({ A[i], 'A' });
    for (int i = 0; i < M; i++) sorted.push_back({ B[i], 'B' });
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < sorted.size() - 1; i++) {
        if (sorted[i].second == 'A' && sorted[i+1].second == 'A') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}