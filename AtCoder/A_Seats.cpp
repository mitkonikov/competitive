#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == '#' && S[i+2] == '#' && S[i+1] == '.') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}