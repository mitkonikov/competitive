#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i + 1 < N && S[i] == '0' && S[i+1] == '0') {
            ans++;
            i++;
            continue;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}