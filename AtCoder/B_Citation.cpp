#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] >= i) {
                count++;
            }
        }
        if (count >= i) ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}