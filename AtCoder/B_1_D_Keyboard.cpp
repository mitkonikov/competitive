#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> pos(26);
    for (int i = 0; i < 26; i++) {
        pos[S[i] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 1; i < 26; i++) {
        ans += abs(pos[i] - pos[i-1]);
    }
    cout << ans << endl;
    return 0;
}