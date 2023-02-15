#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> count(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            count[(A[i]-1-i+j+N)%N]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, count[i]);
    cout << ans << endl;
    return 0;
}